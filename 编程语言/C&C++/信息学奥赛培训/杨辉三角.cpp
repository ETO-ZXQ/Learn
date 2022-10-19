#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
    int a[51][51];
	cin>>n;
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i][1]=1;
		a[i][i]=1;
		for(int j=2;j<=i-1;j++) a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
    for(int i=1;i<=n;i++)
	{
	    if(i!=n) cout<<setw(3*n-3*i)<<" ";
	    for(int j=1;j<=i;j++)
		    cout<<setw(6)<<a[i][j];
		cout<<endl; 	
    }
	return 0;
}
