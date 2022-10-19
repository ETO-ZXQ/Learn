#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short a,b,c,d,e,f,h1,h2;
	cin>>a>>b>>c>>d;
	h1=60*a+b;
	h2=60*c+d;
	e=(h2-h1)/60;
	f=(h2-h1)%60;
	cout<<e<<" "<<f<<endl;
	return 0;
}
