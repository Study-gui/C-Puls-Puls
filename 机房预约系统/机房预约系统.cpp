
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"glabalFile.h"
#include"Identity.h"
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"orderFile.h"



//登录功能 参数一：对应文件，参数二：对应的身份
void LoginIn(string filename,int type)
{
   //创建身份
	Identity* person=NULL;

	//创建文件
	ifstream ifs;
	//打开指定文件进行写文件
	ifs.open(filename, ios::in);
	//判断文件是否为空
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//创建登录信息
	string name;
	int id=0;
	string pwd;
	//学生
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	//教师
	else if (type==2)
	{
		cout << "请输入您的教职工号" << endl;
		cin >> id;
	}
	cout << "请输入你的用户名：" << endl;
	cin >> name;

	cout << "请输入您的密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录身份验证
		int fid=0;//文件读取的id
		string fname;//文件读取的用户名
		string fpwd;//文件读取的密码
		//读取文件的信息
		while (ifs >>  fid && ifs >>  fname && ifs >>  fpwd)//一行一行读取，遇到空格停止
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录成功" << endl;
				person = new Student(id, name, pwd);//创建一个学生类
				system("pause");
				system("cls");
				//进入学生菜单
				StudentMenu(person);
				return ;
			}
		}
	}
	else if (type == 2)
	{
		//老师身份验证
		int fid=0;//文件读取的id
		string fname;//文件读取的用户名
		string fpwd;//文件读取的密码
		//读取文件的信息
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)//一行一行读取，遇到空格停止
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师登录成功" << endl;
				person = new Teacher(id, name, pwd);//创建一个老师类
				system("pause");
				system("cls");
				//进入教师菜单
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fname;//文件读取的管理员用户名
		string fpwd;//文件读取的管理员密码
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);//创建管理员类
			    //进入管理员菜单
				ManagerMenu(person);
				return;
			}
		}

	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}



//预约菜单
void menu()
{
	cout << "=====================================  欢迎来到机房预约系统=====================" << endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               1.学生代表                  |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               2.老师                      |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               3.管理员                    |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               0/退出                      |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t---------------------------------------------\n";
	cout << "请输入您的选择： " << endl;
}
int main()
{
	int select = 0;
	while (1)
	{

		menu();
		cin >> select;//根据用户选择
		switch (select) 
		{
		case 1://学生操作
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师操作
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员操作
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "退出系统，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default://其他
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}