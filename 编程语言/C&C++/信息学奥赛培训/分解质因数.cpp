#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int i=2;
	int n;
	cin>>n;
	cout<<n<<"=";
	do
	{
		while(n%i==0)
		{
			cout<<i;
			n=n/i;
			if(n!=1) cout<<"*";
		}
		i++;
	}
	while(n!=1);
	return 0;
}
