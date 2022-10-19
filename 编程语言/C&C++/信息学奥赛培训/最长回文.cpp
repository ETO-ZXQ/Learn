//最长回文 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1010],flag=1;
int main()
{
	unsigned int i,j,k=0,a,b,n,e,t,len;
	cout<<"最长回文"<<endl;
	gets(s);
	len=strlen(s);
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<=len-1;j++)
		{
			a=i;
			b=j;
			for(n=1;n<=((j-i+1)/2);n++)
			{
				if(s[a]!=s[b])
				{
				  flag=0;
				  break;
			    }   
				a++;
				b--;	
			}
			if(flag==1&&k<(j-i+1))
			{
				k=j-i+1;
				e=i+1;
				t=j+1;
		    }
		    flag=1;
		}
	}
	cout<<k<<" "<<"["<<e<<","<<t<<"]"<<endl;          
	return 0;
}
