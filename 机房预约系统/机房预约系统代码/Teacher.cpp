
#include"Teacher.h"




//默认构造
Teacher::Teacher()
{

}

//有参构造，教师编号，教师密码，教师姓名
Teacher::Teacher(int EmpId,string name, string Pwd)
{
	this->m_EmpId = EmpId;
	this->m_name = name;
	this->m_pwd = Pwd;
}

//操作菜单
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	//判断
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	//显示所有预约记录
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		cout << i << "、";
		cout << "预约日期:周 " << of.m_orderdata[i]["date"];
		cout << " 时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房编号:" << of.m_orderdata[i]["roomId"];
		cout << " 学生学号:" << of.m_orderdata[i]["sutId"];
		cout << " 学生姓名:" << of.m_orderdata[i]["stuName"];
		//设置预约状态标志
		string status = " 状态：";// 1 审核中 ，2 预约成功 ，-1 预约失败  
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else {
			status += "预约以取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::VailOrder()
{
	OrderFile of;
	//判断
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	//拿到所有文件
	cout << "待审核的预约记录如下：" << endl;
	vector<int>v;//存放状态时审核中的i值
	int index = 1;
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{//1 审核中，2 预约成功 ,-1 表示预约失败 ，0  预约取消  
		if (of.m_orderdata[i]["status"] == "1")
		{
			cout << index++ << "、 ";
			v.push_back(i);
			cout << "预约日期: 周" << of.m_orderdata[i]["date"];
			cout << " 时段: " << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房: " << of.m_orderdata[i]["roomId"];
			cout << " 学生学号:" << of.m_orderdata[i]["sutId"];
			cout << " 学生姓名:" << of.m_orderdata[i]["stuName"];
			cout << " 状态: " << of.m_orderdata[i]["status"] << endl;
		}
	}
	cout << "请输入审核的预约记录,0代表返回" << endl;
	//用户选择
	int select = 0;//选择第几条
	int ret = 0;//选择是否通过
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			cout << "请输入审核结果" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
			cin >> ret;
			if (ret == 1)
			{
				of.m_orderdata[v[select - 1]]["status"] = "2";
			}
			else if (ret == 2)
			{
				of.m_orderdata[v[select - 1]]["status"] = "-1";
			}

			//更新预约
			of.updataorder();

			break;

		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}

	system("pause");
	system("cls");

}

//创建教师操作子菜单
void TeacherMenu(Identity*& person)
{

	while (1)
	{
		//利用多态打印菜单
		person->operMenu();
		//转换
		Teacher* tea = (Teacher*)person;

		//用户进行选择
		int select = 0;
		cin >> select;

		//查看所有预约
		if (select == 1)
		{
			tea->showAllOrder();
		}

		//审核预约
		else if (select == 2)
		{
			tea->VailOrder();
		}

		else {
			delete tea;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return ;
		}

	
	}


}
