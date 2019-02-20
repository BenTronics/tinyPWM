/* 
* tinyPWM.h
*
* Created: 19.02.2019 13:08:51
* Author: BenTronics
*/


#ifndef __TINYPWM_H__
#define __TINYPWM_H__

#include <avr/io.h>

class tinyPWM
{
//variables
private:
int pin;
int error_msg=1;

//functions
public:
	tinyPWM();
	tinyPWM(const int &pin);
	void setDuty_cycle(const int &dc);
	int getErrorMsg();
}; 

#endif //__TINYPWM_H__
