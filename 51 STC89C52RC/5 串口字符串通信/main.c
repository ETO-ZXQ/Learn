/*
通过串口助手向 51 发送一个任意长度的字符串，然后再将该
字符串逆序并在字符之间插入“@”，返回到串口助手。
例如发送“Electrical ”，返回“l@a@c@i@r@t@c@e@l@E”。
*/

#include <REGX52.H>
#include "UART.h"

unsigned char string[50];
unsigned char count = 0;	//接收计数
unsigned char flag = 0;		//接受完毕标志

void main()
{
	UART_Init();


	while(1)
	{	
		if(flag)
		{
			while(count)			//count = 0 发送结束
			{
				UART_SendByte(string[count-1]);
				
				count--;
				
				if(count!=0) UART_SendByte('@');
			}
			flag = 0;
		}	
				
	}	
}

void UART_Routine(void) interrupt 4
{
	if(RI==1)
	{
		string[count] = SBUF;
		count++;
		RI = 0;//接收中断复位
		
		if(SBUF=='\n')			//字符串结尾软件自动添加 '\0' 					
		{						//发送完整为 ‘*’ ‘*’ ‘*’ ... ‘\0’ ‘\n’
			count = count - 2;
			flag = 1;
		}
	
	}
	else
	{
		
		
		//发送中断内容
	}
}