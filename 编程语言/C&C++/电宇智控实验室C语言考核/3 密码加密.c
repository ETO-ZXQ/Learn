//密码加密
# include <stdio.h>
# include <string.h>
# include <ctype.h> 
void jiami(char * p,short len)
{
	int i;
	for (i=0;i<=len-1;i++)
	{
		//数字 
		if (isdigit(p[i]))
		{
			if (p[i]=='9')
				p[i]='X';
			else
				p[i] += 1;
			continue; 
		}
		//字母
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
	
	
	fgets(code,12,stdin);//获取字符串 
	len = strlen(code);//包括 '\n' 
	
	//判断长度
	if (len<=6)
	{
		printf("警告：密码过短");
		return 0; 
	} 
	if ((len==11)&&(code[10]!='\n'))
	{
		printf("警告：密码超出长度");
		return 0; 
	}
	
	//判断是否为数字或字母
	for (i=0;i<=len-2;i++)
		if (!isalnum(code[i]))
		{
			printf("警告：字符不规范");
			return 0; 
		} 
	
	//密码加密
	jiami(p,len-1);//len-1 不包括 '\n' 
	
	//输出
	fputs(code,stdout); 
	
	return 0;
 } 
