#include "stm32f10x.h"

//pa5
void led_init(void)
{
	//����gpio����
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//���磬ʹ��GPA��Ӧ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 
	
	//�������Ź�����ʽ���������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;  //ѡ�йܽ�  PA5
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;  //�����������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������ģʽ �������
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //ѡ��gpio  A��

}


void led_on(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_5);   // PA5 ����ߵ�ƽ
}
void led_off(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_5); //pa5����͵�ƽ
}



