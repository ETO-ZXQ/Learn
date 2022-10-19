#include <REGX52.H>

#include <INTRINS.H>
//消除按键抖动
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
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);//空语句
			Delay(20);
			P2_0 = ~P2_0; 
		}
	}
}