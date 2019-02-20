/* 
* tinyPWM.cpp
*
* Created: 19.02.2019 13:08:50
* Author: BenTronics
*/


#include "tinyPWM.h"

//constructor
tinyPWM::tinyPWM(const int &pin)
{
	if(pin==0)
	{
		this->pin=0;
		DDRB |= (1<<0);
		TCCR0A |= (1<<COM0A1) | (1<<WGM00); 
		TCCR0B |= (1<<CS00);
		OCR0A=0;
	}
	else if(pin==1)
	{
		this->pin=1;
		DDRB |= (1<<1);
		TCCR0A |= (1<<COM0B1) | (1<<WGM00);
		TCCR0B |= (1<<CS00);
		OCR0B=0;
	}
	else if(pin==4)
	{
		this->pin=4;
		DDRB |= (1<<4);
		TCCR1 |= (1<<CS10);
		GTCCR |= (1<<PWM1B) | (1<<COM1B1);
		OCR1B=0;
	}
	else
		this->error_msg=-1;
}

// functions
void tinyPWM::setDuty_cycle(const int &dc)
{
	//error handling
	if(dc<0 || dc>255)
	{
		this->error_msg=-10;
		return;
	}
	
	if(this->pin==0)
		OCR0A=dc;
	if(this->pin==1)
		OCR0B=dc;
	if(this->pin==4)
		OCR1B=dc;
}

/*
Error Codes:
-> normal operation																		  1
-> duty duty cycle out of range (smaller than 0 or greater than 255)					-10
-> pin without pwm capability selectet													 -1
*/
int tinyPWM::getErrorMsg()
{
	return this->error_msg;
}
