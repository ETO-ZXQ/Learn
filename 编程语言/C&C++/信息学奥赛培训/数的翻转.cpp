#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	long long n,x;
	x=0;
	cin>>n;
	while(n/10)
	{
		x=x*10;
		x=x+n%10;
		n=n/10;
	}
	cout<<x*10+n<<endl;
	return 0;
}
