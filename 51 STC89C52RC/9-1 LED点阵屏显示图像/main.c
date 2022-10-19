#include <REGX52.H>
#include "MatrixLED.h"
void main()
{
	MatrixLED_Inint();
	while(1)
	{	// 爱心 0x38,0x44,0x42,0x21,0x42,0x44,0x38,0x00,
		MatrixLED_ShowColumn(1,0x38);
		MatrixLED_ShowColumn(2,0x44);
		MatrixLED_ShowColumn(3,0x42);
		MatrixLED_ShowColumn(4,0x21);
		MatrixLED_ShowColumn(5,0x42);
		MatrixLED_ShowColumn(6,0x44);
		MatrixLED_ShowColumn(7,0x38);
		MatrixLED_ShowColumn(8,0x00);
	
	}	
}