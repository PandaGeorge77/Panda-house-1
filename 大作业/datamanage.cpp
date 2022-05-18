#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Student

{

	int num;                                      //学号

	char name[20];                                //姓名

	int classes[6];                               //a[0]基础课，a[1]专业基础课，a[2]专业课，a[3]专业选修课，a[4]实践类课，a[5]，总分

	int trought;                                  //是否通过，如果通过则为1，未通过为0

};

void dataadd()
{
	flag_add:
	system("cls");                                //清屏
	int n;
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "a");                      //a表示追加在文件末尾
	printf("请输入姓名：");
	scanf("%s",a.name);
	printf("请输入学号：");
	scanf("%d", &a.num);
	printf("请按基础课、专业基础课、专业课、专业选修课、实践类课的顺序输入5门课的成绩：\n");
	scanf("%d%d%d%d%d", &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
	fprintf(p, "%6s  %6d  %d  %d  %d  %d  %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	fclose(p);
	printf("写入数据成功，是否继续写入？输入1继续，输入其他数字返回：");
	scanf("%d", &n);
	if (n == 1)
		goto flag_add;                             //继续添加数据
}

void data_modify()
{
	int i ,sum= 0, n, k,newdata;
	char c[20];
	struct Student a;
	FILE* p,*q;
	printf("请输入学生学号：");
	scanf("%d", &n);
flag_reinput:
	printf("请输入需修改课程名称：");
	scanf("%s", c);
	if (strcmp(c, "基础课") == 0)                    //判断课程类别
	{
		k = 0;
	}
	else if (strcmp(c, "专业基础课") == 0)
	{
		k = 1;
	}
	else if (strcmp(c, "专业课") == 0)
	{
		k = 2;
	}
	else if (strcmp(c, "专业选修课") == 0)
	{
		k = 3;
	}
	else if (strcmp(c, "实践类课") == 0)
	{
		k = 4;
	}
	else
	{
		printf("输入错误！请重新输入课程名称：\n");
		goto flag_reinput;                               //如输入错误；返回重新输入
	}
	p = fopen("sText.txt","r");
	q = fopen("sText_.txt", "w");
	printf("请输入该课程的分数：");
	scanf("%d", &newdata);
	while (!feof(p))
	{
		fscanf(p, "%s%d%d%d%d%d%d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		if (a.num == n)                                  //替换数据
			a.classes[k] = newdata;
		fprintf(q, "%6s  %d  %d  %d  %d  %d  %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
		sum++;
	}
	fclose(p);
	fclose(q);
	p = fopen("sText.txt", "w");
	q = fopen("sText_.txt", "r");
	for (i = 0; i < sum - 1; i++)                        //将修改好的数据重新导回xm.txt中
	{
		fscanf(q, "%s%d%d%d%d%d%d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		fprintf(p, "%-6s    %6d    %d    %d    %d    %d    %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	}
	fclose(p);
	fclose(q);
	remove("sText_.txt");
	printf("修改成功！");
	system("pause");
}

void data_delete()                                        //删除指定学生的所有数据
{
	int i=0, sum = 0, n;
	char c[20];
	struct Student a;
	FILE* p, * q;
	printf("请输入学生学号：");
	scanf("%d", &n);
	p = fopen("sText.txt", "r");
	q = fopen("sText_.txt", "w");
	while (!feof(p))
	{
		fscanf(p, "%s%d%d%d%d%d%d", a.name, &a.num,  &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		if (a.num!= n)                                  //只保存非改学生的数据
		{
			fprintf(q, " %s  %d %d %d %d %d %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
			sum++;
		}
	}
	fclose(p);
	fclose(q);
	p = fopen("sText.txt", "w");
	q = fopen("sText_.txt", "r");
	for (i = 0; i < sum - 1; i++)                        //将修改好的数据重新导回xm.txt中
	{
		fscanf(q, "%s%d%d%d%d%d%d", a.name, &a.num,&a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		fprintf(p, "%s %d %d %d %d %d %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	}
	fclose(p);
	fclose(q);
	remove("sText_.txt");
	printf("删除数据成功！");
	system("pause");
}