
#include <REGX52.H>
#include "car.h"
#include <intrins.h>


sbit Trig = P2^1;   
sbit Echo = P2^2;   
sbit PWM = P2^0; 

unsigned int sum,distance1,distance2,distance3;    
unsigned char counter2,angle;
unsigned int mindistance = 20;  

void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

void Delay400ms()		//@11.0592MHz  （延时400ms）
{
	unsigned char i, j, k;

	_nop_();
	i = 3;
	j = 206;
	k = 43;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Timer1_Init()		//500微秒@11.0592MHz
{
	TMOD = 0x11;		//设置定时器模式

	TL1 = 0x33;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值

	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;      //定时器0的中端允许开关
	EA  = 1;      //定时器总开关
	PT1 = 1;      //设置定时器为高低控制优先级，1为高优先级，0为低优先级
}



void Timer1_Routine() interrupt 3  //中断函数
{
	TL1 = 0x33;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值
	counter2++;
	if (counter2 >= 40)
	{
		counter2 = 0;
	}
	if (counter2 < angle)
	{
		PWM = 1;
	}
	else
	{
		PWM = 0;
	}
}
void Delay20us()		//@11.0592MHz  （延时20us）
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}
void chaoshengbo () 
{
	T2MOD = 0;		
	T2CON = 0;		
	TL2 = 0;		
	TH2 = 0;		
	RCAP2L = 0;		
	RCAP2H = 0;		
		
	Trig = 1;   
	Delay20us();
	Trig = 0;
	
	while(!Echo); 
	TR2 = 1;       
	while(Echo);  
	TR2 = 0;      

	sum = ((TH2*256+TL2)*0.034)/2+1;  //计算距离
}


void control0 ()  //舵机归中程序
{
	counter2 = 0;
	angle = 3;  //舵机归中
	Delay400ms();
}
void control ()  //舵机旋转程序
{
	counter2 = 0;
	angle = 2;
	Delay400ms();
	chaoshengbo ();
	distance1 = sum;
	counter2 = 0;
	angle = 4;
	Delay400ms();
	counter2 = 0;
	angle = 3;  //舵机归中
	Delay400ms();
	chaoshengbo ();
	distance2 = sum;
}

void system ()
{	
	car_go();
	chaoshengbo ();
	distance3 = sum;
	if(distance3 < mindistance)
	{
		car_stop ();
		Delay400ms();
		control ();
		if(distance1 < distance2)
		{
			car_leftstop ();  //小车原地左拐
			Delay400ms();
			car_stop();
			Delay100ms();
			car_go ();
		}
		if(distance2 < distance1)
		{
			car_rightstop (); //小车原地右拐
			Delay400ms();
			car_stop();
			Delay100ms();
			car_go ();
		}
		if(distance2 == distance1)
		{
			car_back (); //小车原地右拐
			Delay400ms();
			car_rightstop();
			Delay400ms();
			car_go ();
		}
	}
	else
	{car_go();}
	
}

