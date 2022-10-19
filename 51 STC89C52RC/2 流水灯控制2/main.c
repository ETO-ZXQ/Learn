/*
实现流水灯从中间向两边依次点亮后再从两边向中间依次点 亮，
如此往复（并要求从中间向两边速度逐渐加快，从两边向中间速度逐
渐减慢）。并在灯闪烁途中按下一个按键，流水灯暂停，再次按下同一
按键，流水灯从刚才暂停的位置继续正常运行。
*/
#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "Key.h"
unsigned char a[] = {0x18,0x24,0x42,0x81};
unsigned char KeyNum = 0;
unsigned char mode = 0;		//流水灯模式
unsigned char flag = 0xFF;
unsigned char modeflag; 	//判断是中间往两边 还是 两边往中间
unsigned char time = 100;	//中断函数计时
void main()
{
	P2 = ~a[mode];
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum) flag = ~flag;//按位取反 非零是真
	}	

}
void Timer0_Rountine(void) interrupt 1
{
	static unsigned char T0count = 0;	//static修饰 本函数可重复使用，会一直存在，直到程序结束
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	
	
	if(flag)		//按下按键不计数 相当于暂停
	{	
		
		T0count++;
		if(T0count==time)
		{		
			
			if(mode==0) modeflag = 0;
			if(mode==3) modeflag = 1;
			
			
			
			if(modeflag==0)
				mode++;
			else
				mode--;
		
			time = 100 - mode*20;
			
			
			P2 = ~a[mode];
			
			T0count=0;
		}
	}
}