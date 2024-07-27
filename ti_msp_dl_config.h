/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_MotorB */
#define PWM_MotorB_INST                                                   TIMG12
#define PWM_MotorB_INST_IRQHandler                             TIMG12_IRQHandler
#define PWM_MotorB_INST_INT_IRQN                               (TIMG12_INT_IRQn)
#define PWM_MotorB_INST_CLK_FREQ                                         4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MotorB_C0_PORT                                            GPIOA
#define GPIO_PWM_MotorB_C0_PIN                                    DL_GPIO_PIN_14
#define GPIO_PWM_MotorB_C0_IOMUX                                 (IOMUX_PINCM36)
#define GPIO_PWM_MotorB_C0_IOMUX_FUNC               IOMUX_PINCM36_PF_TIMG12_CCP0
#define GPIO_PWM_MotorB_C0_IDX                               DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MotorB_C1_PORT                                            GPIOA
#define GPIO_PWM_MotorB_C1_PIN                                    DL_GPIO_PIN_25
#define GPIO_PWM_MotorB_C1_IOMUX                                 (IOMUX_PINCM55)
#define GPIO_PWM_MotorB_C1_IOMUX_FUNC               IOMUX_PINCM55_PF_TIMG12_CCP1
#define GPIO_PWM_MotorB_C1_IDX                               DL_TIMER_CC_1_INDEX

/* Defines for PWM_MotorA */
#define PWM_MotorA_INST                                                    TIMG6
#define PWM_MotorA_INST_IRQHandler                              TIMG6_IRQHandler
#define PWM_MotorA_INST_INT_IRQN                                (TIMG6_INT_IRQn)
#define PWM_MotorA_INST_CLK_FREQ                                         4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MotorA_C0_PORT                                            GPIOA
#define GPIO_PWM_MotorA_C0_PIN                                    DL_GPIO_PIN_21
#define GPIO_PWM_MotorA_C0_IOMUX                                 (IOMUX_PINCM46)
#define GPIO_PWM_MotorA_C0_IOMUX_FUNC                IOMUX_PINCM46_PF_TIMG6_CCP0
#define GPIO_PWM_MotorA_C0_IDX                               DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MotorA_C1_PORT                                            GPIOA
#define GPIO_PWM_MotorA_C1_PIN                                    DL_GPIO_PIN_22
#define GPIO_PWM_MotorA_C1_IOMUX                                 (IOMUX_PINCM47)
#define GPIO_PWM_MotorA_C1_IOMUX_FUNC                IOMUX_PINCM47_PF_TIMG6_CCP1
#define GPIO_PWM_MotorA_C1_IDX                               DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1562U)



/* Defines for USB_TLL */
#define USB_TLL_INST                                                       UART0
#define USB_TLL_INST_IRQHandler                                 UART0_IRQHandler
#define USB_TLL_INST_INT_IRQN                                     UART0_INT_IRQn
#define GPIO_USB_TLL_RX_PORT                                               GPIOA
#define GPIO_USB_TLL_TX_PORT                                               GPIOA
#define GPIO_USB_TLL_RX_PIN                                       DL_GPIO_PIN_11
#define GPIO_USB_TLL_TX_PIN                                       DL_GPIO_PIN_10
#define GPIO_USB_TLL_IOMUX_RX                                    (IOMUX_PINCM22)
#define GPIO_USB_TLL_IOMUX_TX                                    (IOMUX_PINCM21)
#define GPIO_USB_TLL_IOMUX_RX_FUNC                     IOMUX_PINCM22_PF_UART0_RX
#define GPIO_USB_TLL_IOMUX_TX_FUNC                     IOMUX_PINCM21_PF_UART0_TX
#define USB_TLL_BAUD_RATE                                               (115200)
#define USB_TLL_IBRD_32_MHZ_115200_BAUD                                     (17)
#define USB_TLL_FBRD_32_MHZ_115200_BAUD                                     (23)
/* Defines for UART_Trans */
#define UART_Trans_INST                                                    UART1
#define UART_Trans_INST_IRQHandler                              UART1_IRQHandler
#define UART_Trans_INST_INT_IRQN                                  UART1_INT_IRQn
#define GPIO_UART_Trans_RX_PORT                                            GPIOA
#define GPIO_UART_Trans_TX_PORT                                            GPIOA
#define GPIO_UART_Trans_RX_PIN                                     DL_GPIO_PIN_9
#define GPIO_UART_Trans_TX_PIN                                     DL_GPIO_PIN_8
#define GPIO_UART_Trans_IOMUX_RX                                 (IOMUX_PINCM20)
#define GPIO_UART_Trans_IOMUX_TX                                 (IOMUX_PINCM19)
#define GPIO_UART_Trans_IOMUX_RX_FUNC                  IOMUX_PINCM20_PF_UART1_RX
#define GPIO_UART_Trans_IOMUX_TX_FUNC                  IOMUX_PINCM19_PF_UART1_TX
#define UART_Trans_BAUD_RATE                                            (115200)
#define UART_Trans_IBRD_4_MHZ_115200_BAUD                                    (2)
#define UART_Trans_FBRD_4_MHZ_115200_BAUD                                   (11)





