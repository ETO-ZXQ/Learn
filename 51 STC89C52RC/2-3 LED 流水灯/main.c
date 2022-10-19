#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;
	while(ms)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		ms--;
	}
}

void main()
{
	while(1)
	{
		P2=0XFE;//1111 1110
		Delay(500);
		P2=0XFD;//1111 1101
		Delay(500);
		P2=0XFB;//1111 1011
		Delay(500);
		P2=0XF7;//1111 0111
		Delay(500);
		P2=0XEF;//1110 1111
		Delay(500);
		P2=0XDF;//1101 1111
		Delay(500);
		P2=0XBF;//1011 1111
		Delay(500);
		P2=0X7F;//0111 1111
		Delay(500);
	}
}