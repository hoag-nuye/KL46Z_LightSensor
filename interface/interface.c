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


static void Flash_LED_Timer(LED_Name_t name, uint8_t times,uint16_t timeMs){
	SysTick_Config_Type sysTickConfig = {
			.clkSrc = SysTick_Processor_Clk,
	};
	SysTick_Init(sysTickConfig);
	SysTick_Reload(timeMs);
	uint8_t idx;
	for (idx = 0; idx <times*2; idx++){
		SysTick_Enable();
		while(SysTick_CountFlag() != Sys_Flag_Counted){}
		Toggle_LED(name);
		SysTick_ClearFlag();
		SysTick_Disable();
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
