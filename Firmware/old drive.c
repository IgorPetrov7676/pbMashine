/*
 * driver.c
 *
 * Created: 19.06.2023 16:05:56
 *  Author: Игорь
 */ 

#include "driver.h"


void setupDriver(){
	currentX = 0;
	currentY = 0;
	currentZ = 0;
	currentF = 0;
	swX = 0;
	swY = 0;
	swZ = 0;
	absoluteCoords = 0;//по умолчанию относительные координаты. так безопаснее

	microStepsCounterX = 0;
	microStepsCounterY = 0;
	microStepsCounterZ = 0;
	
	stepsCounterX = 0;
	stepsCounterY = 0;
	stepsCounterZ = 0;
	
}
/////////////////////////////////////////////////////////////////////////////////////////
void executeCurrentComand(){
	autoCompliteCommand(&currentComand);//сначала заполняем недостающие параметры текущими и запоминаем команду
	
	switch((int)currentComand.GCode){
		case(0):{//холостое перемещение
			blankMove();
			break;
		}
		case(1):{//линейная интерполяция
			
			break;	
		}
		case(2):{//круговыя нитерполяция по часовой стрелке
		
			break;
		}
		case(3):{//круговая интерполяция против часовой стрелки
			
			break;
		}
		case(28):{//перемещене домой (до концевых) с максимальной скоростью
		
			break;
		}
		case(90):{//использовать абсолютные координаты
			absoluteCoords = 1;
			commandExecuted();
			break;
		}
		case(91):{//использовать относительные координаты
			absoluteCoords = 0;
			commandExecuted();
			break;
		}
		case(92):{//сбросить текущие координаты в 0
			currentX = 0;
			currentY = 0;
			currentZ = 0;
			break;
		}
	}  
}
///////////////////////////////////////////////////////////////
void autoCompliteCommand(struct driversCommand *command){
	if(command->F == -1){
		command->F = currentF;
	}
	else{
		calculateForce(command->F);
	}
	if(command->posX == -1){
		command->posX = currentX;
	}
	else if(absoluteCoords == 0){
		command->posX = currentX + command->posX;
	}
	
	if(command->posY == -1){
		command->posY = currentY;
	}
	else if(absoluteCoords == 0){
		command->posY = currentY + command->posY;
	}
	
	if(command->posZ == -1){
		command->posZ = currentZ;
	}
	else if(absoluteCoords == 0){
		command->posZ = currentZ + command->posZ;
	}
}
/////////////////////////////////////////////////////////////////////
void calculateForce(float F){
	stepTime = (1 / (F / 0.0125)) * 1000000;
	currentF = F;
}
//////////////////////////////////////////////////////////////////////
void moveEngines(){
	PORTA ^= (1 << PORTA4);
	char counter = 0;
	
	if(microStepsCounterX != 0){
		if(microStepsCounterX > 0){//меняем направление вращения двигателя оси X
			PORTC |= (1 << PORTC5);
			stepsCounterX ++;
		}
		else{
			PORTC &= ~(1 << PORTC5);
			stepsCounterX --;
		}
		microStepsCounterX --;
		PORTD |= (1 << PORTD7);
		counter ++;
	}
	
	if(microStepsCounterY != 0){
		if(microStepsCounterY > 0){//меняем направление вращения двигателя оси Y
			PORTC |= (1 << PORTC2);
			stepsCounterY ++;
		}
		else{
			PORTC &= ~(1 << PORTC2);
			stepsCounterY --;
		}
		microStepsCounterY --;
		PORTC |= (1 << 6);
		counter ++;
	}
	
	if(microStepsCounterZ != 0){
		if(microStepsCounterZ > 0){//меняем направление вращения двигателя оси Z
			PORTB |= (1 << PORTB2);
			stepsCounterZ ++;
		}
		else{
			PORTB &= ~(1 << PORTB2);
			stepsCounterZ --;
		}
		microStepsCounterZ --;
		PORTB |= (1 << PORTB3);
		counter ++;
	}
	
	if(counter == 0){//если все счетчики равны нулю, то перемещение отработано и нужно останавливать таймер
		stopTimer0();
		executeCurrentComand();
	}
	
	calculateCurrentPosition();
}
//////////////////////////////////////////////////////////////////////
void blankMove(){
	if(isInstrumentOnPosition() == 1){
		commandExecuted();
		return;
	}
	microStepsCounterX = (unsigned int)((currentComand.posX - currentX) * 8);// *8 т.к. 0.1 мм = 8 тактов
	microStepsCounterY = (unsigned int)((currentComand.posY - currentY) * 8);
	microStepsCounterZ = (unsigned int)((currentComand.posZ - currentZ) * 8);
	startTimer0();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void startExecuteCommand(struct driversCommand command){
	currentComand = command;
	executeCurrentComand();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commandExecuted(){
	writeCommandComleteMessage();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char isInstrumentOnPosition(){
	if(currentX == currentComand.posX){
		if(currentY == currentComand.posY){
			if(currentZ == currentComand.posZ){
				return 1;		
			}
		}
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void calculateCurrentPosition(){
	if(stepsCounterX == 8){
		currentX += 1;
		stepsCounterX = 0;
	}
	if(stepsCounterX == -8){
		currentX -= 1;
		stepsCounterX = 0;
	}
	
	if(stepsCounterY == 8){
		currentY += 1;
		stepsCounterY = 0;
	}
	if(stepsCounterY == -8){
		currentY -= 1;
		stepsCounterY = 0;
	}
	
	if(stepsCounterZ == 8){
		currentZ += 1;
		stepsCounterZ = 0;
	}
	if(stepsCounterZ == -8){
		currentZ -= 1;
		stepsCounterZ = 0;
	}
}