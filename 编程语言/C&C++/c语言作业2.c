//�Ӽ���������һ����������������������������룬�������0ֹͣ���룩�������
//
//��1���������������ƽ��ֵ��
//
//��2������ƽ��ֵ���������ĸ�����
# include <stdio.h>
int main()
{
	int count = 0;						//������ 
	int flag = 0;
	int i;				
	int num[1000] = {};
	unsigned long long sum = 0;			//�ܺ� 
	double average = 0;					//ƽ��ֵ 
	
	printf("������һ����������������������������룬�������0ֹͣ���룩\n");
	while(1)
	{
		scanf("%d", &num[count]);
		sum = sum + num[count];
		count++;
 
		// �ж����� 
		if (num[count-1]<=0)
		{	
			if (num[count-1]==0)
				break;
			else
				{
					printf("�������룺\n");
					count = 0;
					sum  = 0;
				}
		}
		 
	}

	count--;			// ���Ϊ0 count��¼Ԫ�ظ���
	
	average = sum/count; 		// ����ƽ��ֵ 
	
	// ��������
	for(i=0;i<count;i++)
	{
		if (num[i] > average)
			flag++;
	} 
	printf("�����������������ƽ��ֵΪ��%10.2f\n", average);
	printf("����ƽ��ֵ���������ĸ���Ϊ��%10d\n", flag);
	return 0;
}
