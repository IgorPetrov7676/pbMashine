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
	currentF = 400;
	swX = 0;
	swY = 0;
	swZ = 0;
	absoluteCoords = 0;//по умолчанию относительные координаты. так безопаснее
	bisy = 0;
	endPosX = 1550;
	endPosY = 1750;
	endPosZ = 170;
	userEndPosX = endPosX;
	userEndPosY = endPosY;
	userEndPosZ = endPosZ;
}
/////////////////////////////////////////////////////////////////////////////////////////
void executeCurrentCommand(){
	switch((int)currentComand.GCode){
		case(0):{//холостое перемещение
			blankMove();
			break;
		}
		case(1):{//линейная интерполяция
			lineMove();
			break;	
		}
		case(2):{//круговыя нитерполяция по часовой стрелке
			cwCicleInterpolation();
			break;
		}
		case(3):{//круговая интерполяция против часовой стрелки
			ccwCicleInterpolation();
			break;
		}
		case(28):{//перемещене домой (до концевых) с максимальной скоростью
			homeMove();
			break;
		}
		case(79):{//бесконеечный цикл рисования периметра рабочей зоны
			drawWorkZone();
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
			if(currentComand.reliability & (1 << 0)){//если параметр X достоверный{
				currentX = 0;	
			}
			if(currentComand.reliability & (1 << 1)){//если параметр Y достоверный{
				currentY = 0;
			}
			if(currentComand.reliability & (1 << 2)){//если параметр Z достоверный{
				currentZ = 0;
			}
			//todo код G92 без параметров должен обнулять все координаты
			commandExecuted();
			break;
		}
	}
}
///////////////////////////////////////////////////////////////
void autoCompliteCommand(struct driversCommand *command){
	//признаки достоверности только для этой функции.
	//больше нигде не должны проверяться
	
	
	if((command->reliability & (1 << 5)) || (command->reliability & (1 << 6))){//если хотябы одна из координат I или J достоверна
		if(! (command->reliability & (1 << 5))){//если недостоверна I 
			command->I = 0;
		}
		else if(! (command->reliability & (1 << 6))){//если недостоверна J
			command->J = 0;	
		}
		
		float tmp = 0;		
		if(absoluteCoords == 1){
			tmp = sqrt(pow((float)(currentX - command->I), 2) + pow((float)currentX - command->J, 2));//считаем радиус, как гипотенузу квадратного треугольника
		}
		else{
			tmp = sqrt(pow((float)(command->I), 2) + pow((float)command->J, 2));//считаем радиус, как гипотенузу квадратного треугольника
		}
		
		command->R = (int)roundf(tmp);
		}
	else if(command->reliability & (1 << 4)){//если достоверный радиус, то считаем I и J
		command->I = command->posX - command->R;
		command->J = command->posY - command->R;
	}
	
	if(! (command->reliability & (1 << 3))){//если параметр F не достоверный
		command->F = currentF;
	}
	else{//если достоверный
		calculateForce(command->F);
	}
	
	if(! (command->reliability & (1 << 0))){//если параметр X не достоверный
		command->posX = currentX;
	}
	else{//если достоверный
		if(absoluteCoords == 0){// и если координаты абсолютные
			command->posX = currentX + command->posX;
		}		
	}
	
	if(! (command->reliability & (1 << 1))){//если параметр Y не достоверный
		command->posY = currentY;
	}
	else{//если достоверный
		if(absoluteCoords == 0){//и если координаты абсолютные
			command->posY = currentY + command->posY;
		}
	}
	
	if(! (command->reliability & (1 << 2))){//если параметр Z не достоверный
		command->posZ = currentZ;
	}
	else{//если достоверный
		if(absoluteCoords == 0){//и если координаты абсолютные
			command->posZ = currentZ + command->posZ;
		}
	}
}
/////////////////////////////////////////////////////////////////////
void calculateForce(float F){
	stepTime = (1 / (F / 0.0125)) * 1000000;
	currentF = F;
}
//////////////////////////////////////////////////////////////////////
void blankMove(){
	char direction = 0;
	static char stop = 0;
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);
	
	if(currentX != currentComand.posX){
		if(currentX > currentComand.posX){
			direction = 0;
		}
		else if(currentX < currentComand.posX){
			direction = 1;
		}
		if(moveX(direction) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_X;
			stop |= (1 << 0);
		}
	}
	else{
		stop |= (1 << 0);	
	}

	if(currentY != currentComand.posY){
		if(currentY > currentComand.posY){
			direction = 0;
		}
		else if(currentY < currentComand.posY){
			direction = 1;
		}
		if(moveY(direction) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Y;
			stop |= (1 << 1);
		}
	}
	else{
		stop |= (1 << 1);
	}
	
	if(currentZ != currentComand.posZ){
		if(currentZ > currentComand.posZ){
			direction = 0;
		}
		else if(currentZ < currentComand.posZ){
			direction = 1;
		}
		if(moveZ(direction) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Z;
			stop |= (1 << 2);
		}
	}
	else{
		stop |= (1 << 2);
	}

	if(stop == 7){
		stop = 0;
		commandExecuted();
		return;
	}
	startTimer0();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void lineMove(){
	static char directionX = 0;
	static char directionY = 0;
	static int lastPosX = 2000;//начальные значения заведомо за пределами рабочей области для первого вызова функции
	static int lastPosY = 2000;	
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);

	if((lastPosX != currentX) || (lastPosY != currentY)){//если отработали 8 микрошагов - пересчитываем	
		if(onPosition() == 1){//если пришли в заданную позицию
			directionX = 0;
			directionY = 0;
			lastPosX = endPosX + 1000;
			lastPosY = endPosY + 1000;
			commandExecuted();//то команда выполнена
			return;
		}
		
		int offsetX = startPosX - currentX;
		int offsetY = startPosY - currentY;
		int vectorX = currentComand.posX - currentX;
		int vectorY = currentComand.posY - currentY;

		int F = (abs(offsetY) * abs(vectorX) - (abs(offsetX) * abs(vectorY)));//оценочная функция
		
		//если находимся на отрезке двигаемся и по X и по Y
		if(F == 0){
			if(vectorX > 0){//перемещение  по X
				directionX = 1;//плюс шаг
			}
			else if(vectorX < 0){
				directionX = 0;//минус шаг
			}
			else{
				directionX = 2;//не двигаемся. для случая перемещения только по X
			}
			
			if(vectorY > 0){//перемещение по Y
				directionY = 1;//плюс шаг
			}
			else if(vectorY < 0){
				directionY = 0;//минус шаг
			}
			else{
				directionY = 2;//не двигаемся. для случая перемещения только по Y
			}
		}
		
		//если выше отрезка двигаемся по X
		else if(F > 0){
			directionY = 2;
			if(vectorX > 0){
				directionX = 1;//плюс шаг
			}
			else if(vectorX < 0){
				directionX = 0;//минус шаг
			}
		}
		
		//если ниже отрезка двигаемся по Y
		else if(F < 0){
			directionX = 2;
			if(vectorY > 0){
				directionY = 1;
			}
			else if(vectorY < 0){
				directionY = 0;
			}
		}
		
		lastPosX = currentX;
		lastPosY = currentY;
	}
	
	if(directionX != 2){
		if(moveX(directionX) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_X;
		}
	}
	if(directionY != 2){
		if(moveY(directionY) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Y;
		}
	}

	startTimer0();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void cwCicleInterpolation(){
	static char directionX = 2;
	static char directionY = 2;
	static int lastPosX = 2000;//начальные значения заведомо за пределами рабочей области для первого вызова функции
	static int lastPosY = 2000;
	static char firstStep = 0;
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);
	
	if((lastPosX != currentX) || (lastPosY != currentY)){//если отработали 8 микрошагов - пересчитываем	
		if(firstStep == 1){//при первом шаге не проверяем иначе не получиться рисовать полные окружности
			if(onPosition() == 1){//если пришли в заданную позицию, то ничего не делаем
				directionX = 0;
				directionY = 0;
				lastPosX = endPosX + 1000;
				lastPosY = endPosY + 1000;
				firstStep = 0;
				commandExecuted();
				return;
			}
		}
		firstStep = 1;
		
		directionX = 2;
		directionY = 2;
		
		int offsetX = currentX - startPosX - currentComand.I;
		int offsetY = currentY - startPosY - currentComand.J;
		int F = ((offsetX * offsetX) + (offsetY * offsetY)) - (currentComand.R * currentComand.R);//оценочная функция (радиус всегда положительный контролируется на этапе парсинга)
		if(F >= 0){//если на окружности или за ней
			if((offsetX > 0) && (offsetY > 0)){//1 квадрант
				directionY = 0;//по Y в отрицательном направлении
			}
			else if((offsetX > 0) && (offsetY < 0)){//2 квадрант
				directionX = 0;//по X в отрицательном направлении
			}
			else if((offsetX < 0) && (offsetY < 0)){//3 квадрант
				directionY = 1;//по Y в положительном направлении
			}
			else if((offsetX < 0) && (offsetY > 0)){//4 квадрант
				directionX = 1;//по Х в положительном направлении
			}
			else{
				if(offsetY > 0){
					directionX = 1;
				}
				else if(offsetY < 0){
					directionX = 0;
				}
				else if(offsetX > 0){
					directionY = 0;
				}
				else if(offsetX < 0){
					directionY = 1;
				}
			}
		}
		else if(F < 0){//если внутри окружности
			if((offsetX > 0) && (offsetY > 0)){//1 квадрант
				directionX = 1;
			}
			else if((offsetX > 0) && (offsetY < 0)){//2 квадрант
				directionY = 0;		
			}
			else if((offsetX < 0) && (offsetY < 0)){//3 квадрант
				directionX = 0;
			}
			else if((offsetX < 0) && (offsetY > 0)){//4 квадрант
				directionY = 1;
			}
			else{
				if(offsetY > 0){
					directionX = 1;
				}
				else if(offsetY < 0){
					directionX = 0;
				}
				else if(offsetX > 0){
					directionY = 0;
				}
				else if(offsetY < 0){
					directionY = 1;
				}
			}
		}
		lastPosX = currentX;
		lastPosY = currentY;
	}
		
	if(directionX != 2){
		if(moveX(directionX) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_X;
		}
	}
	if(directionY != 2){
		if(moveY(directionY) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Y;
		}
	}
	startTimer0();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ccwCicleInterpolation(){
	static char directionX = 2;
	static char directionY = 2;
	static int lastPosX = 2000;//начальные значения заведомо за пределами рабочей области для первого вызова функции
	static int lastPosY = 2000;
	static char firstStep = 0;
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);
	
	if((lastPosX != currentX) || (lastPosY != currentY)){//если отработали 8 микрошагов - пересчитываем
		if(firstStep == 1){//при первом шаге не проверяем иначе не получиться рисовать полные окружности
			if(onPosition() == 1){//если пришли в заданную позицию, то ничего не делаем
				directionX = 0;
				directionY = 0;
				lastPosX = endPosX + 1000;
				lastPosY = endPosY + 1000;
				firstStep = 0;
				commandExecuted();
				return;
			}
		}
		firstStep = 1;
		
		
		directionX = 2;
		directionY = 2;
		
		int offsetX = currentX - startPosX - currentComand.I;
		int offsetY = currentY - startPosY - currentComand.J;
		int F = ((offsetX * offsetX) + (offsetY * offsetY)) - (currentComand.R * currentComand.R);//оценочная функция (радиус всегда положительный контролируется на этапе парсинга)
		if(F >= 0){//если на окружности или за ней
			if((offsetX > 0) && (offsetY > 0)){//1 квадрант
				directionX = 0;
			}
			else if((offsetX > 0) && (offsetY < 0)){//2 квадрант
				directionY = 1;
			}
			else if((offsetX < 0) && (offsetY < 0)){//3 квадрант
				directionX = 1;
			}
			else if((offsetX < 0) && (offsetY > 0)){//4 квадрант
				directionY = 0;
			}
			else{
				if(offsetY > 0){
					directionX = 0;
				}
				else if(offsetY < 0){
					directionX = 1;
				}
				else if(offsetX > 0){
					directionY = 1;
				}
				else if(offsetX < 0){
					directionY = 0;
				}
			}
		}
		else if(F < 0){//если внутри окружности
			if((offsetX > 0) && (offsetY > 0)){//1 квадрант
				directionY = 1;
			}
			else if((offsetX > 0) && (offsetY < 0)){//2 квадрант
				directionX = 1;
			}
			else if((offsetX < 0) && (offsetY < 0)){//3 квадрант
				directionY = 0;
			}
			else if((offsetX < 0) && (offsetY > 0)){//4 квадрант
				directionX = 0;
			}
			else{
				if(offsetY > 0){
					directionX = 1;
				}
				else if(offsetY < 0){
					directionX = 0;
				}
				else if(offsetX > 0){
					directionY = 0;
				}
				else if(offsetY < 0){
					directionY = 1;
				}
			}
		}
		lastPosX = currentX;
		lastPosY = currentY;
	}
	
	if(directionX != 2){
		if(moveX(directionX) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_X;
		}
	}
	if(directionY != 2){
		if(moveY(directionY) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Y;
		}
	}
	startTimer0();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void homeMove(){
	static char stop = 0;//бит 0 - стоп по Х; бит 1 - стоп по Y; бит 2 - стоп по Z
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);
	
	if(moveX(0) == 1){//проверка на концевик X
		stop |= (1 << 0);
	}
	if(moveY(0) == 1){//проверка на концевик Y
		stop |= (1 << 1);
	}
	if(moveZ(0) == 1){//проверка на концевик Z
		stop |= (1 << 2);
	}
	if(stop == 7){//если все три оси стоп
		currentX = 0;
		currentY = 0;
		currentZ = 0;
		//todo сделать точную подстройку нуля: сход сконцевиков и повторное движение до срабатывания на низкой скорости
		commandExecuted();
		stop = 0;
		return;
	}
	startTimer0();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void startExecuteCommand(struct driversCommand command){
	bisy = 1;
	autoCompliteCommand(&command);
	currentComand = command;
	startPosX = currentX;
	startPosY = currentY;
	executeCurrentCommand();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void commandExecuted(){
	bisy = 0;
	stopTimer0();
	sendCommandComleteMessage();
}
////////////////////////////////////////////////////////////////////////////////////////////////
char moveX(char direction){
	static char counter = 0;
	
	if(direction == 0){
		PORTC &= ~(1 << PORTC7);
	}
	else{
		PORTC |= (1 << PORTC7);
	}
	
	if(direction == 1){//движение в положительную сторону
		if(currentX < userEndPosX){//проверяем на программный концевик
			PORTC ^= (1 << PORTC6);
			counter ++;
			if(counter == 8){
				currentX ++;
				counter = 0;
			}
		}
		else{
			counter = 0;
			return 1;
		}
	}
	else{//движение в отрицательную сторону
		if(currentComand.GCode == 28){//если команда G28
			if(swX != 1){//проверяем на физический концевик
				PORTC ^= (1 << PORTC6);
				counter ++;
				if(counter == 8){
					currentX --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}	
		}
		else{//при любой другой команде
			if(currentX > 0){//проверяем на 0
				PORTC ^= (1 << PORTC6);
				counter ++;
				if(counter == 8){
					currentX --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}
		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////
char moveY(char direction){
	static char counter = 0;
	if(direction == 1){
		PORTC &= ~(1 << PORTC5);
	}
	else{
		PORTC |= (1 << PORTC5);
	}
	
	if(direction == 1){//если движение в положительную сторону
		if(currentY < userEndPosY){//проверяем на программный концевик
			PORTD ^= (1 << PORTD7);
			counter ++;
			if(counter == 8){
				currentY ++;
				counter = 0;
			}
		}
		else{
			counter = 0;
			return 1;
		}
	}
	else{//если движение в отрицательную сторону
		if(currentComand.GCode == 28){//если команда G28
			if(swY != 1){//проверяем на физический концевик
				PORTD ^= (1 << PORTD7);
				counter ++;
				if(counter == 8){
					currentY --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}
		}
		else{//при любой другой команде
			if(currentY > 0 ){//проверяем на 0
				PORTD ^= (1 << PORTD7);
				counter ++;
				if(counter == 8){
					currentY --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}
		}
	}
	return 0;
}
///////////////////////////////////////////////////////////////////
char moveZ(char direction){
	static char counter = 0;
	if(direction == 1){
		PORTB |= (1 << PORTB2);
	}
	else{
		PORTB &= ~(1 << PORTB2);
	}
	
	if(direction == 1){//если движение в положительную сторону
		if(currentZ < userEndPosZ){//проверяем на программный концевик
			PORTB ^= (1 << PORTB3);
			counter ++;
			if(counter == 8){
				currentZ ++;
				counter = 0;
			}
		}
		else{
			counter = 0;
			return 1;
		}
	}
	else{//если движение в отрицательную сторону
		if(currentComand.GCode == 28){//если команда G28
			if(swZ != 1){//проверяем на физический концевик
				PORTB ^= (1 << PORTB3);
				counter ++;
				if(counter == 8){
					currentZ --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}
		}
		else{//при любой другой команде
			if(currentZ > 0){//проверяем на 0
				PORTB ^= (1 << PORTB3);
				counter ++;
				if(counter == 8){
					currentZ --;
					counter = 0;
				}
			}
			else{
				counter = 0;
				return 1;
			}
		}
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////
void disableSteppers(){
	PORTD |= (1 << PORTD6);
	PORTA |= (1 << PORTA5);
	commandExecuted();
}
////////////////////////////////////////////////////////////////////////
void emergencyStop(){
	PORTD &= ~(1 << PORTD7);//тактовый импульс оси X
	PORTC &= ~(1 << PORTC6);//тактовый импульс оси Y
	PORTB &= ~(1 << PORTB3);//тактовый импульс оси Y
	PORTD |= (1 << PORTD6);//снимаем разрешения драйверов
	PORTA |= (1 << PORTA5);
	commandExecuted();
}
////////////////////////////////////////////////////////////////////////////
char onPosition(){
	if(currentX == currentComand.posX){
		if(currentY == currentComand.posY){
			if(currentZ == currentComand.posZ){
				return 1;
			}
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
void setUserEndPos(){
	userEndPosX = currentX;
	userEndPosY = currentY;
	commandExecuted();
}
/////////////////////////////////////////////////////////////////////////////////
void drawWorkZone(){
	static char edge = 0;
	char tmp = 0;
	
	switch(edge){
		case(0):{
			tmp = moveOnPerimetr();
			if(tmp == 1){
				currentComand.posX = userEndPosX;
				currentComand.posY = 0;
				edge ++;
			}
			else if(tmp == 2){
				commandExecuted();
				return;
			}
			break;
		}
		case(1):{
			tmp = moveOnPerimetr();
			if(tmp == 1){
				currentComand.posX = userEndPosX;
				currentComand.posY = userEndPosY;
				edge ++;
			}
			else if(tmp == 2){
				commandExecuted();
				return;
			}
			break;
		}
		case(2):{
			tmp = moveOnPerimetr();
			if(tmp == 1){
				currentComand.posX = 0;
				currentComand.posY = userEndPosY;
				edge ++;
			}
			else if(tmp == 2){
				commandExecuted();
				return;
			}
			break;
		}
		case(3):{
			tmp = moveOnPerimetr();
			if(tmp == 1){
				currentComand.posX = 0;
				currentComand.posY = 0;
				edge = 0;
			}
			else if(tmp == 2){
				commandExecuted();
				return;
			}
			break;
		}
	}
	startTimer0();
}
//////////////////////////////////////////////////////////////////////////////////
char moveOnPerimetr(){
	char direction = 0;
	static char stop = 0;
	
	//разрешение на драйверы
	PORTD &= ~(1 << PORTD6);
	PORTA &= ~(1 << PORTA5);
	
	if(currentX != currentComand.posX){
		if(currentX > currentComand.posX){
			direction = 0;
		}
		else if(currentX < currentComand.posX){
			direction = 1;
		}
		if(moveX(direction) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_X;
			return 2;//ошибка выхода из рабочей зоны
		}
	}
	else{
		stop |= (1 << 0);
	}

	if(currentY != currentComand.posY){
		if(currentY > currentComand.posY){
			direction = 0;
		}
		else if(currentY < currentComand.posY){
			direction = 1;
		}
		if(moveY(direction) == 1){
			lastError = ERROR_OUT_OF_WORKPLACE_Y;
			return 2;//ошибка выхода из рабочей зоны
		}
	}
	else{
		stop |= (1 << 1);
	}
	if(stop == 3){
		stop = 0;
		return 1;//перемещение выполнено
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////
void resetUserEndPos(){
	userEndPosX = endPosX;
	userEndPosY = endPosY;
	userEndPosZ = endPosZ;
	commandExecuted();
}