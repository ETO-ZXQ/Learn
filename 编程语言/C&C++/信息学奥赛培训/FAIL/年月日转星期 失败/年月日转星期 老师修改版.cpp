#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	short w,s;
	unsigned int y,m,d;
	int M,Y,c,x;
	cout<<"输入 年 月 日"<<endl;
	cin>>y>>m>>d;
	if(m==1) M=11;
	if(m==2) M=12; 
	M=(m-3)%12+1; 
	Y=y-M/11;
	c=Y/100;
	x=Y%100; 
	s=x+x/4+c/4-2*c+2*M+(M+M/7)/2+M/12+d;
	if(s>=0) 
	 {
	 	//w=s%7;
	 	//if(w=0) w=7;
	    cout<<s%7;
     }
	 else cout<<7+s%7;
	return 0;
}
