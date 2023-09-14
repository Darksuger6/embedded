#include <REGX52.H>
#include "Key.H"
#include "LCD1602.H"
extern KeyNumber;
unsigned char KeyNum,MODE,arrowSetSelect,arrowSetFlashFlag,Column;

void menu()
{
	LCD_ShowString(1,1,"Menu:");
	LCD_ShowString(2,2,"app1");
	LCD_ShowString(2,7,"app2");
	LCD_ShowString(2,12,"app3");
}

void arrowSet()
{
	LCD_ShowString(2,Column+1,">");
	
}

void main()
{
	LCD_Init();
	while(1)
	{
		menu();
		arrowSet();
		KeyNum=Key();//????
		if(KeyNum==2)//??2??
		{
			LCD_Init();
			Column+=5;//??????1
			Column%=15;//????
		}
		if(KeyNum==1)//??2??
		{
			LCD_Init();
			Column-=5;//??????1
			Column%=-15;//????
		}
		if(KeyNum==4)//??1??
		{
			if(MODE==0){MODE=1;arrowSetSelect=0;}//????
			
		}
		if(KeyNum==3)//??1??
		{
			if(MODE==1){MODE=0;arrowSet();}
		}
		switch(MODE)//??????????????
		{
			case 0:menu();break;
			case 1:arrowSet();break;
		}
	}
		
}