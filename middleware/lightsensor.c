//================ INCLUDE ================/
#include "lightsensor.h"
#include "MKL46Z4.h"
#include "port.h"
#include "clock.h"
#include "nvic.h"
#include "mdl2mdl.h"
#include "adc.h"
#include "pit.h"
//================ DEFINED ================/
static void nullHandlLightSensor(uint32_t _){}
Handle_LightSensor_t handle_LightSensorValue = nullHandlLightSensor;
//================ SUPPORT ================/
static void Config_PTE22_Pin(){
	//Clock port E
	Clock_Enable(CLK_PORTE);
	//ADC pin
	PORT_Config_Type PORT_Config = {
			.port = PORTE,
			.pin = 22,
			.mux = Analog,
	};
	PORT_PinConfig(&PORT_Config);
	//Clock ADC
	Clock_Enable(CLK_ADC0);
	//ADC initial
	ADC_Config_Type ADC0_Config = {
			.sc1Name = ADC_SC1A,
			.trigger = HARDWARE,
			.interrupt = ENABLE_IR,
			.srcClock = BUS_CLOCK,
			.voltage = REF_VOL,
			.continuous = DISABLE_CON,
			.resolution = MODE_16BIT,
			.mode = SINGLE_END,
			.input = I_DP3,
	};
	ADC_Config(&ADC0_Config);
	//ADC interrupt NVIC
	NVIC_EnableIRQn(IR_ADC0);
	//Clock PIT
	Clock_Enable(CLK_PIT);
	//PIT initial
	Pit_Config_Type Pit_Config_v = {
			.module = PIT_MODULE_ENABLE,
	};
	Pit_Config(&Pit_Config_v);
	//Set reload
	Pit_Timer_Reload(PIT_TIMER0, 10);//10ms trigger time 1;
	//Module to Module
	M2M_Interconnects(M2M_PIT2ADC);
}

void ADC0_IRQHandler(){
	//read value
	//return to call back function
	uint16_t valueADC = ADC_GetData16bit(ADC_SC1A);
	handle_LightSensorValue(valueADC);
}
//================ FOCUSED ================/
void LIGHTSENSOR_Init(LIGHTSENSOR_Name_t name){
	switch (name){
		case Light_sns:
			Config_PTE22_Pin();
		}
};
void LIGHTSENSOR_TurnOn(){
	Pit_Timer_Reload(PIT_TIMER0, 10);
	Pit_Timer_Start(PIT_TIMER0);
};
void LIGHTSENSOR_TurnOff();
void LIGHTSENSOR_Read(Handle_LightSensor_t _handle_LightSensorValue){
	handle_LightSensorValue = _handle_LightSensorValue;
};
