#include "stm32f10x.h"
#include "myusart.h"
#include "pwm.h"
#include "pwm9.h"
#include "pwm10.h"
#include "pwm11.h"
#include "pwm4.h"
#include "UART.h"
#include "NVIC.h"
#include "ACTION.h"
#include "LEDTEST.h"

/******** �����жϿ��ƹ���������********/
extern int flag;

//��ʱ
void delay (int n)
{
	int i;
	while(n--)
		for(i=0;i<8050;i++);
}

//M12 M13Ԥ������uartͨ��

//������
int main()
{
//	int i=0, j=10;
//	pwm9_init(12);//M9  ��21Ч����ã����6
//	delay(300);	
//	pwm11_init(15);//M11 ���5
//	delay(300);
//	pwm10_init(20);//M10 ���3
//	delay(300);
//	pwm_init(18);//M8		���2
//	delay(300);
//	pwm4_init(21);//M4	���4
//	delay(300);
//	pwm5_init(5);//M5  �Ӷ��1  ����TIM_Pulsֵ��5��26.����ֵ����
	uart1_init(115200);
	my_NVIC_init();
	
	while(1)
	{
/*********************** �����ʼ��***********************************/
		
		pwm_init(18);//M8		���2
		delay(300);	
		pwm9_init(9);  // M9 ���6 ��ʼ��
		delay(300);		
		pwm11_init(15);//M11  ���5 ��ʼ��
		delay(300);
		pwm10_init(21);//M10 ���3 ��ʼ��
		delay(300);
		pwm4_init(20);//M4	���4
	
		uart1_send_byte('h');
			
		delay(500);
		uart1_send_str("world");
		
/************************** ִ�ж���ѡ��*****************************/
		switch(flag)
		{
			case 1:
				maeching_action1();
				flag=0;
				break;
			case 2:
				maeching_action2();
				flag=0;
				break;
			case 3:
				maeching_action3();
				flag=0;
				break;
			case 4:
				maeching_action4();
				flag=0;
				break;
			default:
				break;
		}
			
						
	}
		

}

