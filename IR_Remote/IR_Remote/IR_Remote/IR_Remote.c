/*
 * IR_Remote.c
 *
 * Created: 5/27/2014 4:19:27 PM
 *  Author: Michael
 */ 
#define F_CPU 16000000UL  //16Mhz clock


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h> // provides delays
#include <avr/power.h> // used for setting clock prescaler
#include <stdbool.h>
#include <avr/interrupt.h>
#include <string.h>


#include "Atmega_Libs/AtmegaPins.h"
#include "Atmega_Libs/Serial_Atmel328p.h"


#include "Libs/IR_Sensor.h"


// Please note for both demos it is relient on the use of RS232 for debugging and GUI. 

int main(void)
{

	// Use For Printing out the Remotes Button Signals in an array , used for compare and detection
	//	IR_Get_Signal_Application_(); 
	
	// Used for comparing stored signals with Signal Recieved
		IR_Compare_Signal_Application(); 
}

