//动态数码管显示（直接扫描方式）
#include <REGX52.H>
#include "Nixie.h"
void main ()
{
	while(1)
	{	
		Nixie(1,1);
		Nixie(2,9);
		Nixie(3,6);		
		Nixie(4,9);

	}
}