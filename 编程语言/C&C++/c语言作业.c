// c语言作业
/*
购买地铁车票的规定如下：

乘1-4站，3元/位；乘5-9站，4元/位；乘9站以上，5元/位，编写一个程序，利用循环结构、选择结构实现：

（1）输入人数、站数，输出应付款；

（2）当结束程序运行的时候，输出应付款累计总额。 
*/ 

# include <stdio.h>
int main()
{
	int i,M = 0;
	int r, z, m = 0;
	char n;
	for(i=0;i<=1000;i++)
	{
		printf("请输入 人数 站数：\n");
		scanf("%d %d", &r, &z);
		
		if(z<=4)
			z = 3;
		else if(z<=9)
			z = 4;
		else
			z = 5;
			
		m = r*z;
		M = M + m;
		
		printf("应付款：%d元\n",m);
		r, z, m = 0;
		
		printf("按任意键继续，按 q 退出\n");
		n = getchar(); 							// 清空缓冲 
		n = getchar();
		if(n=='q') break;
		
	}
	printf("应付款累计总额：%d元", M);
	
	return 0;
}
