#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec = 0,Min = 0,Hour = 0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Clock");
	Timer0_Init();
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);		
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
		Sec++;
		if(Sec==60)
		{
			Min++;
			Sec = 0;
			if(Min==60)
			{
				Hour++;
				Min = 0;
				if(Hour==24)
					Hour = 0;
			}
		}
	}
}