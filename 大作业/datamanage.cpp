#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Student

{

	int num;                                      //ѧ��

	char name[20];                                //����

	int classes[6];                               //a[0]�����Σ�a[1]רҵ�����Σ�a[2]רҵ�Σ�a[3]רҵѡ�޿Σ�a[4]ʵ����Σ�a[5]���ܷ�

	int trought;                                  //�Ƿ�ͨ�������ͨ����Ϊ1��δͨ��Ϊ0

};

void dataadd()
{
	flag_add:
	system("cls");                                //����
	int n;
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "a");                      //a��ʾ׷�����ļ�ĩβ
	printf("������������");
	scanf("%s",a.name);
	printf("������ѧ�ţ�");
	scanf("%d", &a.num);
	printf("�밴�����Ρ�רҵ�����Ρ�רҵ�Ρ�רҵѡ�޿Ρ�ʵ����ε�˳������5�ſεĳɼ���\n");
	scanf("%d%d%d%d%d", &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
	fprintf(p, "%6s  %6d  %d  %d  %d  %d  %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	fclose(p);
	printf("д�����ݳɹ����Ƿ����д�룿����1�����������������ַ��أ�");
	scanf("%d", &n);
	if (n == 1)
		goto flag_add;                             //�����������
}

void data_modify()
{
	int i ,sum= 0, n, k,newdata;
	char c[20];
	struct Student a;
	FILE* p,*q;
	printf("������ѧ��ѧ�ţ�");
	scanf("%d", &n);
flag_reinput:
	printf("���������޸Ŀγ����ƣ�");
	scanf("%s", c);
	if (strcmp(c, "������") == 0)                    //�жϿγ����
	{
		k = 0;
	}
	else if (strcmp(c, "רҵ������") == 0)
	{
		k = 1;
	}
	else if (strcmp(c, "רҵ��") == 0)
	{
		k = 2;
	}
	else if (strcmp(c, "רҵѡ�޿�") == 0)
	{
		k = 3;
	}
	else if (strcmp(c, "ʵ�����") == 0)
	{
		k = 4;
	}
	else
	{
		printf("�����������������γ����ƣ�\n");
		goto flag_reinput;                               //��������󣻷�����������
	}
	p = fopen("sText.txt","r");
	q = fopen("sText_.txt", "w");
	printf("������ÿγ̵ķ�����");
	scanf("%d", &newdata);
	while (!feof(p))
	{
		fscanf(p, "%s%d%d%d%d%d%d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		if (a.num == n)                                  //�滻����
			a.classes[k] = newdata;
		fprintf(q, "%6s  %d  %d  %d  %d  %d  %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
		sum++;
	}
	fclose(p);
	fclose(q);
	p = fopen("sText.txt", "w");
	q = fopen("sText_.txt", "r");
	for (i = 0; i < sum - 1; i++)                        //���޸ĺõ��������µ���xm.txt��
	{
		fscanf(q, "%s%d%d%d%d%d%d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		fprintf(p, "%-6s    %6d    %d    %d    %d    %d    %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	}
	fclose(p);
	fclose(q);
	remove("sText_.txt");
	printf("�޸ĳɹ���");
	system("pause");
}

void data_delete()                                        //ɾ��ָ��ѧ������������
{
	int i=0, sum = 0, n;
	char c[20];
	struct Student a;
	FILE* p, * q;
	printf("������ѧ��ѧ�ţ�");
	scanf("%d", &n);
	p = fopen("sText.txt", "r");
	q = fopen("sText_.txt", "w");
	while (!feof(p))
	{
		fscanf(p, "%s%d%d%d%d%d%d", a.name, &a.num,  &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		if (a.num!= n)                                  //ֻ����Ǹ�ѧ��������
		{
			fprintf(q, " %s  %d %d %d %d %d %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
			sum++;
		}
	}
	fclose(p);
	fclose(q);
	p = fopen("sText.txt", "w");
	q = fopen("sText_.txt", "r");
	for (i = 0; i < sum - 1; i++)                        //���޸ĺõ��������µ���xm.txt��
	{
		fscanf(q, "%s%d%d%d%d%d%d", a.name, &a.num,&a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		fprintf(p, "%s %d %d %d %d %d %d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4]);
	}
	fclose(p);
	fclose(q);
	remove("sText_.txt");
	printf("ɾ�����ݳɹ���");
	system("pause");
}