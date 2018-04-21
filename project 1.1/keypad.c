/*
 * keypad.c
 *
 * Created: 8/20/2017 4:03:10 PM
 *  Author: khaled mohab
 */
#include "keypad.h"
#include "lcd.h"
unsigned char get_from_keypad (void)
 {
KB_PORT   = 0x0F;		//Key-board port, higer nibble - input, lower nibble - output
KB_PORT_OUT=0X0F;		//pull-up enabled for higher nibble
unsigned char  keyCode=0x00, keyPressed=0x00;
unsigned int i=0;
//LCD_DisplayString("K");
while(1)
 {		
		KB_PORT   = 0x0F;
		keyCode=0x00;
		KB_PORT_OUT=0X0F;
		//KB_PORT_IN=~(1<<8);
		_delay_ms(10);
		KB_PORT_OUT = (1 << i++);
		_delay_ms(10); 		  		 //key debouncing delay
		keyCode =KB_PORT_OUT|KB_PORT_IN; 
		_delay_ms(20);   			   //key debouncing delay
		 i=i%4;
 
		 /*
		 0001-0001	0x11
		 0001-0010	0x12
		 0001-0100	0x14
		 0001-1000	0x18
		 
		 0010-0001	0x21
		 0010-0010	0x22
		 0010-0100	0x24
		 0010-1000	0x28
		 
		 0100-0001	0x41
		 0100-0010	0x42
		 0100-0100	0X44
		 0100-1000	0X48
		 
		 1000-0001	0X81
		 1000-0010	0X82
		 1000-0100	0X84
		 1000-1000	0X88
		 */
		 switch (keyCode)			   //generating key characetr to display on LCD
		 {
			 case (0x28): keyPressed = '0';
			 break;					   
			 case (0x14): keyPressed = '1';
			 break;
			 case (0x24): keyPressed = '2';
			 break;
			 case (0x44): keyPressed = '3';
			 break;
			 case (0x12): keyPressed = '4';
			 break;
			 case (0x22): keyPressed = '5';
			 break;
			 case (0x42): keyPressed = '6';
			 break;
			 case (0x11): keyPressed = '7';
			 break;
			 case (0x21): keyPressed = '8';
			 break;
			 case (0x41): keyPressed = '9';
			 break;
			 case (0x81): keyPressed = '/';
			 break;
			 case (0x82): keyPressed = '*';
			 break;
			 case (0x84): keyPressed = '-';
			 break;
			 case (0x88): keyPressed = '+';
			 break;
			 case (0x48): keyPressed = '=';
			 break;
			 case (0x18): keyPressed = 'F';
			 break;
			 default	: keyPressed = 'X';
		 }//end of switch
		 //x=&keyPressed;
		if ((unsigned char)(keyPressed)!=(0x58))
		break;
	 
		 }
 return keyPressed;
		}
 
 
 void wait_for_press(void)
 {
 //while (KB_PORT_IN==0xff){}

 }
 unsigned char * get_string_from_keypad(void)
 {
	 int i=0;
	 unsigned char *temp;
	 while(get_from_keypad()!='=')
	 {
		 temp[i]=get_from_keypad();
				//L(temp[i]);
		 i++;
	 }
	 temp='=';
	 return temp;
 }

