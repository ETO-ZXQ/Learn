//ľͰ����/�޸��� ����/ͬ��ϲ� 
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
	cout<<"ľͰ����"<<endl;
	cout<<"������ 10000������0-10000������"<<endl;
	cout<<"������ ���ָ���"<<endl;
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

