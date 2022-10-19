#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	bool flag=1;
	int n;
	unsigned int i;
	cout<<"判断质数 请输入"<<endl;
	cin>>n; 
	if(n<=1) cout<<n<<"不是质数"<<endl;
	 else {
		for(i=2;i*i<=n;i++)
		 if(n%i==0) flag=0;
		if(flag) cout<<n<<"是质数"<<endl;
		 else cout<<n<<"不是质数"<<endl; 
	    } 
	return 0;
}
