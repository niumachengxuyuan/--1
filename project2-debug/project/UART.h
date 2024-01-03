#ifndef  UART_H
#define  UART_H

#include "stm32f10x.h"
//设置串口通信函数
//void uart_send_char(char data);//发送字节数据
//void uart_send_databuff(char *p);//发送字符串数据
//char uart_recive_data(void);//接收字节数据

//void uart_init(void); //串口初始化
void uart1_init(int BaudRate);
void uart1_send_byte(char data);
void uart1_send_str(char *str);

char uart1_recv_byte(void);


#endif
