#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Identity.h"

//������ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죬��ʦ��ţ���ʦ���룬��ʦ����
	Teacher(int EmpId,string name, string Pwd);

	//�����˵�
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void VailOrder();

	//��ְ�����
	int m_EmpId;

};