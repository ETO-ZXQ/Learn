#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int y;
	cout<<"�������"<<endl;
	cin>>y;
	if((y%100!=0&&y%4==0)||y%400==0)
	cout<<y<<"������";
	else cout<<y<<"��������"; 
	return 0;
}
