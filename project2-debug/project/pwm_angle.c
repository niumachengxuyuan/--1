#include "stm32f10x.h"
//���1

void pwm_angle(int i)
{
	int n=i+15;
	for(int j=15;j<n+1;j++)
	{
		TIM_SetCompare4(TIM4,j);
		delay(1500);
	};
}


//���2

void pwm9_angle(int i)
{
	int n=i+26;
	for(int j=26;j<n+1;j++)
	{
		TIM_SetCompare3(TIM4,j);
		delay(1000);
	};
}

//���3


//���6

void pwm5_angle(int i)
{
	int n=i+15;
	for(int j=15;j<n+1;j++)
	{
		TIM_SetCompare3(TIM3,j);
		delay(1000);
	};
}
