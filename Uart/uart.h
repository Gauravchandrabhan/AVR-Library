//**************************************************************
//	 UART(Universal Asynchronous Receiver-Transmitter) Library
//
//  Author: Gaurav Singh
//**************************************************************
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//define macros
#define BAUD 9600
#define BAUDRATE (((F_CPU)/(BAUD*16UL))-1)  //define baud formula

void uart_init (void);
void uart_Tx_char (unsigned char data);
void uart_Tx_string(char* StringPtr);
unsigned char uart_receive(void);
void uart_Tx_number(uint32_t)
void uart_itoa(uint32_t n, char s[]);
static void reverse(char s[]);