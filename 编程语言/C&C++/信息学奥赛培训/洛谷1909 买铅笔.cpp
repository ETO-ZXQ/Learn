#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int n,a1,b1,a2,b2,a3,b3,p,h2,h3;
	cin>>n;
	cin>>a1>>b1;
	cin>>a2>>b2;
	cin>>a3>>b3;
	p=(n/a1)*b1+(n%a1>0)*b1;
	h2=(n/a2)*b2+(n%a2>0)*b2;
	h3=(n/a3)*b3+(n%a3>0)*b3;
	if(h2<p) p=h2;
	if(h3<p) p=h3;
	cout<<p<<endl;
	return 0;
}
