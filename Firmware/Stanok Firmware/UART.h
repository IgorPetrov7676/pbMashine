#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>//����� ��� NULL
#include <stdlib.h>//����� ��� malloc � free
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


char inputBytesCounter;//������� �������� ����
char outputBytesCounter;//������� ��������� ����
char *inputDataArray;
char *diagnosticMessageArray;
int diagnosticMessageArraySize;
int inputDataArraySize;
char *outputDataArray;

void setupUART();
ISR (USART0_RX_vect);//���������� ����������
void decodePacket();
uint16_t CRC16(char *pcBlock, unsigned short len);
void sendStatusMessage();
void sendCommandComleteMessage();
void sendAcknowlegeMessage();
void sendStopMessage();
void sendBisyCommand();
void distributeStatusMessage();//�������� ��������� ��������� � ����� outputDataArray
void distributeShortMessage(messageType message);//�������� ��������� ���������� �  ����� outputDataArray
void clearInputArray();
void clearOutputArray();
void writeArray();
void UARTToWrite();
void UARTToRead();
void clearDiagnosticArray();