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

/******** 引自中断控制管理器部分********/
extern int flag;

//延时
void delay (int n)
{
	int i;
	while(n--)
		for(i=0;i<8050;i++);
}

//M12 M13预留，做uart通信

//主函数
int main()
{
//	int i=0, j=10;
//	pwm9_init(12);//M9  （21效果最好）舵机6
//	delay(300);	
//	pwm11_init(15);//M11 舵机5
//	delay(300);
//	pwm10_init(20);//M10 舵机3
//	delay(300);
//	pwm_init(18);//M8		舵机2
//	delay(300);
//	pwm4_init(21);//M4	舵机4
//	delay(300);
//	pwm5_init(5);//M5  接舵机1  底座TIM_Puls值从5到26.其他值不行
	uart1_init(115200);
	my_NVIC_init();
	
	while(1)
	{
/*********************** 舵机初始化***********************************/
		
		pwm_init(18);//M8		舵机2
		delay(300);	
		pwm9_init(9);  // M9 舵机6 初始化
		delay(300);		
		pwm11_init(15);//M11  舵机5 初始化
		delay(300);
		pwm10_init(21);//M10 舵机3 初始化
		delay(300);
		pwm4_init(20);//M4	舵机4
	
		uart1_send_byte('h');
			
		delay(500);
		uart1_send_str("world");
		
/************************** 执行动作选择*****************************/
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

