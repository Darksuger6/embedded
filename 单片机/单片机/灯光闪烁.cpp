#include<reg52.h>
sbit led1 = P2 ^ 1;
void  delay(int  i)
{
	while (i--);
}

void main()
{
	while (1)
	{
		led1 = 0;
		delay(5000);
		led1 = 1;
		delay(5000);
	}
}