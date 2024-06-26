//================ INCLUDE ================/
#include "tpm.h"
#include "MKL46Z4.h"
#include "driverLib.h"
//================ DEFINED ================/
static TPM_ClockMode_t ClkMode = TPM_CLOCK_DISABLE;
//================ SUPPORT ================/
static void Channel_Mode_Config(TPM_Type* tpm, uint8_t channel,TPM_ChannelMode_t channelMode){
	switch (channelMode){
	case TPM_EPWM_High_MODE:
		//CPWMS = 0
		tpm->SC &= ~TPM_SC_CPWMS_MASK;
		tpm->SC |= TPM_SC_CPWMS(0U);
		//MSnB:MSnA = [1:0]
		tpm->CONTROLS[channel].CnSC &= ~TPM_CnSC_MSB_MASK;
		tpm->CONTROLS[channel].CnSC |= TPM_CnSC_MSB(1);

		tpm->CONTROLS[channel].CnSC &= ~TPM_CnSC_MSA_MASK;
		tpm->CONTROLS[channel].CnSC |= TPM_CnSC_MSA(0);
		//ELSnB:ELSnA = [1:0]
		tpm->CONTROLS[channel].CnSC &= ~TPM_CnSC_ELSB_MASK;
		tpm->CONTROLS[channel].CnSC |= TPM_CnSC_ELSB(1);

		tpm->CONTROLS[channel].CnSC &= ~TPM_CnSC_ELSA_MASK;
		tpm->CONTROLS[channel].CnSC |= TPM_CnSC_ELSA(0);
		break;
	}
}

//================ FOCUSED ================/
void TPM_PWM_Config(TPM_PWM_Config_t* tpmConfig){
	ClkMode = tpmConfig->clockMode;
	Channel_Mode_Config(tpmConfig->tpm,tpmConfig->channel, tpmConfig->channelMode);
};
void TPM_PWM_Enable(TPM_Type* tpm){
	switch (ClkMode){
	case TPM_CLOCK_DISABLE:
		break;
	case TPM_CLOCK_MODULE:
		//CMOD = 01 and PS = 0 (divide 1)
		//NOTE : PS can be written only when the counter is disabled
		//=> Configuration PS before CMOD in CONFIG function
		tpm->SC &= ~TPM_SC_CMOD_MASK;
		tpm->SC |= TPM_SC_CMOD(0b01);
		break;
	case TPM_CLOCK_EXTERNAL:
		break;
	}
};
void TPM_PWM_SetMODValue(TPM_Type* tpm, uint8_t channel, uint16_t freqOfPeriod){
	//Calculate BUS clock
	uint32_t Pit_clock = GetBusClock();
	//Calculate modulo value by BUS clock and Period
	tpm->MOD &= ~TPM_MOD_MOD_MASK;
	tpm->MOD |= TPM_MOD_MOD((uint16_t)((uint32_t)freqOfPeriod/Pit_clock));
};
void TPM_PWM_SetCOUNTCounter(TPM_Type* tpm, uint8_t channel, uint16_t freqOfDuty){
	//Calculate BUS clock
	uint32_t Pit_clock = GetBusClock();
	//Calculate count value by BUS clock and Duty Cycle
	tpm->CNT &= ~TPM_CNT_COUNT_MASK;
	tpm->CNT |= TPM_CNT_COUNT((uint16_t)((uint32_t)freqOfDuty/Pit_clock));
};
