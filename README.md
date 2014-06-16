IR_Universal_Remote
===================

IR Remote Receiver  - Interrupt Driven 

This Library Uses 2x Interrupts - One Timer Interrupt, Signal Interrupt (low->high) & (high->low)

/////////////////////////////////////////////////
/// PLEASE NOTE - IMPORTANT FAQ         ////////
////////////////////////////////////////////////
// Define pins and timing variables in the IR_Sensor.h file// 

IR INPUT = PIND
IR_Initial_Low_Pulse_Minimum	200  //  1.3ms
IR_Initial_Low_Pulse_Maximum	3000   // 19.5ms
IR_Error_Tollerance_			20 //  0.13ms tollerance for error


// This library does not use/follow any Universal Remote standards, 
the library is only responsible for determining the Input Signal to be from an IR remote 
and reading an input signals data. 

//This library is interrupt driven therefore, if any package other than the atmega128/328/328p is used 
some manual configuraiton for the INTTERRUPT is necessary

//Any Signal that has a start signal of less than 1.3ms will be FOREVER IGNORED 

// When a signal is detected it is ALWAYS STORED IN
_IR_Store_Input_Signal[16]  // ALWAYS !!!!!!!!!!!!!!!!!!

Data Usage 
				Program Memory Usage 	:	938 bytes  
				Data Memory Usage 		:	166 bytes  

char IR_Compare(int *_IR_Input, int * _Existing_Code);  // Idealy feed in the INPUT Array and a 2D array with signals 
void IR_Initalize(void);   // 0s all variables enables the timers and interrupts 
ISR(INT0_vect) // Interrupt driven // Responsible for analyzing the incoming signal and storing it 
