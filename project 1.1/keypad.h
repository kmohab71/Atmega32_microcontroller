/*
 * keypad.h
 *
 * Created: 8/20/2017 4:03:29 PM
 *  Author: khaled mohab
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include "lcd.h"
#define KB_PORT					DDRA
#define KB_PORT_OUT 			PORTA
#define KB_PORT_IN				PINA
unsigned char * get_string_from_keypad(void);
unsigned char get_from_keypad (void);
void wait_for_press(void);
#endif /* KEYPAD_H_ */