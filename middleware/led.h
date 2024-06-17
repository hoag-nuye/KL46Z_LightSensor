//================ INCLUDE ================/
#include "MKL46Z4.h"
#include <stdint.h>
//================ DEFINED ================/
#ifndef __LED_H_
#define __LED_H_


//------------- Enum -----------//
//Define value of fields

typedef enum{
	LED1,
	LED2
}LED_Name_t;
//------------- Struct -----------//

//================ SUPPORT ================/

//================ FOCUSED ================/

// Configuration control port
void LED_Init(LED_Name_t name);
void Toggle_LED(LED_Name_t name);
void TurnOn_LED(LED_Name_t name);
void TurnOff_LED(LED_Name_t name);
#endif
