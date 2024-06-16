//================ INCLUDE ================/
#include "MKL46Z4.h"
#include <stdint.h>
//================ DEFINED ================/
#ifndef __GPIO_H_
#define __GPIO_H_


//------------- Enum -----------//
//Define value of fields
typedef enum
{
	IR_PORTCD = 31,
	IR_ADC0 = 15
}IRQn_t;

//------------- Struct -----------//

//================ SUPPORT ================/

//================ FOCUSED ================/

// Configuration control port
void NVIC_EnableIRQ(IRQn_t IRQn){}
void NVIC_DisableIRQ(IRQn_t IRQn){}
#endif
