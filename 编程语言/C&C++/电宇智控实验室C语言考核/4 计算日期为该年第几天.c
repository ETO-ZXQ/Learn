//计算日期为该年第几天 
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
	//闰年处理
	if ((p->n%4==0&&p->n%100!=0)||(p->n%400==0))
		month[1] = 29;
	 
	//累加
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
	
//输入	
	printf("年：");
	scanf("%d", &rq.n);
	printf("月：");
	scanf("%d", &rq.y);	 
	printf("日：");
	scanf("%d", &rq.r);	

//计算
	i = jisuan (p);	
	
//输出
	printf("该日期为该年的第%d天\n",i);
	
	
	return 0;
}
