#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int y,m,d,s;
	cout<<"输入日期"<<endl;
	cin>>y>>m>>d;
	if(m>1) s=s+31;
	if(m>2)
     if((y%100!=0&&y%4==0)||y%400==0) s=s+29;
	 else s=s+28;
	if(m>3) s=s+31;
	if(m>4) s=s+30;
	if(m>5) s=s+31;
	if(m>6) s=s+30;
	if(m>7) s=s+31;
	if(m>8) s=s+31;
	if(m>9) s=s+30;
	if(m>10) s=s+31;
	if(m>11) s=s+30; 
	cout<<"这是"<<y<<"年的第"<<s+d<<"天";	
	return 0;
}
