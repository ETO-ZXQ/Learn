#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short s1,p1,s2,p2,s3,p3,s4,p4,s5,p5,s6,p6,s7,p7,w=0,a=0;
	cin>>s1>>p1;
	cin>>s2>>p2;
	cin>>s3>>p3;
	cin>>s4>>p4;
	cin>>s5>>p5;
	cin>>s6>>p6;
	cin>>s7>>p7;
	if((s1+p1)>8) 
	{
		w=1;
		a=s1+p1;
    }
	if(((s2+p2)>a)&&((s2+p2)>8))
	{
	  w=2;
	  a=s2+p2;
    }
	if(((s3+p3)>a)&&((s3+p3)>8)) 
	{
	  w=3;
	  a=s3+p3;
    }
	if(((s4+p4)>a)&&((s4+p4)>8))
	{
	  w=4;
	  a=s4+p4;
    }
	if(((s5+p5)>a)&&((s5+p5)>8))
	{
	  w=5;
	  a=s5+p5;
    }
	if(((s6+p6)>a)&&((s6+p6)>8))
	{
	  w=6;
	  a=s6+p6;
    }
	if(((s7+p7)>a)&&((s7+p7)>8)) w=7;
	cout<<w<<endl;
	return 0;
 } 
