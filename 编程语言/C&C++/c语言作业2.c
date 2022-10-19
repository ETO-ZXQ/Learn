//从键盘上输入一批正整数（如果遇到负数重新输入，如果遇到0停止输入），输出：
//
//（1）输入的正整数的平均值；
//
//（2）高于平均值的正整数的个数。
# include <stdio.h>
int main()
{
	int count = 0;						//计数器 
	int flag = 0;
	int i;				
	int num[1000] = {};
	unsigned long long sum = 0;			//总和 
	double average = 0;					//平均值 
	
	printf("请输入一批正整数（如果遇到负数重新输入，如果遇到0停止输入）\n");
	while(1)
	{
		scanf("%d", &num[count]);
		sum = sum + num[count];
		count++;
 
		// 判断输入 
		if (num[count-1]<=0)
		{	
			if (num[count-1]==0)
				break;
			else
				{
					printf("重新输入：\n");
					count = 0;
					sum  = 0;
				}
		}
		 
	}

	count--;			// 最后为0 count记录元素个数
	
	average = sum/count; 		// 计算平均值 
	
	// 遍历数组
	for(i=0;i<count;i++)
	{
		if (num[i] > average)
			flag++;
	} 
	printf("输入的这批正整数的平均值为：%10.2f\n", average);
	printf("高于平均值的正整数的个数为：%10d\n", flag);
	return 0;
}
