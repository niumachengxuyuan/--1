#include "stm32f10x.h"
//¶æ»ú1

void pwm_angle(int i)
{
	int n=i+15;
	for(int j=15;j<n+1;j++)
	{
		TIM_SetCompare4(TIM4,j);
		delay(500);
	};
}