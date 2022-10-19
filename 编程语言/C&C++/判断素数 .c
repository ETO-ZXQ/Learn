//2021年9月 暑假中 
#include<stdio.h>
#include<math.h>
int main()
{
	int x = 0;
	int i = 2; 
	int max = 0;//除的最大值 
	printf("<判断素数>\n"); 
	printf("请输入一个数：");
	scanf("%d", &x);
	max = sqrt(x);
	for (i;i<=max;i++)
	{
		if (x%i==0)
		{
			printf("这个数不是素数！");
			i = max + 1;
		}
		if (i==max)
		printf("这个数是素数！"); 
	}

	return 0;
}

