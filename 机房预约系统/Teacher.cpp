
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

}

//查看所有预约
void Teacher::showAllOrder()
{

}

//审核预约
void Teacher::VailOrder()
{

}

