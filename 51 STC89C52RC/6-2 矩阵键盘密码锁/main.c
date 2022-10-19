#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"
/*
	s1~S9 数字 1~9
	s10   数字 0
	s11   确认
	s12   取消
*/
#define MIMA 2002

unsigned char KeyNum = 0;
unsigned char Count = 0;//输入次数
unsigned int Password = 0;
void main()
{

	
	LCD_Init();
	LCD_ShowString(1,1,"Password");
	LCD_ShowNum(2,1,Password,4);
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)
			{
				if(Count<4)
				{
					Password*=10;
					if(KeyNum<=9) Password += KeyNum; //前面数字往高位移					
					LCD_ShowNum(2,1,Password,4);//显示更新
					Count++;				
					if(Count==1) LCD_ShowString(1,14,"   "); //将上一次的结果显示消除
				}
			}

			if(KeyNum==11) //确认
			{
				if(Password==MIMA)
					LCD_ShowString(1,14,"OK!");
				else
					LCD_ShowString(1,14,"ERR");
				Password = 0;//清零
				Count = 0;
				LCD_ShowNum(2,1,Password,4);
			}
			if(KeyNum==12) //取消
			{
				Password = 0;//清零
				Count = 0;
				LCD_ShowNum(2,1,Password,4);
			
			}
		}
	
	
	}

}
