#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int N,a=0,b=0,i=1,s=0;
    cin>>N;
	while(s<N)
	{
		s=s+i;
		i++;
	}
	i--;
	if(i%2==0) 
	{
		a=i-(s-N);
	    b=1+(s-N); 
	}
	else 
	{
		a=1+(s-N);
		b=i-(s-N); 
	}
	cout<<a<<"/"<<b<<endl;
	return 0;
}
