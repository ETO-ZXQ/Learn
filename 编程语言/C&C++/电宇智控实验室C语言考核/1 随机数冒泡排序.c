//�����ð������ 
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
//ð������ 
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
	srand((unsigned int)time(NULL));//������� 
	for(i=0;i<10;i++)
		a[i] = rand();//�������ֵ
	
	
	//��ӡ������� 
	printf("������������ǣ�\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n"); 
	
	sort(a) ;//���������� 
	
	//������� 
	printf("���������Ϊ��\n"); 
	for(i=0;i<10;i++)
		printf("%d ",a[i]); 
	printf("\n");
	
	return 0;
} 
