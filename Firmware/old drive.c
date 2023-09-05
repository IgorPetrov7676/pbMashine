/*
 * driver.c
 *
 * Created: 19.06.2023 16:05:56
 *  Author: �����
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
	absoluteCoords = 0;//�� ��������� ������������� ����������. ��� ����������

	microStepsCounterX = 0;
	microStepsCounterY = 0;
	microStepsCounterZ = 0;
	
	stepsCounterX = 0;
	stepsCounterY = 0;
	stepsCounterZ = 0;
	
}
/////////////////////////////////////////////////////////////////////////////////////////
void executeCurrentComand(){
	autoCompliteCommand(&currentComand);//������� ��������� ����������� ��������� �������� � ���������� �������
	
	switch((int)currentComand.GCode){
		case(0):{//�������� �����������
			blankMove();
			break;
		}
		case(1):{//�������� ������������
			
			break;	
		}
		case(2):{//�������� ������������ �� ������� �������
		
			break;
		}
		case(3):{//�������� ������������ ������ ������� �������
			
			break;
		}
		case(28):{//���������� ����� (�� ��������) � ������������ ���������
		
			break;
		}
		case(90):{//������������ ���������� ����������
			absoluteCoords = 1;
			commandExecuted();
			break;
		}
		case(91):{//������������ ������������� ����������
			absoluteCoords = 0;
			commandExecuted();
			break;
		}
		case(92):{//�������� ������� ���������� � 0
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
		if(microStepsCounterX > 0){//������ ����������� �������� ��������� ��� X
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
		if(microStepsCounterY > 0){//������ ����������� �������� ��������� ��� Y
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
		if(microStepsCounterZ > 0){//������ ����������� �������� ��������� ��� Z
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
	
	if(counter == 0){//���� ��� �������� ����� ����, �� ����������� ���������� � ����� ������������� ������
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
	microStepsCounterX = (unsigned int)((currentComand.posX - currentX) * 8);// *8 �.�. 0.1 �� = 8 ������
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