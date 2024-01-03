#include "UART.h"
#include "stm32f10x.h"   


void uart1_init(int BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure; 
	
	//RCC GPIOA USART1时钟使能 上电
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	
	//GPIO初始化 PA9-复用推挽输出  PA10-浮空输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	//USART1 初始化
	USART_InitStructure.USART_BaudRate = BaudRate; //波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位 8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //停止位 1位
	USART_InitStructure.USART_Parity = USART_Parity_No;  //校验位 无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //硬件流控制位 无
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //模式 发送 接收使能
	USART_Init(USART1, &USART_InitStructure); //初始化
	
	//USART1 使能
	USART_Cmd(USART1, ENABLE);
	
	
	//USART1 接收中断配置
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void uart1_send_byte(char data)
{	
	USART_SendData(USART1, data);
	
	//等待 发送完成
	//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void uart1_send_str(char *str)
{
	while(*str != '\0')
	{
		uart1_send_byte(*str);
		str++;
	}
}

char uart1_recv_byte(void)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
	return USART_ReceiveData(USART1);
}

