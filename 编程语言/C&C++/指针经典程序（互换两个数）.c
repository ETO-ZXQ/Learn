//指针景点程序（互换两个数） 
# include <stdio.h>
void huhuan(int*,int*);
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	huhuan(&a,&b);
	printf("%d %d\n",a,b);
	
	return 0;
 } 
void huhuan(int*p,int*q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
	
	
//	printf("%p\n",p);
	return;
}
