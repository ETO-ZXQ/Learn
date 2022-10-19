//2022年5月4日 赵烯桥 
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
		printf("请输入学号："); 
		scanf("%llu",&student_num);
		
		// 判断是否为0 
		if(student_num == 0) break;
	
		// 判断长度 
		test = student_num;
		while(test!=0)
		{		
			flag++;
			test = test/10;
		}
		if(flag != 12)
		{
			printf("长度错误！\n");
			goto f;
		}
		// 处理年级
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
				printf("年级错误！\n");
				goto f;				
		}
		// 学院
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
				printf("学院错误！\n");
				goto f;				
		}
		// 班级 班内序号
		clas =  student_num/100;
		num = student_num%100;
		//输出
		printf("%d级 ",grade);
		switch(institute)
		{
			case 1:
				printf("机械与动力工程学院 ");
				break;
			case 2:
				printf("电气工程学院 ");
				break;
			case 3:
				printf("化工学院 ");
				break;
			case 4:
				printf("土木工程学院 ");
				break;
			case 5:
				printf("水利科学与工程学院 ");
				break;			
			case 6:
				printf("力学与安全工程学院 ");
				break;
			case 7:
				printf("管理工程学院 ");
				break;
			case 8:
				printf("材料科学与工程学院 ");
				break;
			case 9:
				printf("建筑学院 ");
				break;
			case 63:
				printf("口腔医学院 ");
				break;
			case 10:
				printf("地球科学与技术学院 ");
				break;
			case 11:
				printf("生态与环境学院 ");
				break;
			case 21:
				printf("数学与统计学院 ");
				break;
			case 22:
				printf("物理学院 ");
				break;
			case 23:
				printf("化学学院 ");
				break;
			case 24:
				printf("信息工程学院 ");
				break;
			case 31:
				printf("商学院 ");
				break;
			case 32:
				printf("旅游管理学院 ");
				break;
			case 33:
				printf("政治与公共管理学院 ");
				break;
			case 34:
				printf("信息管理学院 ");
				break;
			case 35:
				printf("法学院 ");
				break;
			case 36:
				printf("文学院 ");
				break;
			case 37:
				printf("外国语与国际关系学院 ");
				break;
			case 38:
				printf("历史学院 ");
				break;
			case 39:
				printf("马克思主义学院 ");
				break;
			case 40:
				printf("新闻与传播学院 ");
				break;
			case 41:
				printf("教育学院 ");
				break;
			case 45:
				printf("书法学院 ");
				break;
			case 46:
				printf("美术学院 ");
				break;
			case 47:
				printf("生命科学学院 ");
				break;
			case 48:
				printf("音乐学院 ");
				break;
			case 49:
				printf("体育学院(校本部) ");
				break;
			case 51:
				printf("基础医学院 ");
				break;
			case 52:
				printf("公共卫生学院 ");
				break;
			case 53:
				printf("药学院 ");
				break;
			case 54:
				printf("护理与健康学院 ");
				break;
			case 90:
				printf("交换生 ");
				break;						
		} 
		printf("%d班 ",clas);
		printf("%d号\n",num);
	}
	
	printf("程序结束！\n");
	
	return 0;
} 
