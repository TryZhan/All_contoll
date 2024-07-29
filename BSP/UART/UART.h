#ifndef __UART_H
#define __UART_H

#include "board.h"

#define USART_RECEIVE_LENGTH 200


extern void OpenMV4_usart_config(void);
extern void Openmv4DataAnalysis(void);
extern void HardFault_Handler();

extern int16_t Data_Pwm;

#endif
