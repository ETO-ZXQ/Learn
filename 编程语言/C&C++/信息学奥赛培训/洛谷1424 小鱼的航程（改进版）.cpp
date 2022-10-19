#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short x;
	unsigned long long n,s=0,i;
	cin>>x>>n;
	for(i=1;i<=n;i++)
	{
		if(x<=5) s=s+250;
		x++;
		if(x==8) x=1;
	}
	cout<<s<<endl;
	return 0;
}