/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOA)

/* Defines for PIN_27: GPIOA.27 with pinCMx 60 on package pin 31 */
#define LED1_PIN_27_PIN                                         (DL_GPIO_PIN_27)
#define LED1_PIN_27_IOMUX                                        (IOMUX_PINCM60)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
// pins affected by this interrupt request:["PIN_18"]
#define KEY_INT_IRQN                                            (GPIOA_INT_IRQn)
#define KEY_INT_IIDX                            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEY_PIN_18_IIDX                                     (DL_GPIO_IIDX_DIO18)
#define KEY_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define KEY_PIN_18_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOA)

/* Defines for SCL: GPIOA.0 with pinCMx 1 on package pin 33 */
#define OLED_SCL_PIN                                             (DL_GPIO_PIN_0)
#define OLED_SCL_IOMUX                                            (IOMUX_PINCM1)
/* Defines for SDA: GPIOA.1 with pinCMx 2 on package pin 34 */
#define OLED_SDA_PIN                                             (DL_GPIO_PIN_1)
#define OLED_SDA_IOMUX                                            (IOMUX_PINCM2)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOB)

/* Defines for PIN_Right_A: GPIOB.2 with pinCMx 15 on package pin 50 */
// pins affected by this interrupt request:["PIN_Right_A","PIN_Left_A"]
#define GPIO_Encoder_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_Encoder_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_PIN_Right_A_IIDX                        (DL_GPIO_IIDX_DIO2)
#define GPIO_Encoder_PIN_Right_A_PIN                             (DL_GPIO_PIN_2)
#define GPIO_Encoder_PIN_Right_A_IOMUX                           (IOMUX_PINCM15)
/* Defines for PIN_Right_B: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_Encoder_PIN_Right_B_PIN                             (DL_GPIO_PIN_3)
#define GPIO_Encoder_PIN_Right_B_IOMUX                           (IOMUX_PINCM16)
/* Defines for PIN_Left_A: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_Encoder_PIN_Left_A_IIDX                         (DL_GPIO_IIDX_DIO9)
#define GPIO_Encoder_PIN_Left_A_PIN                              (DL_GPIO_PIN_9)
#define GPIO_Encoder_PIN_Left_A_IOMUX                            (IOMUX_PINCM26)
/* Defines for PIN_Left_B: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_Encoder_PIN_Left_B_PIN                              (DL_GPIO_PIN_8)
#define GPIO_Encoder_PIN_Left_B_IOMUX                            (IOMUX_PINCM25)
/* Port definition for Pin Group GPIO_LineGet */
#define GPIO_LineGet_PORT                                                (GPIOB)

/* Defines for PIN_Line_Left1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_LineGet_PIN_Line_Left1_PIN                         (DL_GPIO_PIN_19)
#define GPIO_LineGet_PIN_Line_Left1_IOMUX                        (IOMUX_PINCM45)
/* Defines for PIN_Line_Left2: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_LineGet_PIN_Line_Left2_PIN                         (DL_GPIO_PIN_18)
#define GPIO_LineGet_PIN_Line_Left2_IOMUX                        (IOMUX_PINCM44)
/* Defines for PIN_Line_Right1: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_LineGet_PIN_Line_Right1_PIN                        (DL_GPIO_PIN_20)
#define GPIO_LineGet_PIN_Line_Right1_IOMUX                       (IOMUX_PINCM48)
/* Defines for PIN_Line_Right2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_LineGet_PIN_Line_Right2_PIN                        (DL_GPIO_PIN_24)
#define GPIO_LineGet_PIN_Line_Right2_IOMUX                       (IOMUX_PINCM52)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MotorB_init(void);
void SYSCFG_DL_PWM_MotorA_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_USB_TLL_init(void);
void SYSCFG_DL_UART_Trans_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
