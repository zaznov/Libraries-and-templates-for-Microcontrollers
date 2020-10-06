/**
  ******************************************************************************
  * @file    timers.h
  * @author  Zaznov NIIKP
  * @version V1.0.3
  * @date    15/03/2020
  * @brief   This file contains functions prototypes for work with STM32 timers
  ******************************************************************************
  * FILE timers.h
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMERS_H_
#define __TIMERS_H_
/* Includes ------------------------------------------------------------------*/ 
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"
#include "stm32f4xx_gpio.h"

/* defines -------------------------------------------------------------------*/  

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

void timer_init(void);

#endif /* __TIMERS_H_ */

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE timers.h */
