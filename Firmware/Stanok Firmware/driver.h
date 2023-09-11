/*
 * driver.h
 *
 * Created: 19.06.2023 16:05:31
 *  Author: Игорь
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <math.h>
#include "errors.h"

#ifndef DRIVER_H_
#define DRIVER_H_

struct driversCommand{
	char GCode;
	int posX;
	int posY;
	int posZ;
	int F;
	int R;
	int I;
	int J;
	char reliability;//флаги достоверности параметров 0-X;1-Y;2-Z;3-F;4-R;5-I;6-J	
};

struct driversCommand currentComand;

//текущие значания
//осей
int currentX;
int currentY;
int currentZ;
//подачи
int currentF;
//концевиков
char swX;
char swY;
char swZ;
//абсолютные/относительные координаты
char absoluteCoords;//0 - относительные; 1 - абсолютные

//программные концевики
//абсолютные
int endPosX;
int endPosY;
int endPosZ;
//пользовательские
int userEndPosX;
int userEndPosY;
int userEndPosZ;


//стартовые позиции для процедур интерполяции
int startPosX;
int startPosY;


char bisy;//признак занятости выполнением предыдущей команды

extern int stepTime;
extern error lastError;
extern void startTimer0();
extern void stopTimer0();
extern void sendCommandComleteMessage();

void setupDriver();
void executeCurrentCommand();
void autoCompliteCommand(struct driversCommand *comand);
void calculateForce(float F);//вычисление периода таймера по скорости подачи 
void blankMove();//холостое перемещение
void homeMove();//перемещение до концевиков
void startExecuteCommand(struct driversCommand command);//выполняется 1 раз перед каждой командой
void commandExecuted();//вызывается по окончании выполнения команды
char moveX(char direction);//direction: 0 в положительную сторону, 1 в отрицательную (возвращает 1 если наезд на концевой)
char moveY(char direction);//direction: 0 в положительную сторону, 1 в отрицательную (возвращает 1 если наезд на концевой)
char moveZ(char direction);//direction: 0 в положительную сторону, 1 в отрицательную (возвращает 1 если наезд на концевой)
void disableSteppers();//отключение двигателей (снимает сигналы ENABLE с драйверов)
void emergencyStop();//экстренный останов всего
void lineMove();//движение по линейной интерполяции
char onPosition();//проверка на нахождение в позиции, заданной текущей командой
void cwCicleInterpolation();//круговая интерполяция по часовой стрелке
void ccwCicleInterpolation();//круговая интерполяция против часовой стрелки
void setUserEndPos();//установка пользовательских програмных концевиков
void drawWorkZone();//бесконечная отрисовака периметра рабочей зоны
char moveOnPerimetr();//движение по периметру
void resetUserEndPos();//сбросить текущие программные концевики в значения по умолчанию



#endif /* DRIVER_H_ */