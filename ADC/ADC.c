//*************************************************
//		ADC(Analog to Digital Converter) Library
//
//  Author: Gaurav Singh
//*************************************************
#include "ADC.h"

void ADC_Init()
{
	DDRA = 0x0;
	ADCSRA = 0x87;
	ADMUX = 0x40;
}

int ADC_Read(char channel)
{
	int Ain,AinLow;
	
	ADMUX = ADMUX|(channel & 0x0f);
	
	ADCSRA |= (1<<ADSC);
	while((ADCSRA& (1<<ADIF)) ==0 );
	
	_delay_us(10);
	AinLow = (int)ADCL;
	Ain = (int)ADCH*256;
	
	Ain = Ain + AinLow;
	return(Ain);
}