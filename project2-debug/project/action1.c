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

/**********************************************����1**************************/	

void  maeching_action1()
{

		int i=0;		
		pwm4_init(19);//M4	���4
		delay(1000);
		pwm_init(19);//M8		���2
		delay(2000);
		
		pwm9_init(15);  //���6  ���Ӹպñպ�
		delay(2000);
//���ϻ�����4���������ȣ����3����ʼλ�����4����ʼλ	
		pwm10_init(18);//���3
		delay(500);
		pwm4_init(18);
		delay(500);
/**************������������ʼ��ת	**************/
		for(i=6;i<=9;i++)
		{
			pwm5_init(i);
			delay(200);	
		}
/****************��ת��λ�����ӷ���	*******************/
		pwm4_init(19);
		delay(500);
		pwm4_init(20);
		delay(500);	
		pwm4_init(21);
		delay(500);	
		pwm9_init(10);  //���6 �ſ�
		delay(1000);
		pwm4_init(18);
		
/****************���û���������ص���ʼλ��	*******************/
		for( i=9;i>=5;i--)
		{
			pwm5_init(i);
			delay(200);
		}
		delay(200);
		pwm4_init(19);
		pwm_init(18);//M8		���2
		delay(300);	
		pwm9_init(9);  // M9 ���6 ��ʼ��
		delay(300);		
		pwm11_init(15);//M11  ���5 ��ʼ��
		delay(300);
		pwm10_init(21);//M10 ���3 ��ʼ��
		delay(300);
		pwm4_init(21);//M4	���4
	
}
