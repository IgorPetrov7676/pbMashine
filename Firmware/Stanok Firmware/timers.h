/*
 * timers.h
 *
 * Created: 21.06.2023 7:51:05
 *  Author: Игорь
 */ 

#ifndef TIMERS_H_
#define TIMERS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

extern char UARTWriteEnable;
extern void executeCurrentCommand();


int timer0Counter;
int timer2Counter;
int stepTime;

void setupTimers();
void startTimer0();
void stopTimer0();
void startTimer2(int time);
void stopTimer2();
ISR (TIMER0_COMPA_vect);//скорость перемещения
ISR (TIMER2_COMPA_vect);//задержки

#endif /* TIMERS_H_ */