//================ INCLUDE ================/
#include "MKL46Z4.h"
#include <stdint.h>
//================ DEFINED ================/
#ifndef __PORT_H_
#define __PORT_H_


//------------- Enum -----------//
//Define value of fields
typedef enum{
	Pull_DISABLE = 0b00,
	Pull_UP = 0b11,
	Pull_DOWN = 0b10
}PullControl_t;

typedef enum{
	 Analog = 0b000,
	 GPIO   = 001,
	 Alt2   = 010,
	 Alt3   = 011,
	 Alt4   = 100,
	 Alt5   = 101,
	 Alt6   = 110,
	 Al7    = 111
}MuxControl_t;


typedef enum{
	 Falling_Edge = 0b1010,
	 Risin_Edge = 0b1001,
}Port_Interrupt_t;
//------------- Struct -----------//
typedef struct{
	PORT_Type* port;
	uint8_t pin;
	PullControl_t pull;
	MuxControl_t mux;
	Port_Interrupt_t irqc;
}PORT_Config_Type;

//================ SUPPORT ================/

//================ FOCUSED ================/

// Configuration control port
void PORT_PinConfig(PORT_Config_Type *PORT_Config){};
#endif
