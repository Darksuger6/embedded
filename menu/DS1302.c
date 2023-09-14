#include <REGX52.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
#define DS1302_Year       	    0x8C    
#define DS1302_Month     	    0x88    
#define DS1302_Date       	    0x86     
#define DS1302_Hour          	0x84    
#define DS1302_Minutes          0x82   
#define DS1302_Second           0x80
#define DS1302_WP				0x8E
unsigned char DS1302_Time[]={22,6,1,21,15,50};
void DS1302_Init()
{
	DS1302_SCLK=0;
	DS1302_CE=0;	
}
void DS1302_WriteByte(unsigned char Command,Data)
{	unsigned char i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;

}
unsigned char DS1302_ReadByte(unsigned Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{	DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}
void DS1302_SetTime()
{
	DS1302_WriteByte(DS1302_WP,0x00);
	DS1302_WriteByte(DS1302_Year,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_Month,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_Date,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_Hour,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_Minutes,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_Second,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
}
void DS1302_ReadTime()
{
	unsigned char Temp;
	
	Temp=DS1302_ReadByte(DS1302_Year);
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_Month);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_Date);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_Hour);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_Minutes);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_Second);
	DS1302_Time[5]=Temp/16*10+Temp%16;
}













