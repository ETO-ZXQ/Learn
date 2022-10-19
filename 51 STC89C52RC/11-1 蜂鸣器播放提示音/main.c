#include <REGX52.H>
#include "Buzzer.h"
#include "Nixie.h"
#include "Key.h"

unsigned char KeyNum = 0;

void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			Buzzer_Time(50);
			Nixie(1,KeyNum);
		}
	}	
}
