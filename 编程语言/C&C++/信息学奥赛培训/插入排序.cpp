//��������/֧�ָ��� ����/ͬ���޺ϲ� 
#include<iostream> 
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
double a[10001];
double b[10001];
int main()
{
	unsigned short n,i,j=0;
	double temp;
	cout<<"��������"<<endl;
	cout<<"��Χ 10000���� ˫���ȸ�����"<<endl;
	cout<<"���������ָ���"<<endl;
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	b[0]=a[0];
	for(i=1;i<n;i++)
	{
		j=i;
		b[j]=a[i];
		while(b[j]<b[j-1])
		{
			temp=b[j];
			b[j]=b[j-1];
			b[j-1]=temp;
			if(j==1) continue;
			j--;
		}
    }
    for(i=0;i<n;i++) cout<<b[i]<<" ";
	return 0;
}

