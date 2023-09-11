/*
 * timers.c
 *
 * Created: 21.06.2023 7:51:24
 *  Author: Игорь
 */ 

#include "timers.h"


void setupTimers(){
	timer0Counter = 0;
	timer2Counter = 0;
	stepTime = 0;
	
	//таймер 0
	TCCR0A |= (1 << WGM01);//режим сброса при совпадении
	TIMSK0 |= (1 << OCIE0A);//прерывание по совпадении
	OCR0A = 20;//2 000 000 делим на 20 получаем период 0.000 01 с
	
	//таймер 2
	TCCR2A |= (1 << WGM21);//режим сброса при совпадении
	TIMSK2 |= (1 << OCIE2A);//прерывание по совпадении
	OCR2A = 200;//2 000 000 делим на 200 получаем период 0.000 1 с
}
///////////////////////////////////////////////////////////////////////////////////
ISR (TIMER0_COMPA_vect){
	timer0Counter ++;
	if(timer0Counter == stepTime){
		timer0Counter = 0;
		executeCurrentCommand();
	}
	
	//снимаем тактовые импульсы 
	PORTD &= ~(1 << PORTD7);//ось X
	PORTC &= ~(1 << PORTC6);//ось Y
	PORTB &= ~(1 << PORTB3);//ось Z
}
///////////////////////////////////////////////////////////////////////////////////
ISR (TIMER2_COMPA_vect){
	timer2Counter ++;
	if(timer2Counter == stepTime){
		timer2Counter = 0;
		stopTimer2();
		UARTWriteEnable = 1;
	}
}
/////////////////////////////////////////////////////////////
void startTimer0(){
	TCNT0 = 0;
	TCCR0B |= (1 << CS01);
}
/////////////////////////////////////////////////////////////
void stopTimer0(){
	TCCR0B &= ~(1 << CS01);
}
/////////////////////////////////////////////////////////////
void startTimer2(int time){
	timer2Counter = time;
	TCNT2 = 0;
	TCCR2B |= (1 << CS21);
}
/////////////////////////////////////////////////////////////
void stopTimer2(){
	TCCR2B &= ~(1 << CS21);
}