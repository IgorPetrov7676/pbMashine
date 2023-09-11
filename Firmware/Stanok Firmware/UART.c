#include "UART.h"


void setupUART(){
	setupMessageQueue();
	inputDataArray = NULL;
	inputDataArraySize = 0;
	inputBytesCounter = 0;
	outputBytesCounter = 0;
	outputDataArray = NULL;
	diagnosticMessageArray = NULL;
	diagnosticMessageArraySize = 0;
	
	UCSR0B |= (1 << RXCIE0);//разрешаем прерывания по завершении приема
	UCSR0B |= (1 << RXEN0);// Разрешение приема
	UBRR0 = 103;//скорость 9600
}
//////////////////////////////////////////////////////////////////////////////////////////////
ISR (USART0_RX_vect){
	char status = 0;
	
	PORTA ^= (1 << PORTA4);
	
	status = UCSR0A;
	if (status & ((1 << FE0) | (1 << DOR0)  | (1 << UPE0))){//проверка на аппаратные ошибки
		reti();
	}
	
	if (inputDataArray == NULL){//если первый байт сообщения
		clearInputArray();//на всякий случай очищаем входной массив, чтобы избежать утечки памяти 
		inputDataArraySize = UDR0;
		if (inputDataArraySize != 0){//первый байт - размер пакета. Он не может быть нулевым
			//+1 под 0 - конец строки
			//массив на 1 байт больше, но пакет обрабатывается в таком виде, в каком пришел
			inputDataArray = (char*)malloc(inputDataArraySize + 1);
			if(inputDataArray == NULL){
				reti();//TODO обработать ошибку
			}
			inputBytesCounter = 0;
			inputDataArray[(int)inputBytesCounter] = inputDataArraySize;
			
			inputBytesCounter++;
		}
		else{
			//TODO обработать ошибку
		}
	}
	else{//если байт не первый
		inputDataArray[(int)inputBytesCounter] = UDR0;
		inputBytesCounter++;
		if(inputBytesCounter == inputDataArray[0]){//если приняли последний байт пакета
			inputDataArray[inputDataArraySize + 1] = 0;//добавляем признак конца строки
			inputBytesCounter = 0;			
		}
	}	
}
//////////////////////////////////////////////////////////////////////////////////
ISR (USART0_TX_vect){
	UARTWriteEnable = 1;
}
/////////////////////////////////////////////////////////////////
void decodePacket(){

	uint16_t crcCurrent = CRC16(inputDataArray, inputDataArraySize - 2);
	uint16_t crcInMessage = 0;
	memcpy(&crcInMessage, inputDataArray + (inputDataArraySize - 2), 2);//CRC в сообщении 
	if(crcCurrent == crcInMessage){
		//заменяем контрольную сумму симфолами пробела, чтобы не мешала при декодировании чисел
		inputDataArray[inputDataArraySize - 2] = 32;
		inputDataArray[inputDataArraySize - 1] = 32;
		
		switch (inputDataArray[1]){
			case(MESSAGE_STATUS):{
				clearInputArray();//порядок очистки важен, иначе обнуляется bytesCounter И в пакете получаются лишние байты
				sendStatusMessage();
				break;
			}
			case(MESSAGE_COMMAND):{				
				if(bisy != 1){//если контроллер не занят, то принимает команду
					//отстреливаем 1 байт - размер; 2 байт - тип пакета; 3
					sendAcknowlegeMessage();
					parseCommand(inputDataArray + 2, inputDataArray[0] - 2);
				}
				else{//если занят, то посылает
					sendBisyCommand();
				}
				clearInputArray();
				break;
			}
			case(MESSAGE_STOP):{//экстренный останов
				emergencyStop();
				clearInputArray();
				sendStopMessage();
				break;
			}
			default:{
				lastError = ERROR_UNCKNOW_MESSAGE_TYPE;
				diagnosticMessageArray = (char*)malloc(inputDataArraySize);
				memcpy(diagnosticMessageArray, inputDataArray, inputDataArraySize);
				diagnosticMessageArraySize = inputDataArraySize;
				clearInputArray();
				sendStatusMessage();
				break;
			}
		}
	}
	else{
		lastError = ERROR_ERROR_CRC;
		diagnosticMessageArray = (char*)malloc(inputDataArraySize + 2);
		memcpy(diagnosticMessageArray, inputDataArray, inputDataArraySize);
		memcpy(diagnosticMessageArray + inputDataArraySize, &crcCurrent, 2);
		diagnosticMessageArraySize = inputDataArraySize + 2;
		clearInputArray();
		sendStatusMessage();
	}
}
///////////////////////////////////////////////////////////////////////
void sendStatusMessage(){
	UARTToWrite();
	distributeStatusMessage();
	UARTWriteEnable = 1;
}
////////////////////////////////////////////////////////////////////
void distributeStatusMessage(){
	int errorSize = sizeof(error);
	char size = 1 + 6 + 1 + 2 + 3 + 6 + errorSize + 2 + diagnosticMessageArraySize;//размер: тип пакета(1) + 3 координаты(6) + размер(1) + подача(2) + концевики(3) + программные концевики + код ошибки(2) + CRC(2) 
	clearOutputArray();
	char *tmpArray = (char*)malloc((int)size);
	if(tmpArray == NULL){
		//TODO обработать ошибку
	}
	tmpArray[0] = size;
	tmpArray[1] = (char)MESSAGE_STATUS;
	
	//передаем координаты числом с фиксированной точкой. Преобразование во float осуществляем в клиенте
	memcpy(tmpArray + 2, &currentX, 2);	
	memcpy(tmpArray + 2 + 2, &currentY, 2);
	memcpy(tmpArray + 2 + 4, &currentZ, 2);
	memcpy(tmpArray + 2 + 6, &currentF, 2);
	memcpy(tmpArray + 2 + 8, &swX, 1);
	memcpy(tmpArray + 2 + 9, &swY, 1);
	memcpy(tmpArray + 2 + 10, &swZ, 1);
	memcpy(tmpArray + 2 + 11, &userEndPosX, 2);
	memcpy(tmpArray + 2 + 13, &userEndPosY, 2);
	memcpy(tmpArray + 2 + 15, &userEndPosZ, 2);
	memcpy(tmpArray + 2 + 17, &lastError, errorSize);
	lastError = ERROR_NO_ERROR;
	memcpy(tmpArray + 2 + 17 + errorSize, diagnosticMessageArray, diagnosticMessageArraySize);
	
	int16_t crc = CRC16(tmpArray,size-2);
	memcpy(tmpArray + size - 2, &crc, 2);
	if(addMessageInQueue(tmpArray) != 1){
		free(tmpArray);
		tmpArray = NULL;
	}
}
///////////////////////////////////////////////////////////////
uint16_t CRC16(char *pcBlock, unsigned short len){
	int16_t crc = 0xFFFF;
	unsigned char i;

	while (len--)
	{
		crc ^= *pcBlock++ << 8;
		for (i = 0; i < 8; i++)
		crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
	}
	return crc;
}
///////////////////////////////////////////////////////////////////
void clearInputArray(){
	inputDataArraySize = 0;
	inputBytesCounter = 0;
	if(inputDataArray != NULL){
		free(inputDataArray);
		inputDataArray = NULL;
	}
}
///////////////////////////////////////////////////////////////////////////
void clearOutputArray(){
	outputBytesCounter = 0;
	if(outputDataArray != NULL){
		free(outputDataArray);
		outputDataArray = NULL;
	}
}
/////////////////////////////////////////////////////////////////////////////
void clearDiagnosticArray(){
	if(diagnosticMessageArray != NULL){
		free(diagnosticMessageArray);
		diagnosticMessageArraySize = 0;
		diagnosticMessageArray = NULL;
	}
}
///////////////////////////////////////////////////////////////////////////
void writeArray(){
	//UARTWriteEnable = 0;
	if(outputDataArray == NULL){
		outputDataArray = getNewMessage();
		if(outputDataArray == NULL){
			UARTToRead();
		}	
	}
	if (outputBytesCounter != outputDataArray[0]){
		UDR0 = outputDataArray[(int)outputBytesCounter];
		outputBytesCounter ++;
	}
	else{//если пакет закончился
		clearOutputArray();
		outputDataArray = getNewMessage();
		if(outputDataArray == NULL){//если сообщений в очереди больше нет
			UARTToRead();	
		}
		else{
			UARTWriteEnable = 1;
			//startTimer2(30);//задержка в 1 мС между пакетами. иначе при коротких командах приложение принимает две за одну
		}
	}
}
////////////////////////////////////////////////////////////////////////////
void UARTToWrite(){
	UCSR0B &= ~(1 << RXEN0);//запрет приема
	UCSR0B |= (1 << TXEN0);//разрешение передачи
	UCSR0B |= (1 << TXCIE0);//разрешаем прерывание по передаче
	UCSR0B &= ~(1 << RXCIE0);//запрещаем прерывание по приему
}
////////////////////////////////////////////////////////////////////////////
void UARTToRead(){
	inputBytesCounter = 0;
	UCSR0B &= ~(1 << TXEN0);//запрещаем передачу
	UCSR0B |= (1 << RXEN0);//разрешаем прием
	UCSR0B |= (1 << RXCIE0);//разрешаем прерывание по приему
	UCSR0B &= ~(1 << TXCIE0);//запрещаем прерывание по передаче
}
//////////////////////////////////////////////////////////////////////////////
void sendCommandComleteMessage(){
	UARTToWrite();
	distributeShortMessage(MESSAGE_COMPLETE);
	UARTWriteEnable = 1;
}
//////////////////////////////////////////////////////////////////////////////
void distributeShortMessage(messageType message){
	char size = 4;//размер: размер(1) + тип пакета(1) + CRC(2)
	//clearOutputArray();
	char *tmpArray = (char*)malloc((int)size);
	if(tmpArray == NULL){
		//TODO обработать ошибку
	}
	tmpArray[0] = size;
	tmpArray[1] = (char)message;
	
	int16_t crc = CRC16(tmpArray,size-2);
	memcpy(tmpArray + size - 2, &crc, 2);
	if(addMessageInQueue(tmpArray) != 1){
		free(tmpArray);
		tmpArray = NULL;
	}
}
//////////////////////////////////////////////////////////////////////
void sendAcknowlegeMessage(){
	UARTToWrite();
	distributeShortMessage(MESSAGE_ACKNOWLEDGE);
	UARTWriteEnable = 1;
}
///////////////////////////////////////////////////////////////////////
void sendBisyCommand(){
	UARTToWrite();
	distributeShortMessage(MESSAGE_BISY);
	UARTWriteEnable = 1;
}
///////////////////////////////////////////////////////////////////////
void sendStopMessage(){
	UARTToWrite();
	distributeShortMessage(MESSAGE_STOP);
	UARTWriteEnable = 1;
}