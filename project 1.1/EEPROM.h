/*
 * EEPROM.h
 *
 * Created: 9/23/2017 11:15:01 AM
 *  Author: khaled mohab
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include "calculator.h"
#include "lcd.h"
#include "keypad.h"
#include "I2C.h"
void I2C_send_data_eeprom(uint8_t ADDRESS,uint8_t u8data,uint8_t location);
uint8_t I2C_receive_data_eeprom(uint8_t ADDRESS,uint8_t location);
void I2C_send_string_eeprom(uint8_t ADDRESS,uint8_t* u8data,uint8_t location);
uint8_t* I2C_receive_string_eeprom(uint8_t ADDRESS,uint8_t location);

#endif /* EEPROM_H_ */