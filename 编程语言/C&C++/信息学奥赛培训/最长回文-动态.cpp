//最长回文-动态 
#include <iostream>
#include <cstring>
using namespace std;
int b[1000][1000]={0};
int main()
{
	char a[1000];
	gets(a);
	int max=0,max1,max2,i,j;
	for(i=0,j=0;i<strlen(a)-1;i++,j++)
	{
		b[i][j]=1;
		b[i+1][j]=1;
	}
	for(int p=1;p<=strlen(a)-1;p++)
	{
		for(i=0,j=p;j<=strlen(a)-1;i++,j++)
	    {
		    if(a[i]==a[j]&&b[i+1][j-1]>=1)
		    {
			    b[i][j]=j-i+1;
			    if(b[i][j]>max)
			    {
				max=b[i][j];
				max1=i;
				max2=j;
			    }
			    
		    }
	    }
	}
	if(max>0)
	{
		for(i=max1;i<=max2;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl<<max1<<" "<<max2<<" "<<max;
	}
	else cout<<"no"<<endl;	
	return 0;	
}

