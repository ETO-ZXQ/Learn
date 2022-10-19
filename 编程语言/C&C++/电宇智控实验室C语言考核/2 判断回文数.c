//判断回文数 
# include <stdio.h>
int main()
{
	int i,j ;
	char num[101] = {0} ;
	printf("请输入一个一百位以内的正整数：\n");
	//输入 
	for (i=0;i<101;i++)
	{
		num[i] = getchar();
		if (num[i]=='\n') break; 	
	}
	j= i-1 ;   //j变为数列的最后一位
	i= 0 ;       
	//判断 
	while (i<j)
	{
		if (num[i]!=num[j])
		{
			printf("这个数不是回文数！");
			return 0; 
		}
		//从数列两边往中间移位 
		i++;
		j--;
	}
	printf("这个数是回文数！");
	return 0;
 } 
