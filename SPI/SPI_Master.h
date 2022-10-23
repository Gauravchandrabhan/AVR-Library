//******************************************************
//	  SPI(Serial Peripheral Interface) Master Library
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


void SPI_Init_m()
{
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);  //making mosi,sck,ss output
	DDRB &= ~(1<<MISO);                  //making miso input
	
	PORTB |=(1<<SS);                     //ss high
	
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);//enable spi in master mode Fosc/16
	SPSR &= ~(1<<SPI2X);                 //disable speed doubler
	
}

void SPI_Write(char data)
{
	char flush_buffer;
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	flush_buffer = SPDR;
}

char SPI_Read()
{
	SPDR = 0xFF;
	while(!(SPSR & (1<<SPIF)));
	return(SPDR);
}