/*
 * lcd.h
 *
 * Created: 7/22/2017 4:14:36 PM
 *  Author: khaled mohab
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//_Bool A0,RW,DB[8],RES;//DB7,DB6,DB5,DB4,DB3,DB2,DB1,DB0;
//_Bool E1=0x1,E2=0x1;
//uint8_t DB;
void LCD_Init();
void LCD_send_a_character (uint8_t character);
void LCD_send_a_command (uint8_t command);
void LCD_send_a_string (uint8_t *ptr_stringPointer_u8);
void LCD_check_busy(void);
void LCD_check_limits(void);
void LCD_clear (void);

#endif /* LCD_H_ */