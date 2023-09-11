#include <REGX52.H>
#include "0.h"
#include "1.h"


char Counterright, Speedright, Counterleft, Speedleft;
sbit leftlight=P0^2;
sbit rightlight=P0^3;
sbit midlight=P0^1;

sbit IN21=P1^1;//???
sbit IN22=P1^2;

sbit IN23=P1^3;//???
sbit IN24=P1^4;

sbit ENA=P1^5;
sbit ENB=P1^6;


void chasu()
{
			

	        while(1)
			{
				if(leftlight == 1 && midlight==1 && rightlight == 1 )
				{
					Speedleft = 0;
					Speedright = 0;
		
				}
				if(leftlight == 0 && midlight == 0&& rightlight == 0 )
				{	
					Speedleft = 60;
					Speedright = 80;
	
				}
				if(leftlight == 0 && midlight == 0 && rightlight == 1)
				{	
					Speedleft = 60;
					Speedright = 30;
					
				}
				
				if(leftlight == 1 && midlight == 0  && rightlight == 0)
				{	
					Speedleft = 20;
					Speedright =100;
				}
			}
		
}


void Timer1_Routine() interrupt 3
{
	TL1 = 0xA4;		
	TH1 = 0xFF;		
//	speedright = 85;
	Counterright++;	//
	if (Counterright < Speedright)	
	{
		ENA=1;
		ENB=1;
		IN23=1;
		IN24=0;
	}
	else				
	{
		ENA=0;		
		ENB=0;
	}
	if(Counterright==100)
	{
		Counterright=0;
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;		
	TH0 = 0xFF;		
//	speedleft = 75;
	Counterleft++;	
	if (Counterleft < Speedleft)	
	{
		ENA=1;
		ENB=1;
		IN21=1;
		IN22=0;
	}
	else				
	{
		ENA=0;		
		ENB=0;
	}
	if(Counterleft==100)
	{
		Counterleft=0;
	}
}




