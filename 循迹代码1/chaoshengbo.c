#include <REGX52.H>
#include "car.h"
#include "carstop.h"
#include <intrins.h>
sbit Trig = P2^1;   //��������෢���λ��
sbit Echo = P2^2;   //�����������ն�λ��

unsigned int sum;    //�����������
unsigned int mindistance = 20;  //С�����ϰ�������ƾ���

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void Delay20us()		//@11.0592MHz  ����ʱ20us��
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}
void chaoshengbo ()  //������������
{
	
//	T2MOD = 0;		//��ʼ��ģʽ�Ĵ���
//	T2CON = 0;		//��ʼ�����ƼĴ���
//	TL2 = 0;		//���ö�ʱ��ʼֵ
//	TH2 = 0;		//���ö�ʱ��ʼֵ
//	RCAP2L = 0;		//���ö�ʱ����ֵ
//	RCAP2H = 0;		//���ö�ʱ����ֵ

	TMOD = 0x11;		//���ö�ʱ��ģʽ
	TL1 = 0;		//���ö�ʱ��ʼֵ
	TH1 = 0;		//���ö�ʱ��ʼֵ

	
	Trig = 1;   //����һ�����壬����20us
	Delay20us();
	Trig = 0;
	
	while(!Echo);  //�ȴ�������ģ��ķ�������
	TR1 = 1;       //�򿪶�ʱ��
	while(Echo);   //�ȴ�������ģ�鷵���������
	TR1 = 0;       //ֹͣ��ʱ������ʱ����

	sum = ((TH1*256+TL1)*0.034)/2+1;  //�������
	
	if(mindistance > sum)
	{
		carstop();
		Delay1000ms();
	}
}
