/*
通过两个按键控制流水灯分别以 500ms、1s 的速度闪烁，要求从
左到右再从右到左并且跳跃式点亮（也就是第一个亮后第三个亮，以
此类推），如此反复。
*/
#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "Key.h"
unsigned char KeyNum = 0;
unsigned char mode = 1;		//流水灯模式 控制亮灭
unsigned char Num = 1;		//第几个亮
unsigned char modeflag; 	//判断是从左往右 还是 从右往左
unsigned int time = 50;		//计时 默认 500ms
void main()
{
	P2 = ~0x01;
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum) time = KeyNum*50;
	}	

}
void Timer0_Rountine(void) interrupt 1
{
	static unsigned char T0count = 0;	//static修饰 本函数可重复使用，会一直存在，直到程序结束
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	T0count++;
	
	if(T0count==time)	//计时 K1 500ms K2 1s
	{		
								
		if(mode)				//之前 亮
		{
			if(Num==1) modeflag = 0;
			if(Num==7) modeflag = 1;

			if(modeflag==0)		//从左往右
				Num = Num+2;
			else
				Num = Num-2;

			P2 = ~0x00;
			
			mode = 0;
		}
		else					//之前 灭
		{
		
			P2 = ~(0x01<<(Num-1));
		
			mode = 1;
		}
						
		T0count=0;
	}

}