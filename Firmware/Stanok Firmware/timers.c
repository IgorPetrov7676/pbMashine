/*
 * timers.c
 *
 * Created: 21.06.2023 7:51:24
 *  Author: Игорь
 */ 

#include "timers.h"


void setupTimers(){
	timer0Counter = 0;
	stepTime = 0;
	
	//таймер 0
	TCCR0A |= (1 << WGM01);//режим сброса при совпадении
	TIMSK0 |= (1 << OCIE0A);//прерывание по совпадении
	OCR0A = 20;//2 000 000 делим на 20 получаем период 0.000 01 с
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
	
	
	
	
	
	//PORTD ^= (1 << PORTD7);
}
/////////////////////////////////////////////////////////////
void startTimer0(){
	TCCR0B |= (1 << CS01);
}
/////////////////////////////////////////////////////////////
void stopTimer0(){
	TCCR0B &= ~(1 << CS01);
}