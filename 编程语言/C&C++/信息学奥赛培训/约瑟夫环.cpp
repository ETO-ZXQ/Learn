//Լɪ�� 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	cout<<"Լɪ��"<<endl; 
	unsigned short n,m,i=1,j=0,c=0;
	char a[1001];
	fill(&a[0],&a[1001],0);
	cin>>n>>m;//����n���ˣ��ڼ����� 
	while(j<(n-1))
	{	
		if(a[i]==0) c++;
		if(c==m)
		{
			a[i]=1;
			j++;
			c=0;
		}
		i++;
		if(i>n) i=1;
	}
    for(i=1;i<=n;i++) if(a[i]==0) cout<<i<<endl;
	return 0;
}

