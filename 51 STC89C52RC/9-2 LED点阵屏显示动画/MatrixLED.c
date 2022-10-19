#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT	P0

//<REGX52.H> 中 相关定义不符

sbit RCK=P3^5;		//RCLK
sbit SCK=P3^6;		//SRCLK
sbit SER=P3^4;		//SER
/**
  * @brief 点阵屏初始化 
  * @param  无
  * @retval 无
  */
void MatrixLED_Inint(void)
{
	SCK=0;
	RCK=0;
}
	

/**
  * @brief  74HC595写入一个字节
  * @param  Byte要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER = Byte&(0x80>>i);	//取出 Byte 每一位 用0&屏蔽其它位 用1&取出每一位 SER 对八位数据非零为1
		SCK = 1;				//向下移一位
		SCK = 0;				//复位
	}
	RCK = 1;	//输出数据
	RCK = 0;	//复位
}
/**
  * @brief  LED点阵屏显示一列数据
  * @param  Column 要选择的列，范围1~8 1在最左边  
  * @param  Data 选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	Column = Column - 1;
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80>>Column);//控制列
	Delay(1);					//延迟
	MATRIX_LED_PORT = 0xFF;		//消影
}
