
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



//��¼���� ����һ����Ӧ�ļ�������������Ӧ�����
void LoginIn(string filename,int type)
{
   //�������
	Identity* person=NULL;

	//�����ļ�
	ifstream ifs;
	//��ָ���ļ�����д�ļ�
	ifs.open(filename, ios::in);
	//�ж��ļ��Ƿ�Ϊ��
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//������¼��Ϣ
	string name;
	int id=0;
	string pwd;
	//ѧ��
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	//��ʦ
	else if (type==2)
	{
		cout << "���������Ľ�ְ����" << endl;
		cin >> id;
	}
	cout << "����������û�����" << endl;
	cin >> name;

	cout << "�������������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼�����֤
		int fid=0;//�ļ���ȡ��id
		string fname;//�ļ���ȡ���û���
		string fpwd;//�ļ���ȡ������
		//��ȡ�ļ�����Ϣ
		while (ifs >>  fid && ifs >>  fname && ifs >>  fpwd)//һ��һ�ж�ȡ�������ո�ֹͣ
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����¼�ɹ�" << endl;
				person = new Student(id, name, pwd);//����һ��ѧ����
				system("pause");
				system("cls");
				//����ѧ���˵�
				StudentMenu(person);
				return ;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fid=0;//�ļ���ȡ��id
		string fname;//�ļ���ȡ���û���
		string fpwd;//�ļ���ȡ������
		//��ȡ�ļ�����Ϣ
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)//һ��һ�ж�ȡ�������ո�ֹͣ
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				person = new Teacher(id, name, pwd);//����һ����ʦ��
				system("pause");
				system("cls");
				//�����ʦ�˵�
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fname;//�ļ���ȡ�Ĺ���Ա�û���
		string fpwd;//�ļ���ȡ�Ĺ���Ա����
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);//��������Ա��
			    //�������Ա�˵�
				ManagerMenu(person);
				return;
			}
		}

	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}



//ԤԼ�˵�
void menu()
{
	cout << "=====================================  ��ӭ��������ԤԼϵͳ=====================" << endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               1.ѧ������                  |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               2.��ʦ                      |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               3.����Ա                    |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t|               0/�˳�                      |\n";
	cout << "\t\t|                                           |\n";
	cout << "\t\t---------------------------------------------\n";
	cout << "����������ѡ�� " << endl;
}
int main()
{
	int select = 0;
	while (1)
	{

		menu();
		cin >> select;//�����û�ѡ��
		switch (select) 
		{
		case 1://ѧ������
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ����
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա����
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "�˳�ϵͳ����ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default://����
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}