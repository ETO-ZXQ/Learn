#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
unsigned char Sec = 0;


void main()
{
	UART_Init();
	
	while(1)
	{
		UART_SendByte(Sec);
		Sec++;
		Delay(1000);
	}	
}


void UART_Routine(void) interrupt 4
{
	if(RI==1)
	{
		


		RI = 0;//接收中断复位
	}
	else
	{
		//发送中断内容
		

	}
}