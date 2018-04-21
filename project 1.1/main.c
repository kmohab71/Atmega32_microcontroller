/*
 * project 1.1.c
 *
 * Created: 7/23/2017 2:28:33 PM
 * Author : khaled mohab
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include "calculator.h"
#include "lcd.h"
#include "keypad.h"
#include "I2C.h"
#include "EEPROM.h"
#define F_CPU 16000000UL
#define EEPROM_ADDRESS 0xA0
 
void initIO(void){}
	
int main(void) 
{
	uint8_t MOTOR_ADDRESS = 0b10011110;
	//unsigned char a[];
	initIO();
	LCD_Init();
	_delay_ms(10);
	LCD_send_a_string(get_string_from_keypad);
	//I2C_send_string_eeprom(EEPROM_ADDRESS,n,0X01);
	//LCD_send_a_string((I2C_receive_string_eeprom(EEPROM_ADDRESS,0x07)));
	//LCD_send_a_character(0xFF);
	//LCD_send_a_string(a);
	//MOTOR_ROTATE_LEFT();
	//MOTOR_ROTATE_LEFT();
	//MOTOR_ROTATE_LEFT();
	//LCD_send_a_character('a');
	//MOTOR_ROTATE_RIGHT();
	LCD_send_a_character(get_from_keypad());
	
	while (1)
	{
		//I2C_Write_DAC(MOTOR_ADDRESS,0x0F);
		//LCD_send_a_string();
	}
		 
	return 0; // never reached
}