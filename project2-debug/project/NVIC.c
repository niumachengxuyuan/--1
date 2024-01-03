#include "stm32f10x.h"                  // Device header
#include "NVIC.h"
#include "UART.h"
#include "pwm.h"
#include "pwm4.h"
#include "pwm5.h"
#include "pwm9.h"
#include "pwm10.h"
#include "pwm11.h"
#include "ACTION.h"
int flag=0;


//uart1进行中断

void my_NVIC_init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//中断优先级分组
	
	//全局中断管理模块
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;  //
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //先占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
		
}

//中断处理函数

void USART1_IRQHandler(void)
{
	char recv_data = 0;
	
	if( USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
	{
		
		recv_data = uart1_recv_byte(); 
		
		if(recv_data == '1')
		{
			flag=1;
			USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清中断
			
		}	
		else if(recv_data == '2')
		{
			flag=2;
			USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清中断
		}
		else if(recv_data == '3')
		{
			flag=3;
			USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清中断
		}
		else if(recv_data == '4')
		{
			flag=4;
			USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清中断
		}
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE); //清中断
	}
}

