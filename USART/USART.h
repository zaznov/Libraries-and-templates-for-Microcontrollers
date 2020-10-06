/**
  ******************************************************************************
  * @file    USART.h
  * @author  Zaznov NIIKP
  * @version V1.0.2
  * @date    03/02/2020
  * @brief   This file contains functions prototypes for work with USART
  in STM32 Controllers
  ******************************************************************************
  * FILE USART.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H_
#define __USART_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"

/* defines -------------------------------------------------------------------*/  

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void USART_init(void);
void USART_SendData_secure(USART_TypeDef* USARTx, uint16_t Data);

#endif /* __USART_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE UART.h */
