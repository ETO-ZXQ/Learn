#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned short x;
	unsigned int n,w=0,ans=1,ant;
	cin>>n>>x;
	while(ans<=n)
	{
		ant=ans;
		while(ant>=10)
		{
			if(ant%10==x) w++;
			ant=ant/10;
		}
		if(ant==x) w++;
		ans++;
	}
	cout<<w<<endl;
	return 0;
}
