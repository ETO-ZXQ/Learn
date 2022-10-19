#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int x=1;
	double s=2,l,delta=2;
	cin>>l;
	while(s<l) 
	{
		x++;
		delta=delta*0.98;
		s=s+delta;
	}
	cout<<x<<endl;
	return 0;
}
