#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short a;
	double w;
	cin>>a;
	if(a<=150) w=0.4463*a;
	  else 
	  {
	  	if(a<=400) w=66.945+(a-150)*0.4663;
	  	  else w=183.52+(a-400)*0.5663;	  	
	  }
	cout<<fixed<<setprecision(1)<<w<<endl;  
	return 0;
}
