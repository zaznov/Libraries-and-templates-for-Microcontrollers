/**
  ******************************************************************************
  * @file    handlers.c
  * @author  Zaznov NIIKP
  * @version V1.0.2
  * @date    25/02/2020
  * @brief   This file provides firmware functions to work with following handlers:           
  *           + SysTick_Handler
  *           + USART2_IRQHandler
  *           + ...
  ******************************************************************************
  * FILE handlers.c
  */
/* Includes ------------------------------------------------------------------*/
#include "handlers.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/


void SysTick_Handler(void)
{
    ticks_Wert++;
}        

void USART2_IRQHandler(void)
{

}

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE handlers.c */
