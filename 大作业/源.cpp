
#include<Function declaration.h>                              //�����������ļ�
void main()                                                   //������  
{	int n,g=0,x=0,g1,g2,g3,g4;
	flag:                                                     //��¼����
	n=form();
	switch (n) 
	{
	case 1:g=Gmima(); break;                                  //����Ա��¼
	case 2:x=Xmima(); break;                                  //ѧ����¼
	default:return;
	}
	if (g)                                                    //����Ա����
	{
		flag_g:
		g = mselect();                                        //����Ա���˵�
		switch (g)
		{
		case 1: flag_g1: g1 = query();                        //ѧ����Ϣ��ѧ����Ϣ��ѯ ,flag_g1Ϊ��ѯ�˵�
		    {
			switch (g1)
			{
			case 1:refernumber();        goto flag_g1;       //��ѧ�Ų�ѯѧ����Ϣ��goto flag_g1;������ڷ��ز�ѯ�˵�
			case 2:refernumber_class();  goto flag_g1;       //���༶�Ų�ѯѧ����Ϣ
			case 3:referclass();         goto flag_g1;       //���༶��ѯѧ����Ϣ��������ƴ��˳������
			case 4:refercourse();        goto flag_g1;       //��ĳ��γ����δ�ﵽҪ���ѧ������
			case 5:referstandard_meet(); goto flag_g1;       //�������ҵ������ѧ����,���Ӹߵ��͵ķ���������
			case 0:goto flag_g;                              //���ع���Ա���˵�
			default:return;                                  //�˳�����
			}                                   
		case 2:flag_g2:g2 = mmanage();                       //ѧ��������� ����ѯ���޸�ѧ�����룩�˵�
			switch (g2)
			{
			case 1:querym_stdudent(); goto flag_g2;          //��ѯѧ�����룻goto flag_g2;���ڷ���ѧ���������˵�
			case 2:modifym_stdudent(); goto flag_g2;         //�޸�ѧ������
			case 0:goto flag_g;                              //���ع���Ա���˵�
			default:return;                                  //�˳�����
			}
		case 3:flag_g3:g3 = statistic();                     //���ݹ���ͳ�ƣ�
			switch (g3)
			{
			case 1:dataadd(); goto flag_g3;                  //������ݣ�goto flag_g2;���ڷ������ݹ���˵�
			case 2:data_modify(); goto flag_g3;              //�޸�����
			case 3:data_delete(); goto flag_g3;              //ɾ������
			case 0:goto flag_g;                              //���ع���Ա���˵�
			default:return;                                  //�˳�����
			}
		case 4: GmimaXG(); goto flag_g;                      //�޸����� 
		case 0:goto flag;                                    //�˳���¼
		default:return;                                      //�˳�����
		}                                                    
		}
	}
	if (x)                                                   //ѧ������
	{
	flag_x:                                                  
		x = sselect();                                      //ѧ�����˵�
		switch(x)

		{ 
		case 1:  studentself(); goto flag_x;                //����ѧ����Ϣ��ѯ�� goto flag_x;������ڷ������˵�
		case 2:  XmimaXG(); goto flag_x;                    //�޸�����
		case 0:goto flag;                                   //�˳���¼
		default:return;                                     //�˳�����
		}
	}
	goto flag;
}