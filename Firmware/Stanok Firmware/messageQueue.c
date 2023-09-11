/*
 * messagesQueue.c
 *
 * Created: 14.07.2023 11:14:08
 *  Author: Игорь
 */ 


#include "messageQueue.h"

void setupMessageQueue(){
	messageQueueSize = 10;
	messageQueueCount = 0;
	messageQueue = (int*)malloc(messageQueueSize);
	if(messageQueue == NULL){
		//TODO обработать ошибку
		return;	
	}
	for(int n = 0; n != messageQueueSize; n++){
		messageQueue[n] = 0;
	}	
}
////////////////////////////////////////////////////////////////////////////////////
char addMessageInQueue(char *messagePointer){
	if(messageQueueCount == messageQueueSize - 1){
		return 0;
	}
	
	messageQueue[messageQueueCount] = (int)messagePointer;
	messageQueueCount ++;
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////
char *getNewMessage(){
	if(messageQueueCount != 0){
		char *tmp = (char*)messageQueue[0];
		messageQueueCount --;
		for(int n = 0; n != messageQueueCount; n++){//сдвиг очереди влево
			messageQueue[n] = messageQueue[n + 1];
		}
		return tmp;
	}
	return NULL;
}
