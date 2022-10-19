//数组处理 
# include <stdio.h>
int main()
{
	char n;
	unsigned short i,j,t;
	unsigned short get[100] = {0};
	unsigned short num[10] = {0}; 
	unsigned short len1 = 0; //输入数组长度	
	unsigned short len2 = 0; //输出数组长度 
	unsigned short len3 = 0; //相同的组数		
	
	//输入
	for (i=0;i<100;i++) 
	{
		n = getchar();
		if (n=='\n')
			break;
		get[i] = (unsigned short)n-48;
		len1++; 
	}
	//判断是否超长 
	if (i==100&&getchar()!='\n')
	{
		printf("警告：超出100长度限制！");
		return 0; 
	}
	//检查输入
	if (len1==0)
	{
		printf("警告：无输入！"); 
		return 0; 
	} 
	 
	
	//冒泡排序
	for(i=len1-1;i>0;i--)
	{
		for(j=0;j<=i-1;j++)
		{
			if(get[j]>get[j+1])
			{
				t = get[j];
				get[j] = get[j+1];
				get[j+1] = t;
			}
		}
	}  
	//输出数组 
	num[0] = get[0];
	len2++;
	for (i=0;i<len1;i++) 
	{
		if (num[len2-1]!=get[i])
		{
			num[len2] = get[i];
			len2++;		
		} 
	}
	//统计重复数组
	j = 0;
	t = 0;
	for (i=0;i<len1;i++) 
	{
		if (get[i]==num[j])
			t++;
		else
		{
			j++;
			if (t>1)
				len3++;
			t = 1;
		}	
	}	
	if (t>1)
		len3++; 
 
	//输出 
	printf("输出数组为："); 
	for (i=0;i<len2;i++)	
		printf("%d",num[i]);
	printf("\n");
	printf("相同数的数组为：%d组\n",len3);
	printf("输出数组中数据个数为：%d位\n",len2); 
	
	return 0;
} 
