#include "stm32f10x.h"
void myuart_init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;//创建GPIO对象
	USART_InitTypeDef USART_InitStructure;//创建USART对象
	
	//设置时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//找管脚设置管脚9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	//中速
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//推挽复用输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);//选择GPIO A组
	
	//找管脚设置管脚10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	//中速
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//
	GPIO_Init(GPIOA, &GPIO_InitStructure);//选择GPIO A组
	
	//UART
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
	
}
void myuart_send(char c)
{
	
	USART_SendData(USART1,c);
	while (RESET == USART_GetFlagStatus(USART1,USART_FLAG_TXE));
}

char myuart_receive(void)
{
	while (RESET == USART_GetFlagStatus(USART1,USART_FLAG_RXNE));
	return USART_ReceiveData(USART1);
	
}