#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student

{

	int num;                                      //学号

	char name[20];                                //姓名

	int classes[6];                               //a[0]基础课，a[1]专业基础课，a[2]专业课，a[3]专业选修课，a[4]实践类课，a[5]，总分

	int trought;                                  //是否通过，如果通过则为1，未通过为0

};

void studentself()                                //学生进行本人学分信息查询
{
	system("cls");                                //清屏
	int n;
	int flag = 0; 
	char name[10];
	struct Student a;
	printf("请输入您的学号\n");
	printf("学号：");
	scanf("%d", &n);
	printf("请输入您的姓名\n");
	printf("姓名：");
	scanf("%s", name);
	FILE* p;
	p = fopen("sText.txt","r");
	while (!feof(p))
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (n == a.num&&(strcmp(name,a.name)==0))
		{
			printf("姓名    学号    基础课   专业基础课   专业课   专业选修课   实践类课    总学分\n");
			printf("%s   %d    %d        %d            %d        %d            %d        %3d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4],a.classes[5]);
			flag = 1;                               //用于判断是否查询成功
			break;
		}
	}
	fclose(p);
	if (flag)
		printf("查询成功！");
	else
		printf("查询失败！");
	system("pause");
}
 
void refernumber()                                   //按学号查询某同学情况
{
	system("cls");                                   //清屏
	int n,flag=0;
	printf("请输入学生学号：\n");
	scanf("%d", &n);
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "r");
	while(!feof(p))                                   //查找该学号的学生数据
	{ 
	  fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
	  a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
	  if (n == a.num)
	  {
		  printf("姓名      学号    基础课   专业基础课   专业课   专业选修课   实践类课    总学分\n");
		  printf("%-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4], a.classes[5]);
		  flag = 1;                                  //用于判断是否查询成功
		  break;
	  } 
	  
	}
	if (!flag)
		printf("没有数据");                          //数据不存在
	fclose(p);
	system("pause");
}

void refernumber_class()                             //按班级号查询所有同学、并按学号从小到大排列
{
	system("cls");                                   //清屏
	int n,i=0,sum=0,j;
	printf("请输入班级号：");
	scanf("%d", &n);
	struct Student a,b[40],t;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("序号   姓名      学号    基础课   专业基础课   专业课   专业选修课   实践类课    总学分\n");
	while (!feof(p))                                 //读入该班级同学的数据
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (a.num / 100 == n)
		{
			sum++;                                   //统计班级人数，便于后续排序
			b[i] = a;
			i++;
		}
	} 
		for (i = 0; i < sum - 1; i++)                //将班级的数据以学号顺序排列
			for (j = 0; j < sum - 1; j++)
				if (b[j].num > b[j + 1].num)
				{
					t = b[j];
					b[j] = b[j + 1];
					b[j + 1] = t;
				}
		for (i = 0; i < sum; i++)
			printf("%-3d    %-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", i + 1, b[i].name, b[i].num, b[i].classes[0], b[i].classes[1], b[i].classes[2], b[i].classes[3], b[i].classes[4], b[i].classes[5]);
	
	fclose(p);
	system("pause");
}

void referclass()                                    //按照班级、以学生姓名拼音顺序排列
{
	{
		system("cls");                               //清屏
		int n,i=0,j,sum=0;
		printf("请输入班级号：");
		scanf("%d", &n);
		struct Student a,b[40],t;
		FILE* p;
		p = fopen("sText.txt", "r");
		printf("序号   姓名      学号    基础课   专业基础课   专业课   专业选修课   实践类课    总学分\n");
		while (!feof(p))                             //读入整个班级的数据
		{
			fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
			a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
			if (a.num / 100 == n)
			{
				b[i] = a;
				sum++;                               //统计班级人数，便于后续排序
				i++;
			}
		}
		for (i = 0; i <sum-1; i++)                   //将班级的数据以学生姓名拼音顺序排列
			for(j=0;j<sum-1;j++)
				if (b[j].name[0] > b[j + 1].name[0])
				{
					t = b[j];
					b[j] = b[j + 1];
					b[j + 1] = t;
				}
		for(i=0;i<sum;i++)
			printf("%-3d    %-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", i + 1, b[i].name, b[i].num, b[i].classes[0], b[i].classes[1], b[i].classes[2], b[i].classes[3], b[i].classes[4], b[i].classes[5]);
		fclose(p);
		system("pause");
	}
}

void refercourse()                                     //按某类课程，输出未达到要求的学生名单
{
	system("cls");                                     //清屏
	char c[20];
	int i=0,n,k;
	printf("请输入课程名称：\n");
	flag_reinput:
	scanf("%s", c);
	if (strcmp(c, "基础课") == 0)                      //判断课程类别以及相应标准
	{
		n = 0;
		k = 50;
	}
	else if (strcmp(c, "专业基础课") == 0)
	{
		n = 1;
		k = 50;
	}
	else if (strcmp(c, "专业课") == 0)
	{
		n = 2;
		k = 36;
	}
	else if (strcmp(c, "专业选修课") == 0)
	{
		n = 3;
		k = 24;
	}
	else if (strcmp(c, "实践类课") == 0)
	{
		n = 4;
		k = 40;
	}
	else
	{
		printf("输入错误！请重新输入课程名称：\n");
		goto flag_reinput;                               //如输入错误；返回重新输入
	}
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("未达标学生名单：\n");
	printf("序号   姓名      学号    分数\n");
	while (!feof(p))
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (a.classes[n]<k)                               //输出未达标的学生名单
		{
			
			printf("%-2d   %-8s   %6d    %2d\n", i+1, a.name,a.num,a.classes[n]);
			i++;
		}
	}
	fclose(p);
	system("pause");
}


void referstandard_meet()                                  //在满足毕业条件的学生中,按从高到低的分数列名单
{
	system("cls");                                         //清屏
	struct Student a,b[1000],t;
	int i = 0, sum = 0,j;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("序号   姓名      学号    基础课   专业基础课   专业课   专业选修课   实践类课\n");
	while (!feof(p))                                       //读入合格学生名单
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];         //求每个学生总学分
		if (a.classes[0]>=50&& a.classes[1]>=50&& a.classes[2]>=36&& a.classes[3]>=24&& a.classes[4]>=40)
		{
			b[i] = a;
			sum++;                                         //统计合格人数，便于后续排序
			i++;
		}
	}
	for (i = 0; i < sum - 1; i++)                          //按总学分排序
	{
		for (j = 0; j < sum - 1; j++)
		{
			if (b[j].classes[5] < b[j + 1].classes[5])
			{
				t = b[j];
				b[j] = b[j + 1];
				b[j + 1] = t;
			}
		}
	}
	printf("满足毕业条件学生名单：\n");
	printf("序号   姓名      学号    基础课   专业基础课   专业课   专业选修课   实践类课    总学分\n");
	for (i = 0; i < sum; i++)
		printf("%-3d    %-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", i + 1, b[i].name, b[i].num, b[i].classes[0], b[i].classes[1], b[i].classes[2], b[i].classes[3], b[i].classes[4], b[i].classes[5]);
	fclose(p);
	system("pause");
}