/*
通过矩阵键盘实现两个两位数的加法计算（不考虑负数），通过
数码管显示结果，当计算结果超出 177 时，所有 led 灯闪烁两次，
然后蜂鸣器响。
*/
#include <REGX52.H>
#include "Nixie.h"
#include "MatrixKey.h"
#include "Buzzer.h"
#include "Delay.h"


//s1~s9 数字1~9   s10 数字0   s11 确认


unsigned char num1,num2,sum = 0;
unsigned char d1,d2,d3 = 0;			//显示 d1第一位 d2第二位 d3 第三位			
unsigned char KeyNum = 0;
unsigned char flag = 0;				//流程标记	

void main()
{
	while(1)
	{
		Nixie(1,d1);
		Nixie(2,d2);
		Nixie(3,d3);
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			if(KeyNum==10) KeyNum = 0;
			
			switch (flag)
			{
				case 0:			//输入第一位数高位
					num1 = num1 + KeyNum*10;
					d2 = KeyNum;
					flag++;
					break;
				case 1:			//输入第一位数低位
					num1 = num1 + KeyNum;
					d3 = KeyNum;
					flag++;				
					break;
				case 2:			//确认
					d2 = 0;
					d3 = 0;
					flag++;
					break;
				case 3:			//输入第二位数高位
					num2 = num2 + KeyNum*10;
					d2 = KeyNum;
					flag++;				
					break;
				case 4:			//输入第二位数低位
					num1 = num1 + KeyNum;
					d3 = KeyNum;
					flag++;	
					break;
				case 5:			//确认 相加
					sum = num1 + num2;
					d1 = sum/100;
					d2 = sum%100/10;
					d3 = sum%10;
					if(sum>177)
					{	//闪两下
						P2 = 0x00;
						Delay(500);
						P2 = 0xFF;
						Delay(500);
						P2 = 0x00;
						Delay(500);
						P2 = 0xFF;
						Delay(500);
					
						Buzzer_Time(200);	//蜂鸣器鸣响
					}
					flag++;
					break;							
			}
		}
	}	
}
