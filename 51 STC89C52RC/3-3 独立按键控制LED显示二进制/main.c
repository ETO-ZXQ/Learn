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
	unsigned char LEDnum = 0; 

	while(1)
	{
		if(P3_1==0)
		{
			//按键抖动消除
			Delay(20);
			while(P3_1==0);
			Delay(20);
			

			
			LEDnum++;

			P2 = ~LEDnum;
		}
	}
}