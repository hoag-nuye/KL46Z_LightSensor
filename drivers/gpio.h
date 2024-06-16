//================ INCLUDE ================/
#include "MKL46Z4.h"
#include <stdint.h>
//================ DEFINED ================/
#ifndef __GPIO_H_
#define __GPIO_H_


//------------- Enum -----------//
//Define value of fields

typedef enum{
	 Direct_Input = 0b0,
	 Direct_Output = 0b1,
}Direction_t;
//------------- Struct -----------//
typedef struct{
	GPIO_Type* gpio;
	uint8_t pin;
	Direction_t pdd;
}GPIO_PinConfig_Type;

//================ SUPPORT ================/

//================ FOCUSED ================/

// Configuration control port
void GPIO_PinConfig(GPIO_PinConfig_Type *GPIO_Config){};
void GPIO_SetPin(GPIO_Type* gpio, uint8_t pin){};
void GPIO_ClearPin(GPIO_Type* gpio, uint8_t pin){};
void GPIO_ReadPin(GPIO_Type* gpio, uint8_t pin){};
void GPIO_TogglePin(GPIO_Type* gpio, uint8_t pin){};
#endif
