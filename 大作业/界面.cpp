#include<stdio.h>
#include <stdlib.h>

int form()                                           //��¼����
{
	system("cls");   //����
	int n;
	printf("\t\t   ��--------------------��\n");
	printf("\t\t   �� 1. ����Ա��¼      ��\n");
	printf("\t\t   �� 2. ѧ����¼        ��\n");
	printf("\t\t   �� �������֣��˳����� ��\n");
	printf("\t\t   ��--------------------��\n");
	printf("\t\t     ����ѡ��(1-2):");
	scanf("%d", &n);
	return n;
}
	int sselect()                                     //ѧ�����˵�
	{
		int n;
		system("cls"); 
		printf("\t\t   ��----------------------��\n");
		printf("\t\t   �� 1. ����ѧ����Ϣ��ѯ  ��\n");
		printf("\t\t   �� 2. �޸�����          ��\n");
		printf("\t\t   �� 0. �˳���¼          ��\n");
		printf("\t\t   �� �������֣��˳�����   ��\n");
		printf("\t\t   ��----------------------��\n");
		printf("\t\t     ����ѡ��(0-2):");
		scanf("%d", &n);
		return n;
	}
	int mselect()                                        //����Ա���˵� 
	{
		int n;
		system("cls"); 
		printf("\t\t   ��----------------------------��\n");
		printf("\t\t   �� 1. ѧ����Ϣ��ѧ����Ϣ��ѯ  ��\n");
		printf("\t\t   �� 2. ѧ���������            ��\n");
		printf("\t\t   �� 3. ���ݹ���                ��\n");
		printf("\t\t   �� 4. �޸�����                ��\n");
		printf("\t\t   �� 0. �˳���¼                ��\n");
		printf("\t\t   �� �������֣��˳�����         ��\n");
		printf("\t\t   ��----------------------------��\n");
		printf("\t\t     ����ѡ��(0-4):");
		scanf("%d", &n);
		return n;
	}
	int query()                                              //��ѯ�˵�
	{
		int n;
		system("cls"); 
		printf("\t\t   ��------------------------------��\n");
		printf("\t\t   �� 1. ��ѧ�Ų�ѯ                ��\n");
		printf("\t\t   �� 2. ���༶�Ų�ѯ              ��\n");
		printf("\t\t   �� 3. ���༶��ѯ                ��\n");
		printf("\t\t   �� 4. ���γ����ѯ��δ����ͬѧ��\n");
		printf("\t\t   �� 5. ��ҵ�����ɼ�����          ��\n");
		printf("\t\t   �� 0. �������˵�                ��\n");
		printf("\t\t   �� �������֣��˳�����           ��\n"); 
		printf("\t\t   ��------------------------------��\n");
		printf("\t\t     ����ѡ��(0-5):");
		scanf("%d", &n);
		return n;
	}
	int statistic()                                       //���ݹ���ͳ�ƣ��˵�
	{
		int n;
		system("cls"); 
		printf("\t\t   ��-------------------��\n");
		printf("\t\t   �� 1. �������       ��\n");
		printf("\t\t   �� 2. �޸�����       ��\n");
		printf("\t\t   �� 3. ɾ������       ��\n");
		printf("\t\t   �� 0. �������˵�     ��\n");
		printf("\t\t   �� �������֣��˳�����\n");
		printf("\t\t   ��-------------------��\n");
		printf("\t\t     ����ѡ��(0-2):");
		scanf("%d", &n);
		return n;
	}

	int mmanage()                                           //ѧ���������˵�
	{
		int n;
		system("cls");
		printf("\t\t   ��----------------------��\n");
		printf("\t\t   �� 1. ��ѯѧ������      ��\n");
		printf("\t\t   �� 2. �޸�ѧ������      ��\n");
		printf("\t\t   �� 0. �������˵�        ��\n");
		printf("\t\t   �� �������֣��˳�����   ��\n");
		printf("\t\t   ��----------------------��\n");
		printf("\t\t     ����ѡ��(0-2):");
		scanf("%d", &n);
		return n;
	}