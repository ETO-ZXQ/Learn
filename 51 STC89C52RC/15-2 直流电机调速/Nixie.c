#include <REGX52.H>
//#include "Delay.h"
unsigned char nixietable[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};


/**
  * @brief  数码管显示（动态一次）可修改为静态显示
  * @param  location 显示位置 1~8   num 显示数字 0~9
  * @retval 无
  */
void Nixie(unsigned char location,num)
{
	//Location
	switch(location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	//Number
	P0 =  nixietable[num];
	
	//静态显示将 下两行&"Delay.h"   注释掉

//	Delay(1);
//	P0 = 0x00;
}