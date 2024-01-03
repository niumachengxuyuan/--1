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

/**********************************************动作1**************************/	

void  maeching_action1()
{

		int i=0;		
		pwm4_init(19);//M4	舵机4
		delay(1000);
		pwm_init(19);//M8		舵机2
		delay(2000);
		
		pwm9_init(15);  //舵机6  夹子刚好闭合
		delay(2000);
//夹上货物，舵机4上升两个度，舵机3到初始位，舵机4到初始位	
		pwm10_init(18);//舵机3
		delay(500);
		pwm4_init(18);
		delay(500);
/**************上升结束。开始旋转	**************/
		for(i=6;i<=9;i++)
		{
			pwm5_init(i);
			delay(200);	
		}
/****************旋转到位，夹子放下	*******************/
		pwm4_init(19);
		delay(500);
		pwm4_init(20);
		delay(500);	
		pwm4_init(21);
		delay(500);	
		pwm9_init(10);  //舵机6 张开
		delay(1000);
		pwm4_init(18);
		
/****************放置货物结束，回到初始位置	*******************/
		for( i=9;i>=5;i--)
		{
			pwm5_init(i);
			delay(200);
		}
		delay(200);
		pwm4_init(19);
		pwm_init(18);//M8		舵机2
		delay(300);	
		pwm9_init(9);  // M9 舵机6 初始化
		delay(300);		
		pwm11_init(15);//M11  舵机5 初始化
		delay(300);
		pwm10_init(21);//M10 舵机3 初始化
		delay(300);
		pwm4_init(21);//M4	舵机4
	
}
