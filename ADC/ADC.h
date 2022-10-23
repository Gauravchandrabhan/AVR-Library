//*************************************************
//		ADC(Analog to Digital Converter) Library
//
//  Author: Gaurav Singh
//*************************************************
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void ADC_Init();
int ADC_Read(char channel);
