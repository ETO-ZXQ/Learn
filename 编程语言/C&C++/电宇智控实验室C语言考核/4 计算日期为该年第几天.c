//��������Ϊ����ڼ��� 
# include <stdio.h>
struct date
{
	unsigned short n; 
	unsigned short y; 
	unsigned short r; 
};
unsigned short jisuan (struct date * p)
{
	int i;
	unsigned short n = 0;
	unsigned short month[11] = {31,28,31,30,31,30,31,31,30,31,30};
	//���괦��
	if ((p->n%4==0&&p->n%100!=0)||(p->n%400==0))
		month[1] = 29;
	 
	//�ۼ�
	for (i=0;i<=(p->y-2);i++)
		n = n + month[i];
	
	n = n + p->r;
	return n;
}
int main ()
{
	unsigned short i;
	struct date rq;
	struct date * p = &rq; 
	
//����	
	printf("�꣺");
	scanf("%d", &rq.n);
	printf("�£�");
	scanf("%d", &rq.y);	 
	printf("�գ�");
	scanf("%d", &rq.r);	

//����
	i = jisuan (p);	
	
//���
	printf("������Ϊ����ĵ�%d��\n",i);
	
	
	return 0;
}
