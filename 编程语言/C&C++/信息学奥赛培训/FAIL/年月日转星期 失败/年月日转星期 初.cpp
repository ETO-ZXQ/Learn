#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	short w;
	unsigned int y,m,d;
	int M,Y,c,x;
	cout<<"输入 年 月 日"<<endl;
	cin>>y>>m>>d;
	M=(m-3)%12+1;
	Y=y-M/11;
	c=Y/100;
	x=Y%100;             
	w=(x+x/4+c/4-2*c+2*M+(M+M/7)/2+M/12+d)%7;
	cout<<"星期"<<w<<endl; 
	 
	
	
	return 0;
}
