#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>//нужен для NULL
#include <stdlib.h>//нужен для malloc и free
#include <string.h>
#include "GParser.h"
#include "errors.h"
#include "messageQueue.h"

typedef enum{
	MESSAGE_STATUS,
	MESSAGE_COMMAND,
	MESSAGE_COMPLETE,
	MESSAGE_ACKNOWLEDGE,
	MESSAGE_BISY,
	MESSAGE_STOP
} messageType;

extern char UARTWriteEnable;
extern error lastError;
extern char bisy;
extern void setupMessageQueue();
extern char *getNewMessage();
extern char addMessageInQueue(char *messagePointer);
extern void startTimer2();


char inputBytesCounter;//счетчик входящих байт
char outputBytesCounter;//счетчик исходящих байт
char *inputDataArray;
char *diagnosticMessageArray;
int diagnosticMessageArraySize;
int inputDataArraySize;
char *outputDataArray;

void setupUART();
ISR (USART0_RX_vect);//обработчик прерываний
void decodePacket();
uint16_t CRC16(char *pcBlock, unsigned short len);
void sendStatusMessage();
void sendCommandComleteMessage();
void sendAcknowlegeMessage();
void sendStopMessage();
void sendBisyCommand();
void distributeStatusMessage();//собирает статусное сообщение в буфер outputDataArray
void distributeShortMessage(messageType message);//собирает сообщение завершения в  буфер outputDataArray
void clearInputArray();
void clearOutputArray();
void writeArray();
void UARTToWrite();
void UARTToRead();
void clearDiagnosticArray();