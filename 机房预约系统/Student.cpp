
//#include<iostream>
//using namespace std;
#include"Student.h"


//默认构造函数
Student:: Student()
{

}

//操作菜单
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//有参构造函数
Student::Student(int id,string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房容器
	this->Initcomputer();
		//获取机房信息
	//ifstream ifs;
	//ifs.open(COMPUTERROOM_FILE, ios::in);

	//Computer c;
	//while (ifs >> c.m_comid && ifs >> c.m_nummax)
	//{
	//	vCom.push_back(c);
	//}

	//ifs.close();
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int data=0;//日期
	int interval=0;//时间段
	int room=0;//机房号

	while (1)//选择周几
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "请选择你的时间段" <<endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (1)//选择时间段
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入!" << endl;
	}
	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_comid << "号机房的容量：" << vCom[i].m_nummax << endl;
	}
	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	cout << "预约成功，审核中！" << endl;
	ofs << "日期：" << data << " ";
	ofs << "时间段：" << interval << " ";
	ofs << "机房编号：" << room << " ";
	ofs << "预约学号：" << this->m_id << " ";
	ofs << "预约姓名：" << this->m_name << " ";
	ofs << "预约状态：" << "审核中" << endl;
	ofs.close();
}

////申请预约
//void Student::applyOrder()
//{
//	cout << "机房开放时间为周一至周五！" << endl;
//	cout << "请输入申请预约的时间：" << endl;
//	cout << "1、周一" << endl;
//	cout << "2、周二" << endl;
//	cout << "3、周三" << endl;
//	cout << "4、周四" << endl;
//	cout << "5、周五" << endl;
//	int date = 0;
//	int interval = 0;
//	int room = 0;
//
//	while (true)
//	{
//		cin >> date;
//		if (date >= 1 && date <= 5)
//		{
//			break;
//		}
//		cout << "输入有误，请重新输入" << endl;
//	}
//
//
//	cout << "请输入申请预约的时间段：" << endl;
//	cout << "1、上午" << endl;
//	cout << "2、下午" << endl;
//
//	while (true)
//	{
//		cin >> interval;
//		if (interval >= 1 && interval <= 2)
//		{
//			break;
//		}
//		cout << "输入有误，请重新输入" << endl;
//	}
//
//	cout << "请选择机房：" << endl;
//	cout << "1号机房容量：" << vCom[0].m_nummax << endl;
//	cout << "2号机房容量：" << vCom[1].m_nummax << endl;
//	cout << "3号机房容量：" << vCom[2].m_nummax << endl;
//
//	while (true)
//	{
//		cin >> room;
//		if (room >= 1 && room <= 3)
//		{
//			break;
//		}
//		cout << "输入有误，请重新输入" << endl;
//	}
//
//	cout << "预约成功！审核中" << endl;
//
//	ofstream ofs(ORDER_FILE, ios::app);
//	ofs << "date:" << date << " ";
//	ofs << "interval:" << interval << " ";
//	ofs << "stuId:" << this->m_id << " ";
//	ofs << "stuName:" << this->m_name << " ";
//	ofs << "roomId:" << room << " ";
//	ofs << "status:" << 1 << endl;
//
//	ofs.close();
//
//	system("pause");
//	system("cls");
//}

//查看预约
void Student::showMyOrder()
{

}

//查看所有预约
void Student::showAllOrder()
{

}

//取消预约
void Student::canleOrder()
{

}

//学生操作菜单
void StudentMenu(Identity*& person)
{
	while (1)
	{
		//打印菜单
		person->operMenu();
		//强转类型
		Student* stu = (Student*)person;
		//用户进行选择
		int select = 0;
		cin >> select;

		if (select==1)
		{
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//查看所有预约
			stu->showMyOrder();
		}
		else if (select == 4)
		{
			//取消预约
			stu->canleOrder();
		}
		else
		{
			cout << "注销登录成功！" << endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
	}
}


//创建初始化机房的函数
void  Student::Initcomputer()
{
	//读出机房信息
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//创建临时变量
	Computer c;
	while (ifs >> c.m_comid && ifs >> c.m_nummax)
	{
		vCom.push_back(c);
	}
	ifs.close();


}