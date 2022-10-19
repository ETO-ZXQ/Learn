#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int y;
	cout<<"输入年份"<<endl;
	cin>>y;
	if((y%100!=0&&y%4==0)||y%400==0)
	cout<<y<<"是闰年";
	else cout<<y<<"不是闰年"; 
	return 0;
}
