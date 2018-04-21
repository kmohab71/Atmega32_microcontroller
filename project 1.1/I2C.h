/*
 * I2C.h
 *
 * Created: 9/6/2017 5:47:51 PM
 *  Author: khaled mohab
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
#include "lcd.h"
void I2C_Init(void);
void I2C_start(void);
void I2C_REPEAT_start(void);
void I2C_Write(uint8_t u8data);
uint8_t I2C_GetStatus(void);
uint8_t I2C_ReadACK(void);
uint8_t I2C_ReadNACK(void);
void I2C_MASTER_TM(uint8_t ADDRESS);
void I2C_MASTER_RM(uint8_t ADDRESS);
void I2C_end (void);




#endif /* I2C_H_ */