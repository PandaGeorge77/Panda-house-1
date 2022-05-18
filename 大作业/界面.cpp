#include<stdio.h>
#include <stdlib.h>

int form()                                           //登录界面
{
	system("cls");   //清屏
	int n;
	printf("\t\t   ┌--------------------┐\n");
	printf("\t\t   │ 1. 管理员登录      │\n");
	printf("\t\t   │ 2. 学生登录        │\n");
	printf("\t\t   │ 其他数字：退出程序 │\n");
	printf("\t\t   └--------------------┘\n");
	printf("\t\t     请您选择(1-2):");
	scanf("%d", &n);
	return n;
}
	int sselect()                                     //学生主菜单
	{
		int n;
		system("cls"); 
		printf("\t\t   ┌----------------------┐\n");
		printf("\t\t   │ 1. 本人学分信息查询  │\n");
		printf("\t\t   │ 2. 修改密码          │\n");
		printf("\t\t   │ 0. 退出登录          │\n");
		printf("\t\t   │ 其他数字：退出程序   │\n");
		printf("\t\t   └----------------------┘\n");
		printf("\t\t     请您选择(0-2):");
		scanf("%d", &n);
		return n;
	}
	int mselect()                                        //管理员主菜单 
	{
		int n;
		system("cls"); 
		printf("\t\t   ┌----------------------------┐\n");
		printf("\t\t   │ 1. 学生信息及学分信息查询  │\n");
		printf("\t\t   │ 2. 学生密码管理            │\n");
		printf("\t\t   │ 3. 数据管理                │\n");
		printf("\t\t   │ 4. 修改密码                │\n");
		printf("\t\t   │ 0. 退出登录                │\n");
		printf("\t\t   │ 其他数字：退出程序         │\n");
		printf("\t\t   └----------------------------┘\n");
		printf("\t\t     请您选择(0-4):");
		scanf("%d", &n);
		return n;
	}
	int query()                                              //查询菜单
	{
		int n;
		system("cls"); 
		printf("\t\t   ┌------------------------------┐\n");
		printf("\t\t   │ 1. 按学号查询                │\n");
		printf("\t\t   │ 2. 按班级号查询              │\n");
		printf("\t\t   │ 3. 按班级查询                │\n");
		printf("\t\t   │ 4. 按课程类查询尚未达标的同学│\n");
		printf("\t\t   │ 5. 毕业生按成绩排列          │\n");
		printf("\t\t   │ 0. 返回主菜单                │\n");
		printf("\t\t   │ 其他数字：退出程序           │\n"); 
		printf("\t\t   └------------------------------┘\n");
		printf("\t\t     请您选择(0-5):");
		scanf("%d", &n);
		return n;
	}
	int statistic()                                       //数据管理（统计）菜单
	{
		int n;
		system("cls"); 
		printf("\t\t   ┌-------------------┐\n");
		printf("\t\t   │ 1. 添加数据       │\n");
		printf("\t\t   │ 2. 修改数据       │\n");
		printf("\t\t   │ 3. 删除数据       │\n");
		printf("\t\t   │ 0. 返回主菜单     │\n");
		printf("\t\t   │ 其他数字：退出程序│\n");
		printf("\t\t   └-------------------┘\n");
		printf("\t\t     请您选择(0-2):");
		scanf("%d", &n);
		return n;
	}

	int mmanage()                                           //学生密码管理菜单
	{
		int n;
		system("cls");
		printf("\t\t   ┌----------------------┐\n");
		printf("\t\t   │ 1. 查询学生密码      │\n");
		printf("\t\t   │ 2. 修改学生密码      │\n");
		printf("\t\t   │ 0. 返回主菜单        │\n");
		printf("\t\t   │ 其他数字：退出程序   │\n");
		printf("\t\t   └----------------------┘\n");
		printf("\t\t     请您选择(0-2):");
		scanf("%d", &n);
		return n;
	}