//ª ∫ÛŒ Ã‚ fail 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
unsigned short n,i,j,sum,ans=0,k,a[1001]={0};
bool flag=1,v[1001]={0};
unsigned short x=1;
bool check()
{
	for(k=1;k<n;k++)
	{
		if((a[k]==a[k+1])||(abs(a[k]-a[k+1])==1))
		{
			flag=0;
			break;
		}
	}
	if(flag==1) return 1;
	    else return 0;
	flag=1;    
}
unsigned short xh(unsigned short x)
{
	if(x==n+1)
	{
		for(j=1;j<=n;j++)
		a[n]=j;
		if(check()) ans++;
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
		    if(!v[i])
		    {
			    a[x]=i;
			    v[i]=1;
			    xh(x+1);
			    v[i]=0; 
			}
		}  
    }
    return ans;
}
int main()
{
	cin>>n;
	sum=xh(x);
	cout<<ans<<endl;
	return 0;
}
