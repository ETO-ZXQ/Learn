//�������
# include <stdio.h>
# include <string.h>
# include <ctype.h> 
void jiami(char * p,short len)
{
	int i;
	for (i=0;i<=len-1;i++)
	{
		//���� 
		if (isdigit(p[i]))
		{
			if (p[i]=='9')
				p[i]='X';
			else
				p[i] += 1;
			continue; 
		}
		//��ĸ
		switch(p[i])
		{
			case 'x':
				p[i] = 'A';
				break;
			case 'y':
				p[i] = 'B';
				break;
			case 'z':
				p[i] = 'C';
				break;
			case 'X':
				p[i] = 'a';
				break;
			case 'Y':
				p[i] = 'b';
				break;
			case 'Z':
				p[i] = 'c';
				break;
			default :
				p[i] += 3;
		}
	}
	return;	
} 
int main()
{
	char code[12];
	char * p = code; 
	short len = 0;
	int i;
	
	
	fgets(code,12,stdin);//��ȡ�ַ��� 
	len = strlen(code);//���� '\n' 
	
	//�жϳ���
	if (len<=6)
	{
		printf("���棺�������");
		return 0; 
	} 
	if ((len==11)&&(code[10]!='\n'))
	{
		printf("���棺���볬������");
		return 0; 
	}
	
	//�ж��Ƿ�Ϊ���ֻ���ĸ
	for (i=0;i<=len-2;i++)
		if (!isalnum(code[i]))
		{
			printf("���棺�ַ����淶");
			return 0; 
		} 
	
	//�������
	jiami(p,len-1);//len-1 ������ '\n' 
	
	//���
	fputs(code,stdout); 
	
	return 0;
 } 
