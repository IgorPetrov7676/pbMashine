/*
 * CFile1.c
 *
 * Created: 19.06.2023 15:46:58
 *  Author: Игорь
 */ 
#include "GParser.h"


void parseCommand(unsigned char *array, char len){
	switch(array[0]){
		case(71):{//если команда G
			parseGCode(array + 1, len - 1);//отстреливаем букву G
			break;
		}	
		case(77):{//если команда M
			parseMCode(array + 1, len - 1);//отстреливаем букву М 
			break;
		}
		default:{//если неизвестно что
			//TODO обработать ошибку	
		}
	}
}
//////////////////////////////////////////////////////////////////////
void parseGCode(const char *array, char len){
	struct driversCommand command;
	command.GCode = 0;
	command.posX = 0;
	command.posY = 0;
	command.posZ = 0;
	command.F = 0;
	command.R = 0;
	command.reliability = 0;


	//читаем номер команды
	int tmp=(int)(array[0]);
	if(isdigit(tmp)!=0){//первый символ в массиве должен быть числом. Символ G отстрелили в вызывающей функции
		command.GCode = atoi(array);
	}
	else{//иначе ошибка. todo потом добавить фиксацию ошибки
		return;
	}

	//читаем координату Х
	int symbol = 'X';
	char *pos = strchr(array, symbol);
	if(pos != 0){
		command.posX = (int)(atof(pos + 1) * 10);
		command.reliability |= (1 << 0);
	}

	//читаем координату Y
	symbol = 'Y';
	pos = strchr(array, symbol);
	if(pos != 0){
		command.posY = (int)(atof(pos + 1) * 10);
		command.reliability |= (1 << 1);
	}

	//читаем координату Z
	symbol = 'Z';
	pos = strchr(array,symbol);
	if(pos != NULL){
		command.posZ = (int)(atof(pos + 1) * 10);
		command.reliability |= (1 << 2);
	}

	//читаем параметр F
	symbol = 'F';
	pos = strchr(array,symbol);
	if(pos != 0){
		command.F = (int)(atof(pos + 1) * 10);
		command.reliability |= (1 << 3);
	}
	
	//читаем параметр R
	symbol = 'R';
	pos = strchr(array, symbol);
	if(pos != 0){
		command.R = (int)(atof(pos + 1) * 10);
		command.reliability |= (1 << 4);
	}
	
	//читаем параметр I
	symbol = 'I';
	pos = strchr(array, symbol);
	if(pos != 0){
		command.I = (float)(atof(pos + 1) * 10);
		command.reliability |= (1 << 5);
	}
	
	//читаем параметр J
	symbol = 'J';
	pos = strchr(array, symbol);
	if(pos != 0){
		command.J = (float)(atof(pos + 1) * 10);
		command.reliability |= (1 << 6);
	}
	startExecuteCommand(command);
}
////////////////////////////////////////////////////////////////////////
void parseMCode(unsigned char *array, char len){
	char command = 0;
	
	//читаем номер команды
	int tmp=(int)(array[0]);
	if(isdigit(tmp)!=0){//первый символ в массиве должен быть числом. Символ G отстрелили в вызывающей функции
		command = atoi(array);
	}
	else{//иначе ошибка. todo потом добавить фиксацию ошибки
		return;
	}
	
	switch(command){
		case(18):{//отключить двигатели
			disableSteppers();
			break;
		}
		case(112):{//экстренный останов
			emergencyStop();
			break;
		}
		case(50):{//установить текущие координаты как программные концевики
			setUserEndPos();
			break;
		}
		case(51):{//сбросить текущие программные концевики в значения по умолчанию
			resetUserEndPos();
			break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
