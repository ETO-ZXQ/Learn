//2021��9�� ����� 
#include<stdio.h>
#include<math.h>
int main()
{
	int x = 0;
	int i = 2; 
	int max = 0;//�������ֵ 
	printf("<�ж�����>\n"); 
	printf("������һ������");
	scanf("%d", &x);
	max = sqrt(x);
	for (i;i<=max;i++)
	{
		if (x%i==0)
		{
			printf("���������������");
			i = max + 1;
		}
		if (i==max)
		printf("�������������"); 
	}

	return 0;
}

