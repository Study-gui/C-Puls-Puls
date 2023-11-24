#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"glabalFile.h"
#include"orderFile.h"

class Student :public Identity
{
public:
	//默认构造函数
	Student();

	//有参构造函数,学生姓名，学生密码，学生学号，
	Student(int id,string name, string pwd);

	//操作菜单
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void canleOrder();


	//学生学号
	int m_id;

	//创建初始化机房的函数
	void Initcomputer();

	//创建机房容器
	vector<Computer>vCom;

	
};

//操作子菜单
void StudentMenu(Identity*& person);
