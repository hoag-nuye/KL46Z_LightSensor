//================ INCLUDE ================/
#include "MKL46Z4.h"
#include "interface.h"
//================ DEFINED ================/
//================ SUPPORT ================/
static State_Machine_t state = DO_NOTHING;
//handle button
static void handleButton(BUTTON_Name_t name){
	switch (name){
	case SW1:
		state = TOGGLE_LED;
		break;
	case SW2:
		state = FLASHING_LED;
		break;
	}
};


//================ FOCUSED ================/
void BUTTON_LED_Toggle(){
	LED_Init(LED1);
	LED_Init(LED2);
	BUTTON_Init(SW1);
	BUTTON_Init(SW2);
	Read_BUTTON(handleButton);
	while(1){
		switch (state){
		case DO_NOTHING:
			break;
		case TOGGLE_LED:
			Toggle_LED(LED1);
			Flash_LED_Timer(LED2, 3, 200);
			state = DO_NOTHING;
			break;
		case FLASHING_LED:
			Flash_LED_Timer(LED1, 3, 200);
			Flash_LED_Timer(LED2, 3, 200);
			state = DO_NOTHING;
			break;
		}
	}
};

void LIGHTSENSOR_ACTIVE_TEST(){
	LIGHTSENSOR_Init(Light_sns);
	LIGHTSENSOR_TurnOn();
	while(1){

		}
};
