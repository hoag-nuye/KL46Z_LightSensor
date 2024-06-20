//================ INCLUDE ================/
#include "clock.h"
#include "MKL46Z4.h"
//================ DEFINED ================/

//================ SUPPORT ================/

//================ FOCUSED ================/
void Clock_Enable(Perhipheral_Name_t name){
	switch (name){
	case CLK_PORTA:
		SIM->SCGC5 |= SIM_SCGC5_PORTA(1);
		break;
	case CLK_PORTB:
		SIM->SCGC5 |= SIM_SCGC5_PORTB(1);
		break;
	case CLK_PORTC:
		SIM->SCGC5 |= SIM_SCGC5_PORTC(1);
		break;
	case CLK_PORTD:
		SIM->SCGC5 |= SIM_SCGC5_PORTD(1);
		break;
	case CLK_PORTE:
		SIM->SCGC5 |= SIM_SCGC5_PORTE(1);
		break;
	case CLK_ADC0:
		SIM->SCGC6 |= SIM_SCGC6_ADC0(1);
		break;
	case CLK_PIT:
		SIM->SCGC6 |= SIM_SCGC6_PIT(1);
		break;
	}
};
