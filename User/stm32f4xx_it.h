/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f4xx_it.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
__IO uint8_t   SendFlag = 0;         // =1�����������ݣ�=0������
__IO uint16_t  SendTime = 1;         // �������ݷ��ͼ��ʱ��
__IO uint8_t   RecvFlag = 0;         // =1���յȴ�ʱ�������=0������
__IO uint16_t  RecvWaitTime = 0;     // ���յȴ�ʱ��
__IO uint8_t 	CollectCnt = 0;      	// ����MMA7361L����
/* Exported constants --------------------------------------------------------*/
#define 	SEND_GAP  			100 	// ���͵ȴ�0.1s
#define 	ACK_LENGTH      60   	// �������ݰ�����  
#define 	ACK_CNT					ACK_LENGTH/6			// floor(ACK_LENGTH/6)
uint8_t 	AckBuffer[ACK_LENGTH] = {'a','c','k','n','o','w','l','e','d','g','e'};
// ADCת���ĵ�ѹֵͨ��MDA���ݵ�SRAM
extern __IO uint16_t ADC_ConvertedValue[3];
// ���ڱ���ת�������ĵ�ѹֵ
//float ADC_ConvertedValueLocal[3];
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void DEBUG_USART_IRQHandler(void);
void BASIC_TIM_IRQHandler(void);
void CC1101_GDO2_IRQHandler(void);
void MMA7361L_ReadHandler(void);
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
