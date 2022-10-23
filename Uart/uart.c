//**************************************************************
//	 UART(Universal Asynchronous Receiver-Transmitter) Library
//
//  Author: Gaurav Singh
//**************************************************************
//function to initialize UART
#include "uart.h"
#include<string.h>

void uart_init (void)
{
	UBRRH = (x>>8);     //shift the register right by 8 bits
	UBRRL = x;          //set baud rate
	
	UCSRB|= (1<<TXEN)|(1<<RXEN);       //enable receiver and transmitter
	
//	UCSRC|= (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);  //8bit data, 2 stop bits
	UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);  //8bit data, 1 stop bit
	
}


// function to send data
void uart_Tx_char(unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));   //wait while register is free
	UDR = data;                      //load data in the register
}

//function to receive data
unsigned char uart_receive(void)
{
	while (! (UCSRA)& (1<<RXC));
	return UDR;
}

void uart_Tx_string(char*StringPtr)
{
	while (*StringPtr != 0x00){
		uart_Tx_char(*StringPtr);
		StringPtr++;
	}
}