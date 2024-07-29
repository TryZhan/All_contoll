#ifndef __UART_H
#define __UART_H

#include "board.h"

#define USART_RECEIVE_LENGTH 200


extern void OpenMV4_usart_config(void);
extern void Openmv4DataAnalysis(void);
extern void HardFault_Handler();
<<<<<<< HEAD

extern int16_t Data_Pwm;
=======
extern float RecvPWM;
>>>>>>> 31d7d11425ac9fc53de4a84b5c93c7b7afda679c

#endif
