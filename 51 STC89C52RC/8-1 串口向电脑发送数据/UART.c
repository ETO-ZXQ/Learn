#include <REGX52.H>

/**
  * @brief  串口初始化
  * @param  无
  * @retval 无
  */

void UART_Init(void)		//9600bps @11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率 REN = 1 以允许串口接收

	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	//不需要中断 置0
	EA = 1;			//开启总中断
	ES = 1;			//开启串口中断
					//优先级默认 0
}


/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI==0); //等发送完毕 TI 变为 1 会进串口中断
	TI = 0;
}

//串口中断函数模板
/*
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
*/


