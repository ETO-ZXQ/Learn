//走迷宫 
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
bool mg[51][51],map[51][51];
short dx[9]={0,-1,-1,-1,0,1,1,1,0},dy[9]={0,-1,0,1,1,1,0,-1,-1},x1,y1,x2,y2,n;
unsigned short ans=0;
void print()
{
	for(short i=1;i<=n;i++)
	{
	    for(short j=1;j<=n;j++)
	    printf("%d ",map[i][j]);
	    printf("\n");
	} 
	printf("*========================*\n");   
	return;
}
void dg(short x,short y)
{
	if(x==x2&&y==y2)
	{
		ans++;
		print();
	}
	else
	{
		for(short e=1;e<=8;e++)
		{
			if(mg[x+dx[e]][y+dy[e]]==1&&map[x+dx[e]][y+dy[e]]==0&&(x+dx[e])>=1&&(x+dx[e])<=n&&(y+dy[e])>=1&&(y+dy[e]<=n))
			{
				map[x+dx[e]][y+dy[e]]=1;
				dg(x+dx[e],y+dy[e]);
				map[x+dx[e]][y+dy[e]]=0;
			}
		}
	}
	return;
}
int main()
{
	memset(map,0,sizeof(map));
	cout<<"迷宫"<<endl;
	cout<<"地图大小  起始位置(y,x)  终止位置(y,x)"<<endl; 
	cin>>n>>x1>>y1>>x2>>y2;
	//scanf("%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	for(short i=1;i<=n;i++)
	for(short j=1;j<=n;j++)
	    cin>>mg[i][j];
	map[x1][y1]=1;
	printf("==========================\n");  
	dg(x1,y1);
	printf("%d",ans);
	return 0;
}
