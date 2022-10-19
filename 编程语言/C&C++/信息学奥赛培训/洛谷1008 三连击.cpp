#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short a1,b1,c1,a2,b2,c2,a3,b3,c3,x=123;
    while(x<=329)
    {
    	a1=x/100;
    	b1=x%100/10;
    	c1=x%100%10;
    	a2=x*2/100;
    	b2=x*2/100/10;
    	c2=x*2%100%10;
    	a3=x*3/100;
    	b3=x*3%100/10;
    	c3=x*3%100%10;
    	if(a1!=b1&&a1!=c1&&a1!=b2&&a1!=b2&&a1!=c2&&a1!=a3&&a1!=b3&&a1!=c3&&c1!=b1&&a2!=b1&&b2!=b1&&c2!=b1&&a3!=b1&&b3!=b1&&c3!=b1&&c1!=a2&&c1!=b2&&c1!=c2&&c1!=a3&&c1!=b3&&c1!=c3&&a2!=b2&&a2!=c2&&a2!=a3&&a2!=b3&&a2!=c3&&b2!=c2&&b2!=a3&&b2!=b3&&b2!=c3&&c2!=a3&&c2!=b3&&c2!=c3&&a3!=b3&&a3!=c3&&b3!=c3) cout<<x<<" "<<x*2<<" "<<x*3<<endl;
    	x++;
	}
	return 0;
}
