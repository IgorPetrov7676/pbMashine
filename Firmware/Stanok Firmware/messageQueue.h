/*
 * messagesQueue.h
 *
 * Created: 14.07.2023 11:13:47
 *  Author: Игорь
 */ 


#ifndef MESSAGESQUEUE_H_
#define MESSAGESQUEUE_H_

#include <stddef.h>//нужен для NULL
#include <stdlib.h>//нужен для malloc

//FILO буфер очереди сообщений

char messageQueueSize;
int messageQueueCount;//счетчик сообщений в очереди
int *messageQueue;//очередь сообщений. Массив указателей на сообщения

void setupMessageQueue();
char addMessageInQueue(char *messagePointer);//добавляет новое сообщение в очередь/ возвращает 0 если очередь переполнена
char *getNewMessage();



#endif /* MESSAGESQUEUE_H_ */