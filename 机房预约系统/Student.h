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
	//Ĭ�Ϲ��캯��
	Student();

	//�вι��캯��,ѧ��������ѧ�����룬ѧ��ѧ�ţ�
	Student(int id,string name, string pwd);

	//�����˵�
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void canleOrder();


	//ѧ��ѧ��
	int m_id;

	//������ʼ�������ĺ���
	void Initcomputer();

	//������������
	vector<Computer>vCom;

	
};

//�����Ӳ˵�
void StudentMenu(Identity*& person);
