#include <REGX52.H>


sbit IN21=P1^1;//???
sbit IN22=P1^2;

sbit IN23=P1^3;//???
sbit IN24=P1^4;

sbit ENA=P1^5;
sbit ENB=P1^6;

sbit leftlight=P0^2;
sbit rightlight=P0^3;
sbit midlight=P0^1;
void cargo()
{
					IN21=1;
					IN22=0;
					IN23=1;
					IN24=0;
//				if(leftlight == 0 && midlight==1&& rightlight == 0)
//				{	
//					IN21=1;
//					IN22=0;
//					IN23=1;
//					IN24=0;
//				}
//				if(leftlight == 1 && midlight==1&& rightlight == 1)
//				{
//					IN21=0;
//					IN22=0;
//					IN23=0;
//					IN24=0;
////		
//				}
//				if(leftlight == 0 && midlight==0&& rightlight == 0)
//				{	
//					IN21=1;
//					IN22=0;
//					IN23=1;
//					IN24=0;
//				}

				
//				if(leftlight == 1 && midlight==0&& rightlight == 0)
//				{	
//					IN21=1;
//					IN22=0;
//					IN23=0;
//					IN24=0;
//				}
}