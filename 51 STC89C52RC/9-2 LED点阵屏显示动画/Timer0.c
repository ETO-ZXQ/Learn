#include <REGX52.H>

void Timer0_Init(void)		//10毫秒 @11.0592MHz
{
	//使用与，或运算 在不影响定时器1情况下 配置定时器0模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式

	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	EA = 1; 		//CPU总中断允许控制位
	ET0 = 1;		//T0溢出中断允许位
	PT0 = 1;		//定时器0 优先级1
}

/* 定时器函数模板 1s

void Timer0_Rountine(void) interrupt 1
{
	static unsigned char T0count = 0;	//static修饰 本函数可重复使用，会一直存在，直到程序结束
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	T0count++;
	if(T0count==100)	//计时1s
	{
		T0count=0;
	
	}
}

*/
