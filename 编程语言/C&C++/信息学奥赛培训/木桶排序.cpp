//木桶排序/无浮点 负数/同项合并 
#include<iostream> 
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
char a [10001];
int main()
{
    memset(a,0,sizeof(a));
    unsigned int i,n,temp;
	cout<<"木桶排序"<<endl;
	cout<<"请输入 10000个以内0-10000正整数"<<endl;
	cout<<"请输入 数字个数"<<endl;
	cin>>n;
	for(i=0;i<n;i++) 
	{
		cin>>temp;
		a[temp]=1;
	}
    i=0;	
	for(i=0;i<10000;i++) 
	    if(a[i]==1) cout<<i<<" ";		
	return 0;
}

