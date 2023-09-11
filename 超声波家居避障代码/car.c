
#include <REGX52.H>
#include "motor.h"

sbit EN1A = P1^5;//��ǰ
sbit EN1B = P1^6;//��ǰ

unsigned char counter1,speed;	//����ֵ�ͱȽ�ֵ���������PWM

void Timer0_Init()		//100΢��@11.0592MHz
{
	TMOD = 0x11;	//���ö�ʱ��ģʽ
	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	TF0 = 0;			//���TF0��־
	TR0 = 1;			//��ʱ��0��ʼ��ʱ
	ET0 = 1;      //��ʱ��0���ж�������
	EA  = 1;      //��ʱ���ܿ���
	PT0 = 1;      //���ö�ʱ��Ϊ�ߵͿ������ȼ���1Ϊ�����ȼ���0Ϊ�����ȼ�
}
void Timer0_Routine() interrupt 1  //�жϺ���
{

	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	
	counter1++;
	if (counter1 >= 100)
	{
		counter1 = 0;
	}
	if (counter1 < speed)
	{
		EN1A = 1;
		EN1B = 1;

	}
	else
	{
		EN1A = 0;
		EN1B = 0;

	}
}
void car_go ()        //С����ǰֱ��
{
	speed = 90;
	LF_motor_go ();
	RF_motor_go ();

}
void car_back ()      //С�����ֱ��
{
	speed = 90;
	LF_motor_back ();
	RF_motor_back ();

}
void car_stop ()      //С��ֹͣ
{
	speed = 0;
	RF_motor_stop ();
	LF_motor_stop ();
}
void car_leftgo ()    //С����ǰ���
{
	speed = 16;
	RF_motor_go ();
	LF_motor_stop ();

}
void car_rightgo ()   //С����ǰ�ҹ�
{
	speed = 16;
	LF_motor_go ();
	RF_motor_stop ();

}
void car_leftback ()  //С��������
{
	speed = 16;
	RF_motor_back ();
	LF_motor_stop ();

}
void car_rightback () //С������ҹ�	
{
	speed = 16;
	LF_motor_back ();
	RF_motor_stop ();

}
void car_rightstop () //С��ԭ���ҹ�
{
	speed = 90;
	LF_motor_go ();
	RF_motor_back ();

}
void car_leftstop () //С��ԭ�����
{
	speed = 90;
	LF_motor_back ();
	RF_motor_go ();

}