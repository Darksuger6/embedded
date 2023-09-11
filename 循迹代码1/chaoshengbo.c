#include <REGX52.H>
#include "car.h"
#include "carstop.h"
#include <intrins.h>
sbit Trig = P2^1;   //超声波测距发射端位点
sbit Echo = P2^2;   //超声波测距接收端位点

unsigned int sum;    //超声波测距结果
unsigned int mindistance = 20;  //小车与障碍物的限制距离

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


void Delay20us()		//@11.0592MHz  （延时20us）
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}
void chaoshengbo ()  //超声波测距程序
{
	
//	T2MOD = 0;		//初始化模式寄存器
//	T2CON = 0;		//初始化控制寄存器
//	TL2 = 0;		//设置定时初始值
//	TH2 = 0;		//设置定时初始值
//	RCAP2L = 0;		//设置定时重载值
//	RCAP2H = 0;		//设置定时重载值

	TMOD = 0x11;		//设置定时器模式
	TL1 = 0;		//设置定时初始值
	TH1 = 0;		//设置定时初始值

	
	Trig = 1;   //发射一段脉冲，至少20us
	Delay20us();
	Trig = 0;
	
	while(!Echo);  //等待超声波模块的返回脉冲
	TR1 = 1;       //打开定时器
	while(Echo);   //等待超声波模块返回脉冲结束
	TR1 = 0;       //停止定时器，计时结束

	sum = ((TH1*256+TL1)*0.034)/2+1;  //计算距离
	
	if(mindistance > sum)
	{
		carstop();
		Delay1000ms();
	}
}
