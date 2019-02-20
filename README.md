# tinyPWM
let you access all 3 hardware PWM channels of the Attiny 25/ 45/ 85

If you are using the standart Attiny Arduino Core you are only able to let Pin 0 and 1 produce a PWM your Projekts. 
In fact the Attiny 25/ 45/ 85 are able to produce 3 PWM-signals by Hardware and my little Library makes you able to use all of them.

Read the following lines carefully, because the contain using advice and a bit of example code.
Only pins B0, B1, and B4 (se schematic dowm below) are able to be used as PWM pins. If you are trying to use one of the other pins
insteadyou will get an error number which you can read to chek wich one of the chanels cause the problem 
(i'm going to show you how you can read the error number in the code below). A value for the dutycle wich is'nt in the normal range (0 
to 255) will also leading to an Error.


the pinout looks like this:

              ________   ________
             |         V         |
           __|  1(B5)   (Vcc) 8  |__                  The pins who are capable of producing PWM are labeld with Bx~ like one the Arduino
             |                   |                    Board.
           __|  2(B3)    (B2) 7  |__
             |                   |
           __|  3(B4~)  (B1~) 6  |__    
             |                   |
           __|  4(GND)  (B0~) 5  |__    
             |___________________|


a simple code could look like this:

#include "tinyPWM.h"

//greating 3 objects (in this case we are using the PWM for a RGB LED)
tinyPWM red(0);
tinyPWM green(1);
tinyPWM blue(4);

void setup() {
  pinMode(2,OUTPUT); //we are using a LED on this pin to visualize errors
}

void loop() {
  
  //first check for errors 
  if(red.getErrorMsg()<0 || green.getErrorMsg()<0 || blue.getErrorMsg()<0) {
    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);    //short bliky to indicate that an error occurred 
    delay(200);
  }
  
  //fading up each color
  for(int brightness=0; brightness<256; brightness++) {
    red.setDuty_cycle(brightness);
    delay(10);
    //error handling
    if(red.getErrorMsg()<0) {
    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);    //short bliky to indicate that an error occurred 
    delay(200);
    }
  }
  
  for(int brightness=0; brightness<256; brightness++) {
    green.setDuty_cycle(brightness);
    delay(10);
    //error handling
    if(green.getErrorMsg()<0) {
    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);    //short bliky to indicate that an error occurred 
    delay(200);
    }
  }
  
  for(int brightness=0; brightness<256; brightness++) {
    blue.setDuty_cycle(brightness);
    delay(10);
    //error handling
    if(blue.getErrorMsg()<0) {
    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);    //short bliky to indicate that an error occurred 
    delay(200);
    }
  }
  
}

/*
the code shouldn't lead to any kind of error 
you can easily let an error occur if you select a wrong pin or you are to set teh duty cycle below 0 or above 255
*/
