#ifndef __FUNCTION_H
#define __FUNCTION_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./tim/bsp_basic_tim.h"
#include "./spi/bsp_spi.h"
#include "./key/bsp_key.h"
#include "./fsmc/bsp_fsmc.h" 
#include "./rtc/bsp_rtc.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define TX              0       // cc1101����ģʽ
#define RX              1       // cc1101����ģʽ
#define IDLE          	2       // cc1101����ģʽ
#define ACK_LENGTH      24   		// �������ݰ�����
#define ACK_CNT					ACK_LENGTH/6	// floor(ACK_LENGTH/6)
#define SEND_LENGTH     10			// �������ݰ�����
#define RECV_LENGTH   		17			// �������ݰ�����
#define RECV_TIMEOUT		2000  	// ���յȴ�2s
#define SEND_PACKAGE_NUM	80		// �������ݰ���
/* Exported macro ------------------------------------------------------------*/
extern __IO uint16_t	RecvWaitTime;  	// ���յȴ�ʱ��
extern __IO uint8_t		RecvFlag;     	// =1���յȴ�ʱ�������=0������

/* Exported functions ------------------------------------------------------- */
void MCU_Initial(void);
void RF_Initial(uint8_t addr, uint16_t sync, uint8_t mode);
void System_Initial(void);
void Function_Ctrl(uint8_t *commend);
void Check_Assign_RFID(uint8_t *commend);
void Check_All_RFID(uint8_t *commend);
void RF_SendPacket(uint8_t *commend, uint32_t rfid);
uint8_t	RF_Acknowledge(void);
void Reply_PC(uint8_t index);
void GetNandFlashAddr(flashInfo* pFlshInfo);

#endif /* __FUNCTION_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
