/*
 * IR_Application.c
 *
 * Created: 6/16/2014 12:35:44 AM
 *  Author: Michael
 */ 
#include "IR_Application.h"

void IR_Determine_Signal_Length(void){
	struct _IR_Signal *_IR_PointProperties= &Properties;
	printf("\n\r Clock pulses: %d ", _IR_PointProperties->_IR_Clock_Pulses);
}


/// Runs The compare signal application // THe compare signal application uses the IR_REMOTE_BUTTONS defined in 
/// IR_SENSOR.H
void IR_Compare_Signal_Application(void){
	struct _IR_Signal *_IR_PointProperties= &Properties;
	char _IR_Remote_Button_Array_Length =0;
	char _Incorrect_Count=0; 
	printf("\n\r Remote Control Button Detection Compare \n\r ------------------------------------\n\r ");
	
	IR_Application_Init();
	
	printf("\n\r\n\r Now the program will read the current stored button presses and compare it with the input signal, please consult the tutorial on its use: \n\r");
	
	_IR_Remote_Button_Array_Length = sizeof(_IR_Remote_Buttons)/sizeof(*_IR_Remote_Buttons) ;


	while(1){
		
		if (_IR_PointProperties->_IR_Read_State){
			_Incorrect_Count =0;
			
			for (char x= 0; x < _IR_Remote_Button_Array_Length; x++ ){
				/// Compares the input signal stored with the Button array
				if (IR_Compare( _IR_PointProperties->_IR_Store_Input_Signal, _IR_Remote_Buttons[x])) 
				{
					printf(" \n\r Button %d Pressed! ", x);  // Upon the return of 1 the Button pressed signal matches the Stored Button Signal
					_IR_PointProperties->_IR_Read_State =0; // Global Flag used
				
				}
				
				else
					_Incorrect_Count++; 
					
				if(_Incorrect_Count == (_IR_Remote_Button_Array_Length)){
					printf(" \n\r Not A Recognized Button\n\r ");  
					for(char _count=0; _count < (_IR_PointProperties->_IR_Clock_Pulses/16)+1; _count++) // prints out recoreded signal
						printf(" 0x%x, \n\r", _IR_PointProperties->_IR_Store_Input_Signal[_count]);
					
				
					_IR_PointProperties->_IR_Read_State =0; // Global Flag used
				}
			}
		}
		
		
	}
	
}


// simple program used for acquiring the values from the remote
void IR_Get_Signal_Application_(void){
	struct _IR_Signal *_IR_PointProperties= &Properties;
	char _IR_Button_Count =0;
	uint16_t _IR_Bytes_Used =0;
	printf("\n\r Remote Control Button Array Detection \n\r ------------------------------------\n\r ");
	
	IR_Application_Init();
	
	printf("\n\r\n\r Now the program will print out the signal from the remote in a 2D array format \n\r");
	
	while(1){
		
		if (_IR_PointProperties->_IR_Read_State){
			_IR_Button_Count++;
			printf("\n\r IR SIGNAL DETECTED! \n\r -----------------------------\n\r ");
			printf("\n\r int _IR_Remote_Button_%d [%d] ={ \n\r", _IR_Button_Count, (_IR_PointProperties->_IR_Clock_Pulses/16)+1);
				
				
				for(char _count=0; _count < (_IR_PointProperties->_IR_Clock_Pulses/16)+1; _count++)
				printf(" 0x%x, \n\r", _IR_PointProperties->_IR_Store_Input_Signal[_count]);
				

				_IR_PointProperties->_IR_Read_State = 0;
				_IR_Bytes_Used += ((_IR_PointProperties->_IR_Clock_Pulses/16)+1)*2 ;
			printf ("};  // Remote Button %d  \n\r\n\r", _IR_Button_Count);
			printf("  Bytes Per Signal: %u bytes \n\r  Total Bytes Used For All Signals: %u bytes\n\r ", ((_IR_PointProperties->_IR_Clock_Pulses/16)+1)*2 , _IR_Bytes_Used);
		}
		
		
	}
	return;
}

void IR_Application_Init(void){
	struct _IR_Signal *_IR_PointProperties= &Properties;
	/// Initialize Serial For Debugging
	USART_init();
	fdevopen(USART_send, NULL); // Bind USART with printf
	
	// 	Sets the Pins for INT0 / enable interrupts / initalizes variablew;
	IR_Initalize();
	printf("1. Hit any button on the remote :");
	
	// Read state is flagged when a proper IR signal is detected 
	while (!_IR_PointProperties->_IR_Read_State);
	
	IR_Determine_Signal_Length();
	

	return;
}

