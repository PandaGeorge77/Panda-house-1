#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct e
{
	char a[20];
	char b[20];
};

char xy[20],gy[20];                                   //ȫ�ֱ����ֱ��ǵ�¼��ѧ���������û��������߲�ѯ����ѧ������ʱ����ǣ�

int Gmima()                                           //����Ա��¼
{ 
	system("cls");
	printf("����Ա��¼\n");
int t=0;
char s[20],d[20];
FILE *p;
struct e z;
printf("�������û����� ");
scanf("%s", s);
printf("���������룺");
scanf("%s", d);
p = fopen("gm.txt", "r");                               //����Ա�˺���������gm.txt��
while (!feof(p))
{
	fscanf(p,"%s %s", z.a, z.b);
	if (strcmp(z.a, s) == 0 && strcmp(z.b, d)==0)
	{
		strcpy(gy, s);                                  //����û����������޸�����
		printf("��½�ɹ���");
		system("pause");
		return 1;
	}
}
printf("�˺Ż��������");
system("pause");
return 0;
} 

int Xmima()                                             //ѧ����¼
{
	system("cls");
	printf("ѧ����¼\n");
	int t = 0;
	char s[20], d[20];
	FILE* p;
	struct e z;
	printf("�������û����� ");
	scanf("%s", s);
	printf("���������룺");
	scanf("%s", d);
	p = fopen("xm.txt", "r");                           //ѧ���˺ź���������xm.txt��
	while (!feof(p))
	{
		fscanf(p, "%s %s", z.a, z.b);
		if (strcmp(z.a, s) == 0 && strcmp(z.b, d) == 0)
		{
			strcpy(xy, s);
			printf("��½�ɹ���");
			system("pause");
			return 1;
		}
	}
	printf("�˺Ż��������");
	system("pause");
	return 0;
}



void GmimaXG()                                            //����Ա�޸��Լ�������
{ 
	system("cls");
	int t=0,sum=0,i;
    char s[20],d[20];
    FILE *p,*q;
	struct e r,xm,xm_;
	printf("�����벻����10λ��������ĸ��ɵ������룺");
flagxg1:
	scanf("%s", xm.b);
	printf("��ȷ�����룺");
	scanf("%s", xm_.b);
	if (strcmp(xm.b, xm_.b) == 0)                        //����ȷ���������Ž��и��������
	{
		p = fopen("gm.txt", "r");
		q = fopen("gm_.txt", "w");                       //���޸ĺ������������ʱ�ļ�gm_txt��
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
		for (i = 0; i < sum - 1; i++)                     //���޸ĺõ��������µ���gm.txt��
		{
			fscanf(p, "%s%s", r.a, r.b);
			fprintf(q, "%s %s\n", r.a, r.b);
		}
		fclose(q);
		fclose(p);
		printf("�޸ĳɹ���");
		remove("gm_.txt");                                //ɾ����ʱ�ļ�
		system("pause");
	}
	else                                                  //��ֹ�����������ʹ���߿��Լ�����������
	{
		printf("�����������벻һ��!\n");                  
		system("pause");
		system("cls");
		printf("���������룺");
		goto flagxg1;
	}
}



 
void XmimaXG()                                               //ѧ���޸��Լ�������
{ 
	system("cls");
	int t = 0, sum = 0, i;
	char s[20], d[20];
	FILE* p, * q;
	struct e r, xm, xm_;
	printf("�����벻����10λ��������ĸ��ɵ������룺");
flagxg2:
	scanf("%s", xm.b);
	printf("��ȷ�����룺");
	scanf("%s", xm_.b);
	if (strcmp(xm.b, xm_.b) == 0)
	{
		p = fopen("xm.txt", "r");
		q = fopen("xm_.txt", "w+");                          //���޸ĺ������������ʱ�ļ�xm_txt��
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
		for (i = 0; i < sum - 1; i++)                         //���޸ĺõ��������µ���xm.txt��
		{
			fscanf(p, "%s%s", r.a, r.b);
			fprintf(q, "%s %s\n", r.a, r.b);
		}
		fclose(q);
		fclose(p);
		printf("�޸ĳɹ���");
		remove("xm_.txt");
		system("pause");
	}
	else
	{
		printf("�����������벻һ��!\n");
		system("pause");
		system("cls");
		printf("���������룺");
		goto flagxg2;
	}
}

void querym_stdudent()                                          //��ѯѧ������
{
	system("cls");
	int flag=0;
	char s[20];
	FILE* p;
	struct e r, xm, xm_;
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", s);
	p = fopen("xm.txt", "r");
	while (!feof(p))
	{
		fscanf(p,"%s%s", r.a, r.b);
		if (strcmp(r.a, s) == 0)
		{
			printf("��ѯ�ɹ���\n");
			printf("��ѧ��������Ϊ��%s\n", r.b);
			flag = 1;
			break;
		}
	}
	fclose(p);
	if (flag == 0)
		printf("��ѯʧ��.");
	system("pause");
}

void modifym_stdudent()                                        //�޸�ѧ�����룬�޸Ĺ�����ѧ���޸��Լ����������ͬ
{
	system("cls");
	int t = 0, sum = 0, i;
	char s[20];
	FILE* p, * q;
	struct e r, xm, xm_;
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", s);
	strcpy(xy, s);
	printf("�����벻����10λ��������ĸ��ɵ������룺");
flagxg2:
	scanf("%s", xm.b);
	printf("��ȷ�����룺");
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
		printf("�޸ĳɹ���");
		remove("xm_.txt");
		system("pause");
	}
	else
	{
		printf("�����������벻һ��!\n");
		system("pause");
		system("cls");
		printf("���������룺");
		goto flagxg2;
	}
}