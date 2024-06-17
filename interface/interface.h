//================ INCLUDE ================/
#include <stdint.h>
#include "led.h"
#include "button.h"
#include "systick.h"
//================ DEFINED ================/
#ifndef __INTERFACE_H_
#define __INTERFACE_H_


//------------- Enum -----------//
//Define value of fields

typedef enum{
	DO_NOTHING,
	TOGGLE_LED,
	FLASHING_LED,
}State_Machine_t;

typedef enum{
	_BUTTON_LED_Flashing,
}State_Program_t;
//------------- Struct -----------//

//================ SUPPORT ================/

//================ FOCUSED ================/
void BUTTON_LED_Toggle();
#endif
