#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"computerRoom.h"

//创建管理员类
class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造，管理员姓名，管理员密码
	Manager(string name, string Pwd);

	//管理员操作菜单
	virtual void operMenu();

	//添加账号
	void AddPerson();

	//查看账号
	void showPerson();


	//查看机房信息
	void showComputerroom();


	//清空预约记录
	void cleanFlie();

	//创建初始化容器的函数
	void Initvector();

	

	//创建老师的容器
	vector<Teacher>vtea;

	//创建学生的容器
	vector<Student>vstu;

	//创建查看id是否重复的函数，true为重复，false为不重复
	bool cheekRapeat(int id, int type);

	//创建机房类
	vector<Computer>vcom;

	//机房初始化
	void Initcomputer();

};

//建立管理员操作菜单
void ManagerMenu(Identity*& manager);
