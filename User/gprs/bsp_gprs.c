/**
  ******************************************************************************
  * @file    bsp_gprs.c
  * @author  phoenix
  * @version V1.0.0
  * @date    31-January-2017
  * @brief   This file provides set of firmware functions to manage Leds ,
  *          push-button and spi available on STM32F4-Discovery Kit from STMicroelectronics.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */ 
	
#include "./gprs/bsp_gprs.h"

/**
  * @brief  MOD_GPRS_Config function
  * @param  None
  * @retval None
  */
void MOD_GPRS_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
    //����GPIO����ʱ��
    RCC_AHB1PeriphClockCmd(MOD_RESET_CLK|MOD_GPRS_CLK, ENABLE);
	
    //����MOD_RESET��GPIO����
    GPIO_InitStructure.GPIO_Pin = MOD_RESET_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MOD_RESET_PORT, &GPIO_InitStructure);
    
    //����MOD_GPRS��GPIO����
    GPIO_InitStructure.GPIO_Pin = MOD_GPRS_PIN;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_Init(MOD_GPRS_PORT, &GPIO_InitStructure);
	
		MOD_RESET_ON();
		MOD_GPRS_ON();
}

/******************* END OF FILE ******************/
