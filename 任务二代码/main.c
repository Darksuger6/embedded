#include <REGX52.H>
#include "car.h"
#include "cargo.h"
#include "chaoshengbo.h"
#include "Delay.h"



void main ()
{	 	

		car();		
		chaoshengbo();

}	
		
//		IN21=1;
//		IN22=0;
//		IN23=1;
//		IN24=0;
//	
//	
//		Timer0_Init();	
//		Timer1_Init();	
//		
//		TMOD = 0x11;
//		TL1=0;
//		TH1=0;
//	
//		Trig=1;
//		Delay(20);
//		Trig=0;
//		
//		while(!Echo);
//		TR1=1;
//		while(Echo);
//		TR1=0;
//		result=((TH1*256+TL1)*0.034)/2+1;
//	
//		if(instance>result)
//		{
//			Speedleft = 0;
//			Speedright = 0;
//			Delay(1000);
//		}
//		else
//		{	
//				while(1)
//				{
//				if(leftlight == 1 && rightlight == 1 )
//				{
//					Speedleft = 0;
////					Speedright = 0;
//				}
//				if(leftlight == 0 && rightlight == 0 )
//				{	
//					Speedleft = 100;
////					Speedright = 100;
//				}
//				if(leftlight == 0 && rightlight == 1)
//				{	
//					Speedleft = 100;
////					Speedright = 50;
//					
//				}
//				if(leftlight == 1 && rightlight == 0)
//				{	
//					Speedleft = 50;
////					Speedright = 100;
//				}
//				}
//		




//void Timer1_Routine() interrupt 3
//{
//	TL1 = 0xA4;		
//	TH1 = 0xFF;		
//	Counterright++;	//
//	if (Counterright < Speedright)	
//	{
//		ENA=1;
//		ENB=1;
//		IN23=1;
//		IN24=0;
//	}
//	else				
//	{
//		ENA=0;		
//		ENB=0;
//	}
//	if(Counterright==100)
//	{
//		Counterright=0;
//	}
//}


//void Timer0_Routine() interrupt 1
//{
//	TL0 = 0xA4;		
//	TH0 = 0xFF;		
//	Counterleft++;	
//	if (Counterleft < Speedleft)	
//	{
//		ENA=1;
//		ENB=1;
//		IN21=1;
//		IN22=0;
//	}
//	else				
//	{
//		ENA=0;		
//		ENB=0;
//	}
//	if(Counterleft==100)
//	{
//		Counterleft=0;
//	}
//}
