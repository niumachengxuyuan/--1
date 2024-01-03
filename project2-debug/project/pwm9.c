#include "stm32f10x.h"
//舵机2
//void pwm9_init(void)
//{
// 
//	//GPIO
//  GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);
//    
//    //TIM
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
//	TIM_OCInitTypeDef TIM_OCInitStructure; 
//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
//    
//	//定期基础
//	TIM_TimeBaseStructure.TIM_Period = 200-1; //20ms周期=.01ms*200次
//	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1; //72000000/7200=10000hz分频；1/10000秒=0.1ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //不再内部分频
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
//	
//	//功能
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //
//	TIM_OCInitStructure.TIM_Pulse =26;  //翻转计数值
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //初始输出电平为高
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//输出使能
//	TIM_OC3Init(TIM4, &TIM_OCInitStructure);//第四根管脚输出：通道4（time4）
//	
//	
//	TIM_Cmd(TIM4, ENABLE); 	 //定时器使能
//}

void pwm9_init(int angle)
{
 
	//GPIO
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
    
    //TIM
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    
	//定期基础
	TIM_TimeBaseStructure.TIM_Period = 200-1; //20ms周期=.01ms*200次
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1; //72000000/7200=10000hz分频；1/10000秒=0.1ms
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //不再内部分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	//功能
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //
	TIM_OCInitStructure.TIM_Pulse =angle;  //翻转计数值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //初始输出电平为高
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//输出使能
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);//第四根管脚输出：通道3（time4）
	
	
	TIM_Cmd(TIM4, ENABLE); 	 //定时器使能
}



