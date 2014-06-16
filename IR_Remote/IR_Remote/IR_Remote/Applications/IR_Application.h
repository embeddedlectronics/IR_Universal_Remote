/*
 * IR_Application.h
 *
 * Created: 6/16/2014 12:36:01 AM
 *  Author: Michael
 */ 


#ifndef IR_APPLICATION_H_INCLUDED
#define IR_APPLICATION_H_INCLUDED

#include "../Libs/IR_Sensor.h"

#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>

// General Applications/// Not necessary for function // Take a lot of data used on printf statements.
void IR_Get_Signal_Application_(void);
void IR_Compare_Signal_Application(void);
void IR_Application_Init(void);
void IR_Determine_Signal_Length(void);




#endif /* IR_APPLICATION_H_ */