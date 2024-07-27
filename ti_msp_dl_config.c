/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerG_backupConfig gPWM_MotorABackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_MotorB_init();
    SYSCFG_DL_PWM_MotorA_init();
    SYSCFG_DL_TIMER_0_init();
    SYSCFG_DL_USB_TLL_init();
    SYSCFG_DL_UART_Trans_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gPWM_MotorABackup.backupRdy 	= false;



}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_saveConfiguration(PWM_MotorA_INST, &gPWM_MotorABackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_restoreConfiguration(PWM_MotorA_INST, &gPWM_MotorABackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerG_reset(PWM_MotorB_INST);
    DL_TimerG_reset(PWM_MotorA_INST);
    DL_TimerG_reset(TIMER_0_INST);
    DL_UART_Main_reset(USB_TLL_INST);
    DL_UART_Main_reset(UART_Trans_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerG_enablePower(PWM_MotorB_INST);
    DL_TimerG_enablePower(PWM_MotorA_INST);
    DL_TimerG_enablePower(TIMER_0_INST);
    DL_UART_Main_enablePower(USB_TLL_INST);
    DL_UART_Main_enablePower(UART_Trans_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MotorB_C0_IOMUX,GPIO_PWM_MotorB_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MotorB_C0_PORT, GPIO_PWM_MotorB_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MotorB_C1_IOMUX,GPIO_PWM_MotorB_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MotorB_C1_PORT, GPIO_PWM_MotorB_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MotorA_C0_IOMUX,GPIO_PWM_MotorA_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MotorA_C0_PORT, GPIO_PWM_MotorA_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MotorA_C1_IOMUX,GPIO_PWM_MotorA_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MotorA_C1_PORT, GPIO_PWM_MotorA_C1_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_USB_TLL_IOMUX_TX, GPIO_USB_TLL_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_USB_TLL_IOMUX_RX, GPIO_USB_TLL_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_Trans_IOMUX_TX, GPIO_UART_Trans_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_Trans_IOMUX_RX, GPIO_UART_Trans_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutputFeatures(LED1_PIN_27_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalInputFeatures(KEY_PIN_18_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(OLED_SCL_IOMUX);

    DL_GPIO_initDigitalOutput(OLED_SDA_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_PIN_Right_A_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_PIN_Right_B_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_PIN_Left_A_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_Encoder_PIN_Left_B_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_LineGet_PIN_Line_Left1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_LineGet_PIN_Line_Left2_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_LineGet_PIN_Line_Right1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_LineGet_PIN_Line_Right2_IOMUX);

    DL_GPIO_clearPins(GPIOA, LED1_PIN_27_PIN);
    DL_GPIO_setPins(GPIOA, OLED_SCL_PIN |
		OLED_SDA_PIN);
    DL_GPIO_enableOutput(GPIOA, LED1_PIN_27_PIN |
		OLED_SCL_PIN |
		OLED_SDA_PIN);
    DL_GPIO_setUpperPinsPolarity(GPIOA, DL_GPIO_PIN_18_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOA, KEY_PIN_18_PIN);
    DL_GPIO_enableInterrupt(GPIOA, KEY_PIN_18_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_2_EDGE_RISE |
		DL_GPIO_PIN_9_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_Encoder_PIN_Right_A_PIN |
		GPIO_Encoder_PIN_Left_A_PIN);
    DL_GPIO_enableInterrupt(GPIOB, GPIO_Encoder_PIN_Right_A_PIN |
		GPIO_Encoder_PIN_Left_A_PIN);

}



SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_enableMFCLK();

}


/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   4000000 Hz = 4000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gPWM_MotorBClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gPWM_MotorBConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 4000,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_MotorB_init(void) {

    DL_TimerG_setClockConfig(
        PWM_MotorB_INST, (DL_TimerG_ClockConfig *) &gPWM_MotorBClockConfig);

    DL_TimerG_initPWMMode(
        PWM_MotorB_INST, (DL_TimerG_PWMConfig *) &gPWM_MotorBConfig);

    DL_TimerG_setCaptureCompareOutCtl(PWM_MotorB_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_MotorB_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_MotorB_INST, 1199, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(PWM_MotorB_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_MotorB_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_MotorB_INST, 1199, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(PWM_MotorB_INST);


    
    DL_TimerG_setCCPDirection(PWM_MotorB_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 8 (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   4000000 Hz = 4000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gPWM_MotorAClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gPWM_MotorAConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 4000,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_MotorA_init(void) {

    DL_TimerG_setClockConfig(
        PWM_MotorA_INST, (DL_TimerG_ClockConfig *) &gPWM_MotorAClockConfig);

    DL_TimerG_initPWMMode(
        PWM_MotorA_INST, (DL_TimerG_PWMConfig *) &gPWM_MotorAConfig);

    DL_TimerG_setCaptureCompareOutCtl(PWM_MotorA_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_MotorA_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_MotorA_INST, 1199, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(PWM_MotorA_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(PWM_MotorA_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(PWM_MotorA_INST, 1199, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(PWM_MotorA_INST);


    
    DL_TimerG_setCCPDirection(PWM_MotorA_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (4000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   15625 Hz = 4000000 Hz / (8 * (255 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 255U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_0_INST_LOAD_VALUE = (100ms * 15625 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_0TimerConfig = {
    .period     = TIMER_0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_0_init(void) {

    DL_TimerG_setClockConfig(TIMER_0_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_0ClockConfig);

    DL_TimerG_initTimerMode(TIMER_0_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_0TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_0_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_0_INST);





}



static const DL_UART_Main_ClockConfig gUSB_TLLClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUSB_TLLConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_USB_TLL_init(void)
{
    DL_UART_Main_setClockConfig(USB_TLL_INST, (DL_UART_Main_ClockConfig *) &gUSB_TLLClockConfig);

    DL_UART_Main_init(USB_TLL_INST, (DL_UART_Main_Config *) &gUSB_TLLConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115211.52
     */
    DL_UART_Main_setOversampling(USB_TLL_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(USB_TLL_INST, USB_TLL_IBRD_32_MHZ_115200_BAUD, USB_TLL_FBRD_32_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(USB_TLL_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(USB_TLL_INST);
}

static const DL_UART_Main_ClockConfig gUART_TransClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_MFCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_TransConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_Trans_init(void)
{
    DL_UART_Main_setClockConfig(UART_Trans_INST, (DL_UART_Main_ClockConfig *) &gUART_TransClockConfig);

    DL_UART_Main_init(UART_Trans_INST, (DL_UART_Main_Config *) &gUART_TransConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115107.91
     */
    DL_UART_Main_setOversampling(UART_Trans_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_Trans_INST, UART_Trans_IBRD_4_MHZ_115200_BAUD, UART_Trans_FBRD_4_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_Trans_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(UART_Trans_INST_INT_IRQN, 0);


    DL_UART_Main_enable(UART_Trans_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /* Initialize the period to 1.00 μs */
    DL_SYSTICK_init(32);
    /* Enable the SysTick and start counting */
    DL_SYSTICK_enable();
}

