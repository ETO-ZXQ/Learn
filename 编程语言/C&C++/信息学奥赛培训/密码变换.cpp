#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned long long a;
	char b;
	cin>>a;
	if (a/123>=97&&a/123<=122) b=a/123;
	else if(a%91>=65&&a%91<=90) b=a%91;
	     else b='*';
	cout<<b;
	return 0;
 } 
