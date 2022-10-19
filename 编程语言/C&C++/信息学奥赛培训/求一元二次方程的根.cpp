#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	double a,b,c,x1,x2,s,x;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(b*b>=4*a*c) {
	    x1=(-b+sqrt(b*b-4*a*c))/(2*a),x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	    if(b*b==4*a*c) printf("x1=x2=%.5lf",x1);
	    if(b*b>4*a*c) printf("x1=%.5lf;x2=%.5lf",x1,x2);
	}
	else {
		s=-b/(2*a);
		x=sqrt(4*a*c-b*b)/(2*a);
		printf("x1=%.5lf+%lfi;x2=%.5lf-%lfi",s,x,s,x);
	}
	return 0;
 }  
