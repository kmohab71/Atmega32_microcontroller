/*
 * lcd.c
 *
 * Created: 7/22/2017 4:14:02 PM
 *  Author: khaled mohab
 */ 
//
//  AGM1232G LCD.c
//  the gate
//
//  Created by Khaled Mohab on 7/7/17.
//  Copyright © 2017 Khaled Mohab. All rights reserved.
//

#include "lcd.h"
#define E						PC4
#define RW						PC3
#define RS						PC2
#define D0						PD0
#define D1						PD1
#define D2						PD2
#define D3						PD3
#define D4						PD4
#define D5						PD5
#define D6						PD6
#define D7						PD7
#define databus_direction		DDRD			//  LCD databus Direction Configuration
#define controlbus_direction	DDRC			//  LCD Control bus Direction Configuration
#define databus					PORTD           //	LCD databus connected to PORTB
#define control_bus				PORTC			//	LCD Control bus connected to PORTD


//#define F_CPU 16000000UL


void LCD_Init()
{
	_delay_ms(50);
	databus_direction = 0xFF;   // Configure both databus and controlbus as output
	controlbus_direction = 0xFF;
	LCD_send_a_command(0x38);   // LCD 2lines, 5*7 matrix
	LCD_send_a_command(0x0E);	// Display ON cursor ON
	LCD_send_a_command(0x01);	// Clear the LCD
	LCD_send_a_command(0x80);	// Move the Cursor to First line First Position
}
void LCD_send_a_character (uint8_t character)
{
	PORTD=character;
	PORTC|= (1<<RS);
	PORTC|= (1<<E);
	_delay_ms(50);
	PORTC&= ~(1<<E);
	PORTA =0;
}
void LCD_send_a_command (uint8_t command)
{
	PORTD=command;
	PORTC&= ~(1<<RS);
	PORTC|= (1<<E);
	_delay_ms(50);
	PORTC&= ~(1<<E);
	PORTD =0;
}
void LCD_send_a_string(uint8_t *ptr_stringPointer_u8)
{
	while((*ptr_stringPointer_u8)!='\0')
	{
		LCD_send_a_character(*ptr_stringPointer_u8++); // Loop through the string and display char by char
	}
}
void LCD_check_busy(void)
{

	PORTC&=~(1<<RS|1<<E);
	PORTC |=(1<<RW);
	uint8_t BF=(DDRD>>D7);
	while(BF)
	{

	}
}

void LCD_check_limits(void)
{

	PORTC&=~(1<<RS|1<<E);
	PORTC |=(1<<RW);
	uint8_t BF=(DDRD>>D7);
	while(BF)
	{

	}
}
void clear (void)
{
	LCD_send_a_command(0x01);
}

