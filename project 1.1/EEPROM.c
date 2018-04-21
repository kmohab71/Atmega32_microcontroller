/*
 * EEPROM.c
 *
 * Created: 9/23/2017 11:14:45 AM
 *  Author: khaled mohab
 */ 
#include "EEPROM.h"
void I2C_send_data_eeprom(uint8_t ADDRESS,uint8_t u8data,uint8_t location)
{
	I2C_Init();
	I2C_start();
	
	while (I2C_GetStatus() != 0x08);
	_delay_ms(40);
	I2C_Write((ADDRESS & 0xFE));
	while (I2C_GetStatus() != 0x18);
	I2C_Write(location);
	while (I2C_GetStatus() != 0x28);
	I2C_Write(u8data);
	while (I2C_GetStatus() != 0x28);
	I2C_end();
}



uint8_t I2C_receive_data_eeprom(uint8_t ADDRESS,uint8_t location)
{
	uint8_t data = 0;
	I2C_Init();
	I2C_start();
	while (I2C_GetStatus() != 0x08);
	_delay_ms(40);
	I2C_Write(ADDRESS );
	while (I2C_GetStatus() != 0x18);
	I2C_Write(location);
	while (I2C_GetStatus() != 0x28);
	I2C_start();
	while (I2C_GetStatus() != 0x10);
	I2C_Write(ADDRESS | 0X01);
	while (I2C_GetStatus() != 0x40);
	data= I2C_ReadNACK();
	while (I2C_GetStatus() != 0x58);
	I2C_end();
	return data;
}



void I2C_send_string_eeprom(uint8_t ADDRESS,uint8_t* u8data,uint8_t location)
{
	int i=0;
	I2C_Init();
	I2C_start();
	while (I2C_GetStatus() != 0x08);
	_delay_ms(40);
	I2C_Write((ADDRESS & 0xFE));
	while (I2C_GetStatus() != 0x18);
	I2C_Write(location);
	while (I2C_GetStatus() != 0x28);
	I2C_Write(u8data[i++]);
	while (I2C_GetStatus() != 0x28);
	for(i=0;i<7;i++)
	{
		_delay_ms(40);
		I2C_Write(u8data[i++]);
		while (I2C_GetStatus() != 0x30);
	}	
	I2C_end();
}



uint8_t* I2C_receive_string_eeprom(uint8_t ADDRESS,uint8_t location)
{
	static uint8_t data[4] ;
	int i;
	I2C_Init();
	I2C_start();
	while (I2C_GetStatus() != 0x08);
	_delay_ms(40);
	I2C_Write(ADDRESS );
	while (I2C_GetStatus() != 0x18);
	I2C_Write(location);
	while (I2C_GetStatus() != 0x28);
	I2C_start();
	while (I2C_GetStatus() != 0x10);
	I2C_Write(ADDRESS | 0X01);
	while (I2C_GetStatus() != 0x40);
	for(i=0;i<3;i++)
	{
		data[i]= I2C_ReadACK()+'1';
		while (I2C_GetStatus() != 0x50);
	}
	data[i]= I2C_ReadNACK()+'1';
	while (I2C_GetStatus() != 0x58);
	I2C_end();
	return data;
}