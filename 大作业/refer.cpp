#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student

{

	int num;                                      //ѧ��

	char name[20];                                //����

	int classes[6];                               //a[0]�����Σ�a[1]רҵ�����Σ�a[2]רҵ�Σ�a[3]רҵѡ�޿Σ�a[4]ʵ����Σ�a[5]���ܷ�

	int trought;                                  //�Ƿ�ͨ�������ͨ����Ϊ1��δͨ��Ϊ0

};

void studentself()                                //ѧ�����б���ѧ����Ϣ��ѯ
{
	system("cls");                                //����
	int n;
	int flag = 0; 
	char name[10];
	struct Student a;
	printf("����������ѧ��\n");
	printf("ѧ�ţ�");
	scanf("%d", &n);
	printf("��������������\n");
	printf("������");
	scanf("%s", name);
	FILE* p;
	p = fopen("sText.txt","r");
	while (!feof(p))
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (n == a.num&&(strcmp(name,a.name)==0))
		{
			printf("����    ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����    ��ѧ��\n");
			printf("%s   %d    %d        %d            %d        %d            %d        %3d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4],a.classes[5]);
			flag = 1;                               //�����ж��Ƿ��ѯ�ɹ�
			break;
		}
	}
	fclose(p);
	if (flag)
		printf("��ѯ�ɹ���");
	else
		printf("��ѯʧ�ܣ�");
	system("pause");
}
 
void refernumber()                                   //��ѧ�Ų�ѯĳͬѧ���
{
	system("cls");                                   //����
	int n,flag=0;
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d", &n);
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "r");
	while(!feof(p))                                   //���Ҹ�ѧ�ŵ�ѧ������
	{ 
	  fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
	  a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
	  if (n == a.num)
	  {
		  printf("����      ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����    ��ѧ��\n");
		  printf("%-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", a.name, a.num, a.classes[0], a.classes[1], a.classes[2], a.classes[3], a.classes[4], a.classes[5]);
		  flag = 1;                                  //�����ж��Ƿ��ѯ�ɹ�
		  break;
	  } 
	  
	}
	if (!flag)
		printf("û������");                          //���ݲ�����
	fclose(p);
	system("pause");
}

void refernumber_class()                             //���༶�Ų�ѯ����ͬѧ������ѧ�Ŵ�С��������
{
	system("cls");                                   //����
	int n,i=0,sum=0,j;
	printf("������༶�ţ�");
	scanf("%d", &n);
	struct Student a,b[40],t;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("���   ����      ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����    ��ѧ��\n");
	while (!feof(p))                                 //����ð༶ͬѧ������
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (a.num / 100 == n)
		{
			sum++;                                   //ͳ�ư༶���������ں�������
			b[i] = a;
			i++;
		}
	} 
		for (i = 0; i < sum - 1; i++)                //���༶��������ѧ��˳������
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

void referclass()                                    //���հ༶����ѧ������ƴ��˳������
{
	{
		system("cls");                               //����
		int n,i=0,j,sum=0;
		printf("������༶�ţ�");
		scanf("%d", &n);
		struct Student a,b[40],t;
		FILE* p;
		p = fopen("sText.txt", "r");
		printf("���   ����      ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����    ��ѧ��\n");
		while (!feof(p))                             //���������༶������
		{
			fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
			a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
			if (a.num / 100 == n)
			{
				b[i] = a;
				sum++;                               //ͳ�ư༶���������ں�������
				i++;
			}
		}
		for (i = 0; i <sum-1; i++)                   //���༶��������ѧ������ƴ��˳������
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

void refercourse()                                     //��ĳ��γ̣����δ�ﵽҪ���ѧ������
{
	system("cls");                                     //����
	char c[20];
	int i=0,n,k;
	printf("������γ����ƣ�\n");
	flag_reinput:
	scanf("%s", c);
	if (strcmp(c, "������") == 0)                      //�жϿγ�����Լ���Ӧ��׼
	{
		n = 0;
		k = 50;
	}
	else if (strcmp(c, "רҵ������") == 0)
	{
		n = 1;
		k = 50;
	}
	else if (strcmp(c, "רҵ��") == 0)
	{
		n = 2;
		k = 36;
	}
	else if (strcmp(c, "רҵѡ�޿�") == 0)
	{
		n = 3;
		k = 24;
	}
	else if (strcmp(c, "ʵ�����") == 0)
	{
		n = 4;
		k = 40;
	}
	else
	{
		printf("�����������������γ����ƣ�\n");
		goto flag_reinput;                               //��������󣻷�����������
	}
	struct Student a;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("δ���ѧ��������\n");
	printf("���   ����      ѧ��    ����\n");
	while (!feof(p))
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];
		if (a.classes[n]<k)                               //���δ����ѧ������
		{
			
			printf("%-2d   %-8s   %6d    %2d\n", i+1, a.name,a.num,a.classes[n]);
			i++;
		}
	}
	fclose(p);
	system("pause");
}


void referstandard_meet()                                  //�������ҵ������ѧ����,���Ӹߵ��͵ķ���������
{
	system("cls");                                         //����
	struct Student a,b[1000],t;
	int i = 0, sum = 0,j;
	FILE* p;
	p = fopen("sText.txt", "r");
	printf("���   ����      ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����\n");
	while (!feof(p))                                       //����ϸ�ѧ������
	{
		fscanf(p, "%s %d %d %d %d %d %d", a.name, &a.num, &a.classes[0], &a.classes[1], &a.classes[2], &a.classes[3], &a.classes[4]);
		a.classes[5] = a.classes[0] + a.classes[1] + a.classes[2] + a.classes[3] + a.classes[4];         //��ÿ��ѧ����ѧ��
		if (a.classes[0]>=50&& a.classes[1]>=50&& a.classes[2]>=36&& a.classes[3]>=24&& a.classes[4]>=40)
		{
			b[i] = a;
			sum++;                                         //ͳ�ƺϸ����������ں�������
			i++;
		}
	}
	for (i = 0; i < sum - 1; i++)                          //����ѧ������
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
	printf("�����ҵ����ѧ��������\n");
	printf("���   ����      ѧ��    ������   רҵ������   רҵ��   רҵѡ�޿�   ʵ�����    ��ѧ��\n");
	for (i = 0; i < sum; i++)
		printf("%-3d    %-6s   %6d    %2d        %2d            %2d        %2d            %2d     %3d\n", i + 1, b[i].name, b[i].num, b[i].classes[0], b[i].classes[1], b[i].classes[2], b[i].classes[3], b[i].classes[4], b[i].classes[5]);
	fclose(p);
	system("pause");
}