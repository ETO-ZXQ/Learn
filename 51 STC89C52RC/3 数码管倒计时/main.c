/*
利用数码管制作一个60秒的倒计时，单片机通电倒计时开始，每倒
计时10s，蜂鸣器响一下，倒计时结束前可通过三个独立按键进行控制，
其中按下第一个按键，倒计时暂停，按下第二个按键，倒计时继续，
按下第三个按键，倒计时回到60重新开始，其中蜂鸣器发出响声要求
在定时器中断中实现。
*/
#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

//K1 开启 K2 暂停 K3 复位
unsigned char time = 60;
unsigned char num1 = 6,num2 = 0;	//数码管显示的数字
unsigned char KeyNum = 0;
unsigned char flag = 1;		//计时器状态 0关闭 1开启 3复位

unsigned char T0count = 0;	//定时器计数

void reset (void)
{
	T0count = 0;
	time = 60;
	num1 = 6;
	num2 = 0;
	flag = 0;
}

void main()
{
	Timer0_Init();

	
	while(1)
	{
		Nixie(1,num1);
		Nixie(2,num2);
		KeyNum = Key();
		
		switch (KeyNum)
		{
			case 1: flag = 1; 	break;
			case 2: flag = 0; 	break;
			case 3: flag = 3; 	break;
			default:			break;
		}			
		
	}	
}

void Timer0_Rountine(void) interrupt 1
{

	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	

	
	if(flag)
	{
		
		T0count++;
		
		if(flag==3) reset();
		
		
		if(T0count==100)	//计时1s
		{
			time--;
			num1 = time/10;
			num2 = time%10;
			
			T0count=0;
			
			if(num2==0)
			{
				Buzzer_Time(10);
				T0count=1;				//弥补误差								
				if(time==0) 			//结束暂停
				{
					Buzzer_Time(50);
					reset();
				}

			}
		
		
		}
		
	}
}