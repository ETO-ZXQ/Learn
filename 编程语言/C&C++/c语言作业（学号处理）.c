//2022��5��4�� ��ϩ�� 
# include<stdio.h> 
int main()
{
	unsigned long long student_num,test = 0;
	unsigned int grade,clas,institute,num = 0;
	int flag,i = 0;
	while(1)
	{
		f:
		
		flag=0;
		printf("������ѧ�ţ�"); 
		scanf("%llu",&student_num);
		
		// �ж��Ƿ�Ϊ0 
		if(student_num == 0) break;
	
		// �жϳ��� 
		test = student_num;
		while(test!=0)
		{		
			flag++;
			test = test/10;
		}
		if(flag != 12)
		{
			printf("���ȴ���\n");
			goto f;
		}
		// �����꼶
		grade = student_num/100000000;
		student_num = student_num%100000000; 
		switch(grade)
		{
			case 2018:
				break;
			case 2019:
				break;
			case 2020:
				break;
			case 2021:
				break;
			default:				
				printf("�꼶����\n");
				goto f;				
		}
		// ѧԺ
		institute = student_num/1000000;
		student_num = student_num%10000; 
		switch(institute)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;			
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 63:
				break;
			case 10:
				break;
			case 11:
				break;
			case 21:
				break;
			case 22:
				break;
			case 23:
				break;
			case 24:
				break;
			case 31:
				break;
			case 32:
				break;
			case 33:
				break;
			case 34:
				break;
			case 35:
				break;
			case 36:
				break;
			case 37:
				break;
			case 38:
				break;
			case 39:
				break;
			case 40:
				break;
			case 41:
				break;
			case 45:
				break;
			case 46:
				break;
			case 47:
				break;
			case 48:
				break;
			case 49:
				break;
			case 51:
				break;
			case 52:
				break;
			case 53:
				break;
			case 54:
				break;
			case 90:
				break;			
			default:				
				printf("ѧԺ����\n");
				goto f;				
		}
		// �༶ �������
		clas =  student_num/100;
		num = student_num%100;
		//���
		printf("%d�� ",grade);
		switch(institute)
		{
			case 1:
				printf("��е�붯������ѧԺ ");
				break;
			case 2:
				printf("��������ѧԺ ");
				break;
			case 3:
				printf("����ѧԺ ");
				break;
			case 4:
				printf("��ľ����ѧԺ ");
				break;
			case 5:
				printf("ˮ����ѧ�빤��ѧԺ ");
				break;			
			case 6:
				printf("��ѧ�밲ȫ����ѧԺ ");
				break;
			case 7:
				printf("������ѧԺ ");
				break;
			case 8:
				printf("���Ͽ�ѧ�빤��ѧԺ ");
				break;
			case 9:
				printf("����ѧԺ ");
				break;
			case 63:
				printf("��ǻҽѧԺ ");
				break;
			case 10:
				printf("�����ѧ�뼼��ѧԺ ");
				break;
			case 11:
				printf("��̬�뻷��ѧԺ ");
				break;
			case 21:
				printf("��ѧ��ͳ��ѧԺ ");
				break;
			case 22:
				printf("����ѧԺ ");
				break;
			case 23:
				printf("��ѧѧԺ ");
				break;
			case 24:
				printf("��Ϣ����ѧԺ ");
				break;
			case 31:
				printf("��ѧԺ ");
				break;
			case 32:
				printf("���ι���ѧԺ ");
				break;
			case 33:
				printf("�����빫������ѧԺ ");
				break;
			case 34:
				printf("��Ϣ����ѧԺ ");
				break;
			case 35:
				printf("��ѧԺ ");
				break;
			case 36:
				printf("��ѧԺ ");
				break;
			case 37:
				printf("���������ʹ�ϵѧԺ ");
				break;
			case 38:
				printf("��ʷѧԺ ");
				break;
			case 39:
				printf("���˼����ѧԺ ");
				break;
			case 40:
				printf("�����봫��ѧԺ ");
				break;
			case 41:
				printf("����ѧԺ ");
				break;
			case 45:
				printf("�鷨ѧԺ ");
				break;
			case 46:
				printf("����ѧԺ ");
				break;
			case 47:
				printf("������ѧѧԺ ");
				break;
			case 48:
				printf("����ѧԺ ");
				break;
			case 49:
				printf("����ѧԺ(У����) ");
				break;
			case 51:
				printf("����ҽѧԺ ");
				break;
			case 52:
				printf("��������ѧԺ ");
				break;
			case 53:
				printf("ҩѧԺ ");
				break;
			case 54:
				printf("�����뽡��ѧԺ ");
				break;
			case 90:
				printf("������ ");
				break;						
		} 
		printf("%d�� ",clas);
		printf("%d��\n",num);
	}
	
	printf("���������\n");
	
	return 0;
} 
