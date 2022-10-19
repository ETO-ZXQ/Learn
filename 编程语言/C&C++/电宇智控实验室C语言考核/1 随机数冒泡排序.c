//随机数冒泡排序 
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
//冒泡排序 
void sort(int * a)
{
	int i,j,t;
	for(i=9;i>0;i--)
	{
		for(j=0;j<=i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	} 
	return; 
}
int main()
{
	int i;
	int a[10];
	srand((unsigned int)time(NULL));//随机种子 
	for(i=0;i<10;i++)
		a[i] = rand();//随机数赋值
	
	
	//打印随机数组 
	printf("产生的随机数是：\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n"); 
	
	sort(a) ;//调用排序函数 
	
	//输出数组 
	printf("排序后数组为：\n"); 
	for(i=0;i<10;i++)
		printf("%d ",a[i]); 
	printf("\n");
	
	return 0;
} 
