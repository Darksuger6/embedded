#include <REGX52.H>

//#include "Delay.h"
#include "carstop.h"

sbit Trig=P2^1; 
sbit Echo=P2^2;

unsigned int result;
unsigned int instance=20;
void Timer1_Init(void)
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x00;		//设置定时初值
	TH1 = 0x00;		//设置定时初值
	TF1 = 0;		//清除TF0标志
	TR1 = 0;		//定时器0开始计时
	ET1=1;
	EA=1;
	PT1=0;
}
	

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

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

	
void Delay20us()		//@11.0592MHz
{
	unsigned char i;


	i = 6;
	while (--i);
}


	
	void chaoshengbo ()  //³¬Éù²¨²â¾à³ÌÐò
{
	T1MOD = 0;		//³õÊ¼»¯Ä£Ê½¼Ä´æÆ÷
	T2CON = 0;		//³õÊ¼»¯¿ØÖÆ¼Ä´æÆ÷
	TL2 = 0;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
	TH2 = 0;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
	RCAP2L = 0;		//ÉèÖÃ¶¨Ê±ÖØÔØÖµ
	RCAP2H = 0;		//ÉèÖÃ¶¨Ê±ÖØÔØÖµ
		
	Trig = 1;   //·¢ÉäÒ»¶ÎÂö³å£¬ÖÁÉÙ20us
	Delay20us();
	Trig = 0;
	
	while(!Echo);  //µÈ´ý³¬Éù²¨Ä£¿éµÄ·µ»ØÂö³å
	TR2 = 1;       //´ò¿ª¶¨Ê±Æ÷
	while(Echo);   //µÈ´ý³¬Éù²¨Ä£¿é·µ»ØÂö³å½áÊø
	TR2 = 0;       //Í£Ö¹¶¨Ê±Æ÷£¬¼ÆÊ±½áÊø

	result = ((TH2*256+TL2)*0.034)/2+1;  //¼ÆËã¾àÀë

	
		if(instance>result)
		{
			cargo();
			Delay1000ms();
		}
	}	