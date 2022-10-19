//�����Է�����
# include <stdio.h>
# include <math.h>
# define FLAG1 "Infinite group solutions"
# define FLAG2 "No solution"

int n;
const double eps = 1e-6; //epsilon 
int judge (double x [n][n+1],int r)
{
	int i; 
	// ���r < n��˵�����ı�׼�εķ��̸�����С��n�ģ��ǲ���Ψһ��
    if (r < n) 
	{
    	// ������ϵ��ȫ��0�ķ����еĳ�����������һ����0�����޽�
        for (i = r; i < n; i++) //�� r+1 �п�ʼ�ж� 
            if (fabs(x[i][n]) > eps)
  	            return 2;
        // �����������
        return 1;
    }
	
	// ���r = n���򷽳���Ψһ��
	return 3;
}
int simplify (double x [n][n+1])
{
	double trans;
	int c, r,i,j;// cΪ�� rΪ��  
    for (c = 0, r = 0; c < n; c++) 
	{
    	// �ҵ���ǰ�еľ���ֵ����һ��
        int t = r;  //  ������һ�У���һ�д���һ�п�ʼ���� 
        for (i = r; i < n; i++)
        {   if (fabs(x[i][c]) > fabs(x[t][c]))
        		t = i;
		} 
		// �����ǰ��ȫ��0����ɨ����һ����
        if (fabs(x[t][c]) < eps)
			continue;
		
		// ���������ֵ������һ�л�����ǰ��
        for (i = c; i < n + 1; i++) 
		{
			trans = x[t][i];
			x[t][i] = x[r][i];
			x[r][i] = trans; 
		}
        // ����һ�еĵ�һ��ϵ����Ϊ 1
        for (i = n; i >= c; i--)
			x[r][i] /= x[r][c];
        
		// ����������Ԫ�ػ�Ϊ 0  
        for (i = r + 1; i < n; i++)
        { 
			if (fabs(x[i][c]) > eps)
            {
				for (j = n; j >= c; j--)
                    x[i][j] -= x[r][j] * x[i][c];
			}    
		}   
        r++; // r���ջ��� 1 ������Ϊ�������� 
    }	
	return r; 
} 
 
int main(void)
{
	//���� 
	int i,j,flag,r;
	printf("������n��");
	scanf("%d",&n);
	double x [n][n+1];// �䳤���� c99 
	printf("������ %d*%d �������\n",n,n+1);
	for (i=0;i<n;i++)
	{
		for (j=0;j<(n+1);j++)
			scanf("%lf", &x[i][j]);	
	} 		 
	
	//��Ϊ�м�
	r = simplify (x); 


/*    //�����м� 
for (i=0;i<n;i++)
	{
		for (j=0;j<(n+1);j++)
			printf("%lf  ", x[i][j]);	
	} 
	
printf("\n");	
*/

	//�ж�
	flag = judge (x,r) ;
	
	//�����(ֻ��������)
	if(flag==3)
	{
		for (i = n - 2; i >= 0; i--)
        	for (j = i + 1; j < n; j++)
        		x[i][n] -= x[j][n] * x[i][j];		
	} 
	
	//���
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
