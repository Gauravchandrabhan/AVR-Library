//******************************************************
//	  SPI(Serial Peripheral Interface) Slave Library
//
//  Author: Gaurav Singh
//******************************************************
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define MOSI 5
#define SCK 7
#define SS 4
#define MISO 6

void SPI_Init_s()
{
	DDRB &= ~((1<<MOSI)|(1<<SCK)|(1<<SS));    //Make mosi,sck,ss input
	DDRB |= (1<<MISO);                        //Make miso output
	
	SPCR |=(1<<SPE);                          //enable slave mode
}

char SPI_Receive()
{
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);
}