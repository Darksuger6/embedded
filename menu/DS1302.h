#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Init();
void DS1302_WriteByte(unsigned char Command,Date);
unsigned char DS1302_ReadByte(unsigned Command);
unsigned char DS1302_Time[];
void DS1302_SetTime();
void DS1302_ReadTime();



#endif