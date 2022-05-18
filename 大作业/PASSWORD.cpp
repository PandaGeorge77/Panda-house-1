#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct e
{
	char a[20];
	char b[20];
};

char xy[20],gy[20];                                   //全局变量分别标记登录的学生或管理的用户名，或者查询更改学生密码时做标记；

int Gmima()                                           //管理员登录
{ 
	system("cls");
	printf("管理员登录\n");
int t=0;
char s[20],d[20];
FILE *p;
struct e z;
printf("请输入用户名： ");
scanf("%s", s);
printf("请输入密码：");
scanf("%s", d);
p = fopen("gm.txt", "r");                               //管理员账号密码存放在gm.txt中
while (!feof(p))
{
	fscanf(p,"%s %s", z.a, z.b);
	if (strcmp(z.a, s) == 0 && strcmp(z.b, d)==0)
	{
		strcpy(gy, s);                                  //标记用户名方便后边修改密码
		printf("登陆成功！");
		system("pause");
		return 1;
	}
}
printf("账号或密码错误！");
system("pause");
return 0;
} 

int Xmima()                                             //学生登录
{
	system("cls");
	printf("学生登录\n");
	int t = 0;
	char s[20], d[20];
	FILE* p;
	struct e z;
	printf("请输入用户名： ");
	scanf("%s", s);
	printf("请输入密码：");
	scanf("%s", d);
	p = fopen("xm.txt", "r");                           //学生账号和密码存放在xm.txt中
	while (!feof(p))
	{
		fscanf(p, "%s %s", z.a, z.b);
		if (strcmp(z.a, s) == 0 && strcmp(z.b, d) == 0)
		{
			strcpy(xy, s);
			printf("登陆成功！");
			system("pause");
			return 1;
		}
	}
	printf("账号或密码错误！");
	system("pause");
	return 0;
}



void GmimaXG()                                            //管理员修改自己的密码
{ 
	system("cls");
	int t=0,sum=0,i;
    char s[20],d[20];
    FILE *p,*q;
	struct e r,xm,xm_;
	printf("请输入不超过10位由数字字母组成的新密码：");
flagxg1:
	scanf("%s", xm.b);
	printf("请确认密码：");
	scanf("%s", xm_.b);
	if (strcmp(xm.b, xm_.b) == 0)                        //两次确认新密码后才进行改密码操作
	{
		p = fopen("gm.txt", "r");
		q = fopen("gm_.txt", "w");                       //将修改后的密码存放在临时文件gm_txt中
		while (!feof(p))
		{
			fscanf(p, "%s%s", r.a, r.b);
			if (strcmp(r.a, gy) == 0)
			{
				fprintf(q, "%s %s\n", r.a, xm.b);
			}
			else
			{
				fprintf(q, "%s %s\n", r.a, r.b);
			}
			sum++;
		}
		fclose(q);
		fclose(p);
		q = fopen("gm.txt", "w");
		p = fopen("gm_.txt", "r");
		for (i = 0; i < sum - 1; i++)                     //将修改好的密码重新导回gm.txt中
		{
			fscanf(p, "%s%s", r.a, r.b);
			fprintf(q, "%s %s\n", r.a, r.b);
		}
		fclose(q);
		fclose(p);
		printf("修改成功！");
		remove("gm_.txt");                                //删除临时文件
		system("pause");
	}
	else                                                  //防止手误操作，让使用者可以继续更改密码
	{
		printf("两次密码输入不一致!\n");                  
		system("pause");
		system("cls");
		printf("请重新输入：");
		goto flagxg1;
	}
}



 
void XmimaXG()                                               //学生修改自己的密码
{ 
	system("cls");
	int t = 0, sum = 0, i;
	char s[20], d[20];
	FILE* p, * q;
	struct e r, xm, xm_;
	printf("请输入不超过10位由数字字母组成的新密码：");
flagxg2:
	scanf("%s", xm.b);
	printf("请确认密码：");
	scanf("%s", xm_.b);
	if (strcmp(xm.b, xm_.b) == 0)
	{
		p = fopen("xm.txt", "r");
		q = fopen("xm_.txt", "w+");                          //将修改后的密码存放在临时文件xm_txt中
		while (!feof(p))
		{
			fscanf(p, "%s%s", r.a, r.b);
			if (strcmp(r.a, xy) == 0)
			{
				fprintf(q, "%s %s\n", r.a, xm.b);
			}
			else
			{
				fprintf(q, "%s %s\n", r.a, r.b);
			}
			sum++;
		}
		fclose(q);
		fclose(p);
		q = fopen("xm.txt", "w");
		p = fopen("xm_.txt", "r");
		for (i = 0; i < sum - 1; i++)                         //将修改好的密码重新导回xm.txt中
		{
			fscanf(p, "%s%s", r.a, r.b);
			fprintf(q, "%s %s\n", r.a, r.b);
		}
		fclose(q);
		fclose(p);
		printf("修改成功！");
		remove("xm_.txt");
		system("pause");
	}
	else
	{
		printf("两次密码输入不一致!\n");
		system("pause");
		system("cls");
		printf("请重新输入：");
		goto flagxg2;
	}
}

void querym_stdudent()                                          //查询学生密码
{
	system("cls");
	int flag=0;
	char s[20];
	FILE* p;
	struct e r, xm, xm_;
	printf("请输入学生学号：");
	scanf("%s", s);
	p = fopen("xm.txt", "r");
	while (!feof(p))
	{
		fscanf(p,"%s%s", r.a, r.b);
		if (strcmp(r.a, s) == 0)
		{
			printf("查询成功！\n");
			printf("该学生的密码为：%s\n", r.b);
			flag = 1;
			break;
		}
	}
	fclose(p);
	if (flag == 0)
		printf("查询失败.");
	system("pause");
}

void modifym_stdudent()                                        //修改学生密码，修改过程与学生修改自己密码大致相同
{
	system("cls");
	int t = 0, sum = 0, i;
	char s[20];
	FILE* p, * q;
	struct e r, xm, xm_;
	printf("请输入学生学号：");
	scanf("%s", s);
	strcpy(xy, s);
	printf("请输入不超过10位由数字字母组成的新密码：");
flagxg2:
	scanf("%s", xm.b);
	printf("请确认密码：");
	scanf("%s", xm_.b);
	if (strcmp(xm.b, xm_.b) == 0)
	{
		p = fopen("xm.txt", "r");
		q = fopen("xm_.txt", "w+");
		while (!feof(p))
		{
			fscanf(p, "%s%s", r.a, r.b);
			if (strcmp(r.a, xy) == 0)
			{
				fprintf(q, "%s %s\n", r.a, xm.b);
			}
			else
			{
				fprintf(q, "%s %s\n", r.a, r.b);
			}
			sum++;
		}
		fclose(q);
		fclose(p);
		q = fopen("xm.txt", "w");
		p = fopen("xm_.txt", "r");
		for (i = 0; i < sum - 1; i++)
		{
			fscanf(p, "%s%s", r.a, r.b);
			fprintf(q, "%s %s\n", r.a, r.b);
		}
		fclose(q);
		fclose(p);
		printf("修改成功！");
		remove("xm_.txt");
		system("pause");
	}
	else
	{
		printf("两次密码输入不一致!\n");
		system("pause");
		system("cls");
		printf("请重新输入：");
		goto flagxg2;
	}
}