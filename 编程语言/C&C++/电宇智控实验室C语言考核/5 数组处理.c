//���鴦�� 
# include <stdio.h>
int main()
{
	char n;
	unsigned short i,j,t;
	unsigned short get[100] = {0};
	unsigned short num[10] = {0}; 
	unsigned short len1 = 0; //�������鳤��	
	unsigned short len2 = 0; //������鳤�� 
	unsigned short len3 = 0; //��ͬ������		
	
	//����
	for (i=0;i<100;i++) 
	{
		n = getchar();
		if (n=='\n')
			break;
		get[i] = (unsigned short)n-48;
		len1++; 
	}
	//�ж��Ƿ񳬳� 
	if (i==100&&getchar()!='\n')
	{
		printf("���棺����100�������ƣ�");
		return 0; 
	}
	//�������
	if (len1==0)
	{
		printf("���棺�����룡"); 
		return 0; 
	} 
	 
	
	//ð������
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
	//������� 
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
	//ͳ���ظ�����
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
 
	//��� 
	printf("�������Ϊ��"); 
	for (i=0;i<len2;i++)	
		printf("%d",num[i]);
	printf("\n");
	printf("��ͬ��������Ϊ��%d��\n",len3);
	printf("������������ݸ���Ϊ��%dλ\n",len2); 
	
	return 0;
} 
