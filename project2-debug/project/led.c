#include "stm32f10x.h"

//pa5
void led_init(void)
{
	//创建gpio对象
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//供电，使能GPA对应的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 
	
	//设置引脚工作方式，推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;  //选中管脚  PA5
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;  //设置输出速率
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //设置输出模式 推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //选择gpio  A口

}


void led_on(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_5);   // PA5 输出高电平
}
void led_off(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_5); //pa5输出低电平
}



