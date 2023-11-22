#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"computerRoom.h"

//��������Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��죬����Ա����������Ա����
	Manager(string name, string Pwd);

	//����Ա�����˵�
	virtual void operMenu();

	//����˺�
	void AddPerson();

	//�鿴�˺�
	void showPerson();


	//�鿴������Ϣ
	void showComputerroom();


	//���ԤԼ��¼
	void cleanFlie();

	//������ʼ�������ĺ���
	void Initvector();

	

	//������ʦ������
	vector<Teacher>vtea;

	//����ѧ��������
	vector<Student>vstu;

	//�����鿴id�Ƿ��ظ��ĺ�����trueΪ�ظ���falseΪ���ظ�
	bool cheekRapeat(int id, int type);

	//����������
	vector<Computer>vcom;

	//������ʼ��
	void Initcomputer();

};

//��������Ա�����˵�
void ManagerMenu(Identity*& manager);
