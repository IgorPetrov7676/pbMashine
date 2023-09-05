/*
 * Stanok Firmware.c
 *
 * Created: 07.06.2023 14:35:37
 * Author : Игорь
 */ 



#include "UART.h"
#include "timers.h"
#include "errors.h"


int ledCounter = 0;
char UARTWriteEnable = 0;
error lastError = ERROR_NO_ERROR;

void checkStopSwitches();
void setup();

void setup();



int main(void)
{
		
	setup();	
	
	//currentX = 111;
	//currentY = 222;
	//currentZ = 333;
	//currentF = 444;
	lastError = ERROR_NO_ERROR;
	
	/*inputDataArray = (char *)malloc(4);
	inputDataArray[0] = 4;
	inputDataArray[1] = 0;
	inputDataArray[2] = 203;
	inputDataArray[3] = 209;
	

	inputDataArraySize = 4;
	*/
	
	
	/*inputDataArraySize = 20;
	inputDataArray = (char*)malloc(inputDataArraySize);

	inputDataArray[0] = 20;
	inputDataArray[1] = 1;
	inputDataArray[2] = 71;
	inputDataArray[3] = 48;
	inputDataArray[4] = 50;
	inputDataArray[5] = 32;
	inputDataArray[6] = 88;
	inputDataArray[7] = 52;
	inputDataArray[8] = 48;
	inputDataArray[9] = 32;
	inputDataArray[10] = 73;
	inputDataArray[11] = 50;
	inputDataArray[12] = 48;
	inputDataArray[13] = 32;
	inputDataArray[14] = 70;
	inputDataArray[15] = 52;
	inputDataArray[16] = 48;
	inputDataArray[17] = 48;
	inputDataArray[18] = 92;
	inputDataArray[19] = 103;
	*/
	//inputDataArray[20] = 48;
	//inputDataArray[21] = 48;
	//inputDataArray[22] = 220;
	//inputDataArray[23] = 13;
	
	//inputDataArray[16] = 255;
	
	//parseCommand(inputDataArray + 2, 12):
	
	//startTimer0();
    while (1) 
    {
		checkStopSwitches();
		if(UARTWriteEnable == 1){
			UARTWriteEnable = 0;
			writeArray();
		}
			
		if(inputDataArraySize != 0){//если входной буфек UART не пустой
			if(inputBytesCounter == 0){//а счетчик байт обнулен
				decodePacket();//то декодируем прилетевший пакет
			}
		}
    }
}
//////////////////////////////////////////////////////
void setup(){
	
	//выходы
	DDRA |= (1 << DDA4);//светодиод
	DDRD |= (1 << DDD6);//ENABLE для драйверов X, Y, E
	DDRA |= (1 << DDA5);//ENABLE для драйвера Z
	DDRD |= (1 << DDD7);//тактовый импульс оси X
	DDRC |= (1 << DDC6);//тактовый импульс оси Y
	DDRB |= (1 << DDB3);//тактовый импульс оси Z
	DDRC |= (1 << DDC5);//направление оси X
	DDRC |= (1 << DDC7);//направление оси Y
	DDRB |= (1 << DDB2);//направление оси Z
	
	//отключаем драйверы двигателей
	PORTD |= (1 << PORTD6);
	PORTA |= (1 << PORTA5);
	
	//входы
	//подтягивающие резисторы
	PORTC |= (1 << PORTC2);//концевик оси X
	PORTC |= (1 << PORTC3);//концевик оси Y
	PORTC |= (1 << PORTC4);//концевик оси Z
	
	setupTimers();
	setupUART();
	setupDriver();
	
	lastError = ERROR_NO_ERROR;
	
	sei();
}
////////////////////////////////////////////////////////
void checkStopSwitches(){
	if(! (PINC & (1 << PORTC2))){
		swX = 1;
	}
	else{
		swX = 0;
	}
	
	if(! (PINC & (1 << PORTC3))){
		swY = 1;
	}
	else{
		swY = 0;
	}
	
	if(! (PINC & (1 << PORTC4))){
		swZ = 1;
	}
	else{
		swZ = 0;
	}
}