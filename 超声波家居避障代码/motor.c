
#include <REGX52.H>

sbit IN11 = P1^1;//��ǰ
sbit IN12 = P1^2;
sbit IN13 = P1^3;//��ǰ
sbit IN14 = P1^4;

void LF_motor_go ()    //��ǰ�����ת
{IN11 = 1;IN12 = 0;}
void LF_motor_back ()  //��ǰ�����ת
{IN11 = 0;IN12 = 1;}
void LF_motor_stop ()  //��ǰ���ֹͣ
{IN11 = 1;IN12 = 1;}
void RF_motor_go ()    //��ǰ�����ת
{IN13 = 1;IN14 = 0;}
void RF_motor_back ()  //��ǰ�����ת
{IN13 = 0;IN14 = 1;}
void RF_motor_stop ()  //��ǰ���ֹͣ
{IN13 = 1;IN14 = 1;}




