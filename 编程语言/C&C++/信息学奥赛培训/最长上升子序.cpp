//最长上升子序列 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
float a[10001];
unsigned short b[10001];
int main()
{
	memset(b,0,sizeof(b));
	unsigned short i,n,e=0,t=0;
	cout<<"最长上升子序列"<<endl;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]>=a[i-1]) 
		{
		    b[i]=b[i-1]+1;
		    if(b[i]>e)
		    {
		    	e=b[i]+1;
		    	t=i+1;
			}
	    }
	}
	cout<<e<<" "<<"["<<t-e+1<<","<<t<<"]"<<endl;
	return 0;
}
