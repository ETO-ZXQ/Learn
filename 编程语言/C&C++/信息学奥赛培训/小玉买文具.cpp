#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned int a,w;
	unsigned short b;
	cin>>a>>b;
	w=10*a/19;
	w=w+(10*a%19+b)/19;
	cout<<w<<endl; 
	return 0;
}
