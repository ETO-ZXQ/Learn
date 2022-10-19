//解线性方程组
# include <stdio.h>
# include <math.h>
# define FLAG1 "Infinite group solutions"
# define FLAG2 "No solution"

int n;
const double eps = 1e-6; //epsilon 
int judge (double x [n][n+1],int r)
{
	int i; 
	// 如果r < n，说明最后的标准形的方程个数是小于n的，那不是唯一解
    if (r < n) 
	{
    	// 检查左边系数全是0的方程中的常数项，如果发现一个非0，则无解
        for (i = r; i < n; i++) //从 r+1 行开始判断 
            if (fabs(x[i][n]) > eps)
  	            return 2;
        // 否则是无穷解
        return 1;
    }
	
	// 如果r = n，则方程有唯一解
	return 3;
}
int simplify (double x [n][n+1])
{
	double trans;
	int c, r,i,j;// c为列 r为行  
    for (c = 0, r = 0; c < n; c++) 
	{
    	// 找到当前列的绝对值最大的一行
        int t = r;  //  处理完一列，下一列从下一行开始处理 
        for (i = r; i < n; i++)
        {   if (fabs(x[i][c]) > fabs(x[t][c]))
        		t = i;
		} 
		// 如果当前列全是0，那扫描下一个列
        if (fabs(x[t][c]) < eps)
			continue;
		
		// 将这个绝对值最大的那一行换到最前面
        for (i = c; i < n + 1; i++) 
		{
			trans = x[t][i];
			x[t][i] = x[r][i];
			x[r][i] = trans; 
		}
        // 将这一行的第一个系数化为 1
        for (i = n; i >= c; i--)
			x[r][i] /= x[r][c];
        
		// 将该列其余元素化为 0  
        for (i = r + 1; i < n; i++)
        { 
			if (fabs(x[i][c]) > eps)
            {
				for (j = n; j >= c; j--)
                    x[i][j] -= x[r][j] * x[i][c];
			}    
		}   
        r++; // r最终会多加 1 ，正好为非零行数 
    }	
	return r; 
} 
 
int main(void)
{
	//输入 
	int i,j,flag,r;
	printf("请输入n：");
	scanf("%d",&n);
	double x [n][n+1];// 变长数组 c99 
	printf("请输入 %d*%d 增广矩阵：\n",n,n+1);
	for (i=0;i<n;i++)
	{
		for (j=0;j<(n+1);j++)
			scanf("%lf", &x[i][j]);	
	} 		 
	
	//化为行简化
	r = simplify (x); 


/*    //测试行简化 
for (i=0;i<n;i++)
	{
		for (j=0;j<(n+1);j++)
			printf("%lf  ", x[i][j]);	
	} 
	
printf("\n");	
*/

	//判断
	flag = judge (x,r) ;
	
	//计算解(只化常数项)
	if(flag==3)
	{
		for (i = n - 2; i >= 0; i--)
        	for (j = i + 1; j < n; j++)
        		x[i][n] -= x[j][n] * x[i][j];		
	} 
	
	//输出
	switch(flag)
	{
		case 1:
			printf("%s",FLAG1); 
			break;
		case 2: 
			printf("%s",FLAG2);
			break;
		case 3:
			for (i = 0; i < n; i++)
				printf("x%3d= %+.2lf\n",i+1, x[i][n]);
			break;
		default:
			printf("error!");
	} 
	
	return 0;
}
