
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

	int date=0;//日期
	int interval=0;//时间段
	int room=0;//机房号

	while (1)//选择周几
	{
		cin >> date;
		if (date >= 1 && date <= 5)
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
	cout << "预约成功，审核中！" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	
	/*ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;*/
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;


	ofs.close();


	system("pause");
	system("cls");
}


//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	//判断是否预约
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//查找自身预约
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		//将string转为int
		//1 将string通过c_str（）转为const char*
		//2 利用atoi(const char* )转为int
		if (m_id == atoi(of.m_orderdata[i]["stuId"].c_str()))
		{
			cout << "预约日期:周 " << of.m_orderdata[i]["date"];
			cout << " 时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房编号:" << of.m_orderdata[i]["roomId"];
			//设置预约状态标志
			string status=" 状态：";// 1 审核中 ，2 预约成功 ，-1 预约失败  
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
	}
	system("pause");
	system("cls");

}

//查看所有预约
void Student::showAllOrder()
{
	//创建预约文件类
	OrderFile of;
	//判断是否有预约记录
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//拿到所有文件
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

//取消预约
void Student::canleOrder()
{
	OrderFile of;
	//判断
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>v;
	//存放我的记录条数
	int index = 1;
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		if (m_id == atoi(of.m_orderdata[i]["stuId"].c_str()))
		{
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")
			{
				cout << index++ << "、";
				v.push_back(i);
				cout << "预约日期:周 " << of.m_orderdata[i]["date"];
				cout << " 时段:" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号:" << of.m_orderdata[i]["roomId"];
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
			
		}
	}
	cout << "请输入你要取消的预约,0表示返回：" << endl;
	int select = 0;//0 表示要不取消预约的操作
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			of.m_orderdata[v[select - 1]]["status"] = "0";
			//更新一下预约记录
			of.updataorder();
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "预约已取消" << endl;
	system("pause");
	system("cls");

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
			stu->showAllOrder();
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