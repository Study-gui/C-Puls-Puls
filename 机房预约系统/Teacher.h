#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Identity.h"

//创建教师类
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造，教师编号，教师密码，教师姓名
	Teacher(int EmpId,string name, string Pwd);

	//操作菜单
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void VailOrder();

	//教职工编号
	int m_EmpId;

};