#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int n=0,k;
	double s=0;
	cin>>k;
	while(s<=k)
	{
		n++;
		s=s+1.0/n;
	}
	cout<<n<<endl;
	return 0;
}
