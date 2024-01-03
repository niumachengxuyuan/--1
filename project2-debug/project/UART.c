#include "UART.h"
#include "stm32f10x.h"   


void uart1_init(int BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure; 
	
	//RCC GPIOA USART1ʱ��ʹ�� �ϵ�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	
	//GPIO��ʼ�� PA9-�����������  PA10-��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	//USART1 ��ʼ��
	USART_InitStructure.USART_BaudRate = BaudRate; //������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //����λ 8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1; //ֹͣλ 1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;  //У��λ ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //Ӳ��������λ ��
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //ģʽ ���� ����ʹ��
	USART_Init(USART1, &USART_InitStructure); //��ʼ��
	
	//USART1 ʹ��
	USART_Cmd(USART1, ENABLE);
	
	
	//USART1 �����ж�����
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void uart1_send_byte(char data)
{	
	USART_SendData(USART1, data);
	
	//�ȴ� �������
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

