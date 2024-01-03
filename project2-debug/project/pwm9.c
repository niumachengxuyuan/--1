#include "stm32f10x.h"
//���2
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
//	//���ڻ���
//	TIM_TimeBaseStructure.TIM_Period = 200-1; //20ms����=.01ms*200��
//	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1; //72000000/7200=10000hz��Ƶ��1/10000��=0.1ms
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //�����ڲ���Ƶ
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
//	
//	//����
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //
//	TIM_OCInitStructure.TIM_Pulse =26;  //��ת����ֵ
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //��ʼ�����ƽΪ��
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//���ʹ��
//	TIM_OC3Init(TIM4, &TIM_OCInitStructure);//���ĸ��ܽ������ͨ��4��time4��
//	
//	
//	TIM_Cmd(TIM4, ENABLE); 	 //��ʱ��ʹ��
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
    
	//���ڻ���
	TIM_TimeBaseStructure.TIM_Period = 200-1; //20ms����=.01ms*200��
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1; //72000000/7200=10000hz��Ƶ��1/10000��=0.1ms
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //�����ڲ���Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	//����
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //
	TIM_OCInitStructure.TIM_Pulse =angle;  //��ת����ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //��ʼ�����ƽΪ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//���ʹ��
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);//���ĸ��ܽ������ͨ��3��time4��
	
	
	TIM_Cmd(TIM4, ENABLE); 	 //��ʱ��ʹ��
}



