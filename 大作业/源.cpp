
#include<Function declaration.h>                              //函数声明的文件
void main()                                                   //主函数  
{	int n,g=0,x=0,g1,g2,g3,g4;
	flag:                                                     //登录界面
	n=form();
	switch (n) 
	{
	case 1:g=Gmima(); break;                                  //管理员登录
	case 2:x=Xmima(); break;                                  //学生登录
	default:return;
	}
	if (g)                                                    //管理员功能
	{
		flag_g:
		g = mselect();                                        //管理员主菜单
		switch (g)
		{
		case 1: flag_g1: g1 = query();                        //学生信息及学分信息查询 ,flag_g1为查询菜单
		    {
			switch (g1)
			{
			case 1:refernumber();        goto flag_g1;       //按学号查询学生信息；goto flag_g1;语句用于返回查询菜单
			case 2:refernumber_class();  goto flag_g1;       //按班级号查询学生信息
			case 3:referclass();         goto flag_g1;       //按班级查询学生信息按照姓名拼音顺序排列
			case 4:refercourse();        goto flag_g1;       //按某类课程输出未达到要求的学生名单
			case 5:referstandard_meet(); goto flag_g1;       //在满足毕业条件的学生中,按从高到低的分数列名单
			case 0:goto flag_g;                              //返回管理员主菜单
			default:return;                                  //退出程序
			}                                   
		case 2:flag_g2:g2 = mmanage();                       //学生密码管理 （查询或修改学生密码）菜单
			switch (g2)
			{
			case 1:querym_stdudent(); goto flag_g2;          //查询学生密码；goto flag_g2;用于返回学生密码管理菜单
			case 2:modifym_stdudent(); goto flag_g2;         //修改学生密码
			case 0:goto flag_g;                              //返回管理员主菜单
			default:return;                                  //退出程序
			}
		case 3:flag_g3:g3 = statistic();                     //数据管理（统计）
			switch (g3)
			{
			case 1:dataadd(); goto flag_g3;                  //添加数据；goto flag_g2;用于返回数据管理菜单
			case 2:data_modify(); goto flag_g3;              //修改数据
			case 3:data_delete(); goto flag_g3;              //删除数据
			case 0:goto flag_g;                              //返回管理员主菜单
			default:return;                                  //退出程序
			}
		case 4: GmimaXG(); goto flag_g;                      //修改密码 
		case 0:goto flag;                                    //退出登录
		default:return;                                      //退出程序
		}                                                    
		}
	}
	if (x)                                                   //学生功能
	{
	flag_x:                                                  
		x = sselect();                                      //学生主菜单
		switch(x)

		{ 
		case 1:  studentself(); goto flag_x;                //本人学分信息查询； goto flag_x;语句用于返回主菜单
		case 2:  XmimaXG(); goto flag_x;                    //修改密码
		case 0:goto flag;                                   //退出登录
		default:return;                                     //退出程序
		}
	}
	goto flag;
}