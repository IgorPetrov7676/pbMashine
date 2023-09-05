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

extern void executeCurrentCommand();


int timer0Counter;
int stepTime;

void setupTimers();
void startTimer0();
void stopTimer0();
ISR (TIMER0_COMPA_vect);


#endif /* TIMERS_H_ */