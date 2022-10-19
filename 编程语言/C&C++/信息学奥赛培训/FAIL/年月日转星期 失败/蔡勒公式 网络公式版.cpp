#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	short w;
	unsigned int y,m,d,c;
	cout<<"输入 年 月 日"<<endl;
	cin>>y>>m>>d;
	if(m<3) 
	{
		m=m+12;
		y=y-1;
	}
	c=y/100;
	y=y%100;
	w=y+y/4+c/4-2*c+(26*(m+1))/10+d-1;
    cout<<"星期"<<w<<endl; 
    return 0;
}
	
