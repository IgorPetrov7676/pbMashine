/*
 * GParser.h
 *
 * Created: 19.06.2023 15:46:50
 *  Author: Игорь
 */ 


#ifndef GPARSER_H_
#define GPARSER_H_


#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "driver.h"

//extern void executeComand(struct driversComand comand);
//extern struct Buffer rxBuffer;

void parseGCode(const char *array, char len);
void parseMCode(unsigned char *array, char len);
void parseCommand(unsigned char *array, char len);
unsigned char findSymbol(unsigned char *array, unsigned char len, char symbol,unsigned char start);



#endif /* GPARSER_H_ */