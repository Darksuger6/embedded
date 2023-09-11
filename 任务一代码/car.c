#include <REGX52.H>
#include "Delay.h"


sbit leftlight=P0^2;
sbit rightlight=P0^3;
sbit midlight=P0^1;

sbit ENA=P1^5;
sbit ENB=P1^6;

sbit IN21=P1^1;//右后轮
sbit IN22=P1^2;

sbit IN23=P1^3;//左后轮
sbit IN24=P1^4;

//unsigned char counter1,speed;	//¼ÆÊýÖµºÍ±È½ÏÖµ£¬ÓÃÓÚÊä³öPWM

//void Timer0_Init()		//100Î¢Ãë@11.0592MHz
//{
//	TMOD = 0x11;	//ÉèÖÃ¶¨Ê±Æ÷Ä£Ê½
//	TL0 = 0xA4;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
//	TH0 = 0xFF;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
//	TF0 = 0;			//Çå³ýTF0±êÖ¾
//	TR0 = 1;			//¶¨Ê±Æ÷0¿ªÊ¼¼ÆÊ±
//	ET0 = 1;      //¶¨Ê±Æ÷0µÄÖÐ¶ËÔÊÐí¿ª¹Ø
//	EA  = 1;      //¶¨Ê±Æ÷×Ü¿ª¹Ø
//	PT0 = 1;      //ÉèÖÃ¶¨Ê±Æ÷Îª¸ßµÍ¿ØÖÆÓÅÏÈ¼¶£¬1Îª¸ßÓÅÏÈ¼¶£¬0ÎªµÍÓÅÏÈ¼¶
//}
//void Timer0_Routine() interrupt 1  //ÖÐ¶Ïº¯Êý
//{

//	TL0 = 0xA4;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
//	TH0 = 0xFF;		//ÉèÖÃ¶¨Ê±³õÊ¼Öµ
//	
//	counter1++;
//	if (counter1 >= 100)
//	{
//		counter1 = 0;
//	}
//	if (counter1 < speed)
//	{
//		ENA = 1;
//		ENB = 1;

//	}
//	else
//	{
//		ENA = 0;
//		ENB = 0;

//	}
//}


			void car()
			{
				if(leftlight == 1 && midlight==1&& rightlight == 1)
				{
					
					IN21=0;
					IN22=0;
					IN23=0;
					IN24=0;
				}
				if(leftlight == 0 && midlight==0&& rightlight == 0)
				{	
					IN21=1;
					IN22=0;
					IN23=1;
					IN24=0;
				}
				if(leftlight == 0 && midlight==0&& rightlight == 1)
				{	
					
					IN21=1;
					IN22=0;
					IN23=0;
					IN24=1;
					
				}
		    	if(leftlight == 1 && midlight==0&& rightlight == 0)
				{	
							
							IN21=0;
							IN22=1;
							IN23=1;
							IN24=0;
				}
				if(leftlight == 0 && midlight==1&& rightlight == 0)
				{
					IN21=1;
					IN22=0;
					IN23=1;
					IN24=0;
				}
				if(leftlight == 1 && midlight==0&& rightlight == 1)
				{	
					IN21=1;
					IN22=0;
					IN23=1;
					IN24=0;
				}
			
			}
