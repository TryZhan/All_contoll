#include "PWM.h"

/*
        ���BΪ�ҵ��(TIMG12)                ���AΪ����(TIMG6)              
        BIN2��PA14                     		BIN1: PA25
        AIN2: PA22                    		AIN1: PA21
*/

void PwmA_Duty_Set(float Duty,uint8_t channel)				//PWMƵ��Ϊ1kHz
//timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
{
	uint32_t CompareValue = 4000 - Duty;
	switch(channel){
		case 0:
			DL_TimerG_setCaptureCompareValue(PWM_MotorA_INST,CompareValue,GPIO_PWM_MotorA_C0_IDX);			
			break;
		case 1:
			DL_TimerG_setCaptureCompareValue(PWM_MotorA_INST,CompareValue,GPIO_PWM_MotorA_C1_IDX);
			break;
	}
}

void PwmB_Duty_Set(float Duty,uint8_t channel)				//PWMƵ��Ϊ1kHz
//timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
{
<<<<<<< HEAD
	uint32_t CompareValue = 4000 - Duty;
=======
	uint32_t CompareValue = 4000 - (1 - Duty) * 4000;
	
>>>>>>> 31d7d11425ac9fc53de4a84b5c93c7b7afda679c
	switch(channel){
		case 0:
			DL_TimerG_setCaptureCompareValue(PWM_MotorB_INST,CompareValue,GPIO_PWM_MotorB_C0_IDX);			
			break;
		case 1:
			DL_TimerG_setCaptureCompareValue(PWM_MotorB_INST,CompareValue,GPIO_PWM_MotorB_C1_IDX);
			break;
	}
}


