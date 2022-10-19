#include <REGX52.H>
#include "Timer0.h"
#include <INTRINS.h>
#include "Key.h"
unsigned char KeyNum;
unsigned char LEDMode = 1;
void main()
{
	Timer0_Init();//定时器初始化

	P2 = 0xFE;
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			if(KeyNum==1) LEDMode = 0;
			if(KeyNum==2) LEDMode = 1;
		}
	}	
}

void Timer0_Rountine(void) interrupt 1
{
	static unsigned char T0count = 0;	//static修饰 本函数可重复使用，会一直存在，直到程序结束
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	T0count++;
	
	if(T0count==100)	//计时1s
	{
		T0count=0;
		if(LEDMode == 0) 
			P2 = _cror_(P2,1);//右移 高位到低位
		else
			P2 = _crol_(P2,1);//左移 低位到高位
	}
}