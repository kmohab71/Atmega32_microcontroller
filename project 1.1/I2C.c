/*
 * I2C.c
 *
 * Created: 9/6/2017 5:47:19 PM
 *  Author: khaled mohab
 */ 
#include "I2C.h"
void I2C_Init(void)
{
	TWSR = 0x00;
	TWBR = 0x0C;
	TWCR = (1<<TWEN);
}

void I2C_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

}

void I2C_REPEAT_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));

}
void I2C_MASTER_TM(uint8_t SLA)
{
	I2C_Write(SLA & 0XFE);
	while (I2C_GetStatus() != 0x28);

}
void I2C_MASTER_RM(uint8_t SLA)
{
	I2C_Write(SLA | 0X01);
	while (I2C_GetStatus() != 0x28);

}
uint8_t I2C_GetStatus(void)
{
	uint8_t status;
	status = TWSR & 0xF8;
	return status;
}



uint8_t I2C_ReadACK(void)

{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;

}

uint8_t I2C_ReadNACK(void)

{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}



void I2C_Write(uint8_t u8data)

{	
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);

}


void I2C_end (void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

