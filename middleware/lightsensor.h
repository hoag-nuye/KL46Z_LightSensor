//================ INCLUDE ================/
#include "MKL46Z4.h"
#include <stdint.h>
//================ DEFINED ================/
#ifndef __LIGHTSENSOR_H_
#define __LIGHTSENSOR_H_


//------------- Enum -----------//
//Define value of fields
typedef enum{
	Light_sns,
}LIGHTSENSOR_Name_t;

//------------- Struct -----------//

//================ SUPPORT ================/

//================ FOCUSED ================/
void LIGHTSENSOR_Init(LIGHTSENSOR_Name_t name);
void LIGHTSENSOR_TurnOn();
void LIGHTSENSOR_TurnOff();
void LIGHTSENSOR_Read_LUX();

#endif
