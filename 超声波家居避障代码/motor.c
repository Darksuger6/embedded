
#include <REGX52.H>

sbit IN11 = P1^1;//左前
sbit IN12 = P1^2;
sbit IN13 = P1^3;//右前
sbit IN14 = P1^4;

void LF_motor_go ()    //左前电机正转
{IN11 = 1;IN12 = 0;}
void LF_motor_back ()  //左前电机反转
{IN11 = 0;IN12 = 1;}
void LF_motor_stop ()  //左前电机停止
{IN11 = 1;IN12 = 1;}
void RF_motor_go ()    //右前电机正转
{IN13 = 1;IN14 = 0;}
void RF_motor_back ()  //右前电机反转
{IN13 = 0;IN14 = 1;}
void RF_motor_stop ()  //右前电机停止
{IN13 = 1;IN14 = 1;}




