//ª ∫ÛŒ Ã‚ 
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
unsigned short n,a[30],ans=0;
bool v[30]={0};
int e;
bool check(int e)
{
	for(int i=1;i<=e-1;i++)
    for(int j=i+1;j<=e;j++)
    if(abs(i-j)==abs(a[i]-a[j])) return 0;
    return 1;
}
void xh(int x)
{
	if(x==n+1)
	{
		//if(check()) 
		//{
			for(unsigned int k=1;k<=n;k++)
			printf("%d ",a[k]);
			printf("\n");
			ans++;
	    //}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!v[i])
			{
				a[x]=i;
				v[i]=1;
				if(!check(x)) 
				{
				    v[i]=0;
				    continue;
			    }
				xh(x+1);
				v[i]=0;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	xh(1);
	printf("%d",ans);
	return 0;
}
