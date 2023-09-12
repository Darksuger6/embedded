#include"reg51.h"
sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;
int str[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07, 0x7f,0x6f };

void Delay(int time)
{
	while (time--)
	{
	}
}
void  Display(int Location, int Number)
{
	switch (Location)
	{
	case 1: LSC = 0; LSB = 0; LSA = 0; break;
	case 2: LSC = 0; LSB = 0; LSA = 1; break;
	case 3: LSC = 0; LSB = 1; LSA = 0; break;
	case 4: LSC = 0; LSB = 1; LSA = 1; break;
	case 5: LSC = 1; LSB = 0; LSA = 0; break;
	case 6: LSC = 1; LSB = 0; LSA = 1; break;
	case 7: LSC = 1; LSB = 1; LSA = 0; break;
	case 8: LSC = 1; LSB = 1; LSA = 1; break;
	}
	P0 = str[Number];
	Delay(100);
	P0 = 0x00;
}
int main()
{
	while (1)
	{
		Display(1, 4);
		Display(2, 1);
		Display(3, 3);
		Display(4, 1);
		Display(5, 0);
		Display(6, 2);
		Display(7, 5);

	}
}
