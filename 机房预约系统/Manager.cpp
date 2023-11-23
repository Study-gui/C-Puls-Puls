
#include"Manager.h"
#include<fstream>
#include"glabalFile.h"
#include<algorithm>


//默认构造
Manager::Manager()
{

}

//有参构造，管理员姓名，管理员密码
Manager::Manager(string name, string Pwd)
{
	this->m_name = name;
	this->m_pwd = Pwd;

	//初始化学生和教师容器，读取信息
	this->Initvector();

	//初始化机房信息
	this->Initcomputer();
}

//管理员操作菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}



//添加账号
void Manager::AddPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string errortip;//表示重复的错误输出
	string fname;//要添加的文件名
	ofstream ofs;//要写入的文件

	int select = 0;//选择添加类型
	cin >> select;
	if (select == 1)
	{
		fname = STUDENT_FILE;
		errortip = "学生学号有重复,请重新输入";
		cout << "请输入学生的学号：" << endl;
	}
	else if (select == 2)
	{
		fname = TEACHER_FILE;
		errortip = "教职工编号重复，请重新输入";
		cout << "请输入教职工号：" << endl;
	}

	ofs.open(fname, ios::out | ios::app);//以追加的形式，写文件

	int id=0;
	string name;
	string pwd;
 
	while (1)
	{
		cin >> id;
		bool ret = this->cheekRapeat(id, select);
		if (ret)//为真就有重复
		{
			cout << errortip << endl;
		}
		else {
			break;
		}

	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功!" << endl;

	
	system("pause");
	system("cls");
	this->Initvector();
	ofs.close();
}
//student仿函数
void printstudent(Student& s)
{
	cout << "学号：" << s.m_id << " 姓名：" << s.m_name << " 学生密码：" << s.m_pwd << endl;
}
//teacher仿函数
void printteacher(Teacher& t)
{
	cout << "教职工号：" << t.m_EmpId << " 姓名：" << t.m_name << " 教师密码：" << t.m_pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	
	int select = 0;
	cin >> select;
	if (select == 1)//表示为显示学生信息
	{
		cout << "所有学生信息如下" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else {
		cout << "所有教师信息如下" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}


//查看机房信息
void Manager::showComputerroom()
{
	cout << "机房信息如下" << endl;
	for (vector<Computer>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号：" << it->m_comid << " 机房电脑数量：" << it->m_nummax << endl;
	}
	system("pause");
	system("cls");
}


//清空预约记录
void Manager::cleanFlie()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//建立管理员操作菜单
void ManagerMenu(Identity*& manager)
{
	//
	while (1)
	{
		//利用多态进入管理员菜单
		manager->operMenu();
		//将manager强转为管理员类型，以便使用他的成员函数
		Manager* man = (Manager*)manager;
		//用户输入选择
		int select = 0;

		cin >> select;

		if (select == 1)//添加账号
		{
			//添加账号
			man->AddPerson();
		}
		else if (select == 2)//查看账号
		{
			//查看账号
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			//查看机房
			man->showComputerroom();
		}
		else if (select == 4)//清空预约
		{
			//清空预约
			man->cleanFlie();
		}
		else {
			cout << "注销成功！" << endl;
			delete man;
			system("pause");
			system("cls");
			return;
		}


	}
}

//创建初始化容器的函数
void Manager::Initvector()
{
	//清空容器
	vstu.clear();
	vtea.clear();

	//拿到学生的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	//判断释放打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//创建临时对象
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vstu.push_back(s);
	}
	cout << "当前学生数量：" <<vstu.size() << endl;
	ifs.close();

	//读取老师的信息
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//创建临时对象
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);
	}
	cout << "当前教师的数量：" << vtea.size()<<endl;
	ifs.close();

}


//机房初始化
void Manager::Initcomputer()
{
	//获取机房信息
	ifstream ifs;

	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	Computer com;

	while (ifs >> com.m_comid && ifs >> com.m_nummax)
	{
		vcom.push_back(com);
	}

	cout << "当前机房数量为： " << vcom.size() << endl;

	ifs.close();

}

//创建查看id是否重复的函数，true为重复，false为不重复
bool Manager::cheekRapeat(int id, int type)
{
	if (type == 1)//表示是学生id
	{
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else//表示为教师id
	{
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}