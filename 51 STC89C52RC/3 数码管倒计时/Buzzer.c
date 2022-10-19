#include <REGX52.H>
#include <INTRINS.H>
//蜂鸣器端口
sbit Buzzer = P2^5;
/**
  * @brief  蜂鸣器私有延时函数，延时500us
  * @param  无
  * @retval 无
  */
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}


/**
  * @brief  蜂鸣器发声
  * @param  ms 发声时长
  * @retval 无
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	ms = ms * 2;
	for(i=0;i<ms;i++)
	{	//1000Hz
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
