#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL


void LCD_VoidSendCommand (unsigned char Command)
{

	PORTB = 0b0000000; 				//set RS :low , RW: LOW
	PORTA = Command;

	PORTB = 0b00000100; 			//set enable pin to high (5v)
	_delay_ms(2);       			//wait for 2 ms
	PORTB = 0b00000000; 		 	//set enable pin to low (0v)
}

void LCD_VoidInit(void)
{
	DDRA = 0b11111111;  				//set data pins as output
	DDRB = 0b00000111; 					//set control pins (RS,RW,E) (PB0,PB1,PB2) as output

	_delay_ms(40);       				//wait for 40ms

	LCD_VoidSendCommand(0b00111000);  	//send the function

	LCD_VoidSendCommand(0b00001100);  	 // send display on/off

	LCD_VoidSendCommand(0b00000001);   //send display clear command


}

void LCD_VoidSendData (unsigned char Data)
{
	PORTB = 0b0000001; 				//set RS :high , RW: LOW
	PORTA = Data;

	PORTB = 0b0000101; 			//set enable pin to high (5v)
	_delay_ms(2);       			//wait for 2ms
	PORTB = 0b0000001; 		 	//set enable pin to low (0v)
}

int LCD_VoidGoToXY(unsigned char x_position , unsigned char y_position)
{
	unsigned char LCDAdress = 0 ;
	if(x_position == 0)
	{
		LCDAdress = y_position;
	}
	else if (x_position ==1)
	{
		LCDAdress = y_position + 0x40;

	}
	else
	{
		LCDAdress = y_position;

	}
	LCDAdress |= (1<<7);
	LCD_VoidSendCommand(LCDAdress);
}

void main (void)
{

	LCD_VoidInit();
	LCD_VoidGoToXY(0,1);
	LCD_VoidSendData('T');
	LCD_VoidSendData('A');
	LCD_VoidSendData('S');
	LCD_VoidSendData('N');
	LCD_VoidSendData('E');
	LCD_VoidSendData('E');
	LCD_VoidSendData('M');




	while(1)
	{
		LCD_VoidGoToXY(0,1);
		LCD_VoidSendData('T');
		LCD_VoidSendData('A');
		LCD_VoidSendData('S');
		LCD_VoidSendData('N');
	   	LCD_VoidSendData('E');
	   	LCD_VoidSendData('E');
	   	LCD_VoidSendData('M');
		_delay_ms(500);
		LCD_VoidSendCommand(0b00000001);   //send display clear command

		LCD_VoidGoToXY(1,2);
		LCD_VoidSendData('T');
		LCD_VoidSendData('A');
		LCD_VoidSendData('S');
		LCD_VoidSendData('N');
		LCD_VoidSendData('E');
		LCD_VoidSendData('E');
	  LCD_VoidSendData('M');
	_delay_ms(500);
	LCD_VoidSendCommand(0b00000001);   //send display clear command

	LCD_VoidGoToXY(0,4);
	LCD_VoidSendData('T');
	LCD_VoidSendData('A');
	LCD_VoidSendData('S');
	LCD_VoidSendData('N');
	LCD_VoidSendData('E');
	LCD_VoidSendData('E');
	LCD_VoidSendData('M');
	_delay_ms(500);
	LCD_VoidSendCommand(0b00000001);   //send display clear command

	LCD_VoidGoToXY(1,6);
			LCD_VoidSendData('T');
			LCD_VoidSendData('A');
			LCD_VoidSendData('S');
			LCD_VoidSendData('N');
		   	LCD_VoidSendData('E');
		   	LCD_VoidSendData('E');
		   	LCD_VoidSendData('M');

			_delay_ms(500);
			LCD_VoidSendCommand(0b00000001);   //send display clear command

			LCD_VoidGoToXY(0,10);
					LCD_VoidSendData('T');
					LCD_VoidSendData('A');
					LCD_VoidSendData('S');
					LCD_VoidSendData('N');
				   	LCD_VoidSendData('E');
				   	LCD_VoidSendData('E');
				   	LCD_VoidSendData('M');

					_delay_ms(500);
					LCD_VoidSendCommand(0b00000001);   //send display clear command

					LCD_VoidGoToXY(1,11);
							LCD_VoidSendData('T');
							LCD_VoidSendData('A');
							LCD_VoidSendData('S');
							LCD_VoidSendData('N');
						   	LCD_VoidSendData('E');
						   	LCD_VoidSendData('E');
						   	LCD_VoidSendData('M');

							_delay_ms(500);
							LCD_VoidSendCommand(0b00000001);   //send display clear command







	}
}
