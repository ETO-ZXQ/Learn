#include<iostream>  
using namespace std;    
void PrintfDay(int y,int m, int d); //声明PrintfDay函数    
void CaculateWeekDay(int y, int m, int d)  
{  
    if(m==1||m==2) //把一月和二月换算成上一年的十三月和是四月  
    {  
        m+=12;  
        y--;  
    }  
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
    switch(Week)  
    {  
        case 0: PrintfDay(y,m,d); cout << "星期一" << endl; break;  
        case 1: PrintfDay(y,m,d); cout << "星期二" << endl; break;  
        case 2: PrintfDay(y,m,d); cout << "星期三" << endl; break;  
        case 3: PrintfDay(y,m,d); cout << "星期四" << endl; break;  
        case 4: PrintfDay(y,m,d); cout << "星期五" << endl; break;  
        case 5: PrintfDay(y,m,d); cout << "星期六" << endl; break;  
        case 6: PrintfDay(y,m,d); cout << "星期日" << endl; break;  
    }  
}  
void PrintfDay(int y,int m,int d)  
{  
   // cout << y << "年" << m << "月" << d << "日";  
}  
int main()  
{  
    int year,month,day;  
    cout<<"请输入年 月 日"<<endl;  
    cin>>year>>month>>day;  
    CaculateWeekDay(year,month,day);  
    return 0;  
}  
