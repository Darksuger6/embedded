#include <REGX52.H>


sbit IN21=P1^1;//右后轮
sbit IN22=P1^2;

sbit IN23=P1^3;//左后轮
sbit IN24=P1^4;

sbit ENA=P1^5;
sbit ENB=P1^6;

void carstop()
{
	IN21=0;
	IN22=0;
	IN23=0;
	IN24=0;
}