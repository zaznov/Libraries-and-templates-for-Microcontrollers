/**
  ******************************************************************************
  * @file    timers.c
  * @author  Zaznov NIIKP
  * @version V1.0.3
  * @date    15/03/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of STM32 timers:           
  *           + ...
  *           + ...
  *           + ...
  ******************************************************************************
  * FILE timers.c
  */
/* Includes ------------------------------------------------------------------*/
#include "timers.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/


void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        //GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
    }


}


void timer_init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    TIM_TimeBaseInitTypeDef timer_struck;
    timer_struck.TIM_Prescaler = 20000 - 1;
    timer_struck.TIM_ClockDivision = TIM_CKD_DIV1;
    timer_struck.TIM_CounterMode = TIM_CounterMode_Up;
    timer_struck.TIM_Period = 950;
    timer_struck.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timer_struck);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    
    
    NVIC_InitTypeDef NVIC_STRUCT;
    NVIC_STRUCT.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_STRUCT.NVIC_IRQChannelSubPriority = 0;
    NVIC_STRUCT.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_STRUCT.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_STRUCT);
    
    TIM_Cmd(TIM2, ENABLE);

}

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE timers.c */

