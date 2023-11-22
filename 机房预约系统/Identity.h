#pragma once
#include<iostream>
using namespace std;


//身份基类
class Identity
{
public:
	//操作菜单
	virtual void operMenu() = 0;

	//用户名
	string m_name;
	
	//密码
	string m_pwd;

};