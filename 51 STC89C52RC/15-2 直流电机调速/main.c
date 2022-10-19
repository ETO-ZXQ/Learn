#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"


unsigned char speed,KeyNum = 0;
unsigned char compare = 0;

void Timer0_Init(void)		//1毫秒 @11.0592MHz 误差0.04%
{

	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1;
	EA = 1;			//总中断
	PT0 = 0;
}

void main()
{
	Timer0_Init();
//	P1_0 = 0;

	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			speed++;
			speed%=4;
			if(speed==0){compare=0;}	//速度控制
			if(speed==1){compare=4;}
			if(speed==2){compare=8;}
			if(speed==3){compare=10;}
		}
		Nixie(1,speed);		
	}	
}

void Timer0_Rountine(void) interrupt 1
{
	static unsigned char T0count = 0;	//static修饰 本函数可重复使用，会一直存在，直到程序结束
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0count++;
	T0count%=10;	//如果等于10 归零   约为100Hz
	
	P1_0 = 0;
	
	if(T0count<compare)
		P1_0 = 1;
	else
		P1_0 = 0;
}
