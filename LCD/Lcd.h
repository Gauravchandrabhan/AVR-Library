//**********************************************************
//          LCD(Liquid Crystal Display) Library
//           16X2 LCD for basic display of text
//**********************************************************
#define F_CPU 1000000UL
#include <avr/io.h>
#include<util/delay.h>

#define cmd_port PORTD   //rs,rw,en
#define data_port PORTB  //8 pins of lcd
#define decimal_point 2

#define rs 0  //PD0
#define rw 6  //PD6
#define en 1  //PD1

void lcd_init();
void lcd_clear();
void lcd_cmd(unsigned char cmd);
void lcd_gotoxy(unsigned char x, unsigned char y); //x=col(1-16) and y=row(1-2)
void lcd_Display_char(unsigned char data);
void lcd_Display_String(char *ptr_stringPointer_u8);
void lcd_Display_Integer(int number);
void lcd_Display_Float(float number);
void LCD_itoa(int n, char s[]);
void LCD_ftoa(float n,char *res, int afterpoint);

static void reverse(char s[]);
static void reverseF(char *str, int len);
static int intToStr(int x,char str[], int d);