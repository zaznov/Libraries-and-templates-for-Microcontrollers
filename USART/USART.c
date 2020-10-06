/**
  ******************************************************************************
  * @file    USART.c
  * @author  Zaznov NIIKP
  * @version V1.0.2
  * @date    03/02/2020
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the USART-driver:           
  *           + Initialization and Configuration
  *           + Transmission data with pending buffer flush.
  *           + ...
  ******************************************************************************
  * FILE USART.c
  */
/* Includes ------------------------------------------------------------------*/
#include "USART.h"

/* Defines -------------------------------------------------------------------*/ 

/* Variables -----------------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/

void USART_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                       
    GPIO_InitTypeDef GPIO_struct_USART2;
    GPIO_struct_USART2.GPIO_Pin                 = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_struct_USART2.GPIO_Mode                = GPIO_Mode_AF;
    GPIO_struct_USART2.GPIO_OType               = GPIO_OType_PP;
    GPIO_struct_USART2.GPIO_PuPd                = GPIO_PuPd_UP;
    GPIO_struct_USART2.GPIO_Speed               = GPIO_Low_Speed;
    GPIO_Init(GPIOA, &GPIO_struct_USART2);
    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);  
    
    USART_InitTypeDef USART_InitSTRUCT;
    USART_InitSTRUCT.USART_BaudRate             = 9600;
    USART_InitSTRUCT.USART_HardwareFlowControl  = USART_HardwareFlowControl_None;   
    USART_InitSTRUCT.USART_Mode                 = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitSTRUCT.USART_Parity               = USART_Parity_No;
    USART_InitSTRUCT.USART_StopBits             = USART_StopBits_1;
    USART_InitSTRUCT.USART_WordLength           = USART_WordLength_8b;
    USART_Init(USART2, &USART_InitSTRUCT);
    
    USART_Cmd(USART2, ENABLE);
    /*USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);*/
    /*NVIC_EnableIRQ(USART2_IRQn);*/
}



void USART2_IRQHandler(void)
{
    if(USART_GetITStatus(USART2, USART_IT_RXNE) ==1)
    {
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == 0)
            ;
        USART_SendData(USART2, 0xAA);    
    } 
}

/**
  * @brief  Transmits single data through the USARTx peripheral with pending 
  buffer flush.
  * @param  USARTx: where x can be 1, 2, 3, 4, 5, 6, 7 or 8 to select the USART or 
  *         UART peripheral.
  * @param  Data: the data to transmit.
  * @retval None
  */
void USART_SendData_secure(USART_TypeDef* USARTx, uint16_t Data)
{
    /* Check the parameters */
    assert_param(IS_USART_ALL_PERIPH(USARTx));
    assert_param(IS_USART_DATA(Data)); 
    while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == 0)
        ;
    /* Transmit Data */
    USARTx->DR = (Data & (uint16_t)0x01FF);
}

/************************* 2020 Zaznov NIIKP ***********************************
*
* END OF FILE USART.c */
