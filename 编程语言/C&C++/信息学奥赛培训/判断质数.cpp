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
	cout<<"�ж����� ������"<<endl;
	cin>>n; 
	if(n<=1) cout<<n<<"��������"<<endl;
	 else {
		for(i=2;i*i<=n;i++)
		 if(n%i==0) flag=0;
		if(flag) cout<<n<<"������"<<endl;
		 else cout<<n<<"��������"<<endl; 
	    } 
	return 0;
}
