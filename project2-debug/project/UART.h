#ifndef  UART_H
#define  UART_H

#include "stm32f10x.h"
//���ô���ͨ�ź���
//void uart_send_char(char data);//�����ֽ�����
//void uart_send_databuff(char *p);//�����ַ�������
//char uart_recive_data(void);//�����ֽ�����

//void uart_init(void); //���ڳ�ʼ��
void uart1_init(int BaudRate);
void uart1_send_byte(char data);
void uart1_send_str(char *str);

char uart1_recv_byte(void);


#endif
