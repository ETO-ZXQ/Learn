//�жϻ����� 
# include <stdio.h>
int main()
{
	int i,j ;
	char num[101] = {0} ;
	printf("������һ��һ��λ���ڵ���������\n");
	//���� 
	for (i=0;i<101;i++)
	{
		num[i] = getchar();
		if (num[i]=='\n') break; 	
	}
	j= i-1 ;   //j��Ϊ���е����һλ
	i= 0 ;       
	//�ж� 
	while (i<j)
	{
		if (num[i]!=num[j])
		{
			printf("��������ǻ�������");
			return 0; 
		}
		//�������������м���λ 
		i++;
		j--;
	}
	printf("������ǻ�������");
	return 0;
 } 
