
//#include<iostream>
//using namespace std;
#include"Student.h"


//Ĭ�Ϲ��캯��
Student:: Student()
{

}

//�����˵�
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�вι��캯��
Student::Student(int id,string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ����������
	this->Initcomputer();
		//��ȡ������Ϣ
	//ifstream ifs;
	//ifs.open(COMPUTERROOM_FILE, ios::in);

	//Computer c;
	//while (ifs >> c.m_comid && ifs >> c.m_nummax)
	//{
	//	vCom.push_back(c);
	//}

	//ifs.close();
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int data=0;//����
	int interval=0;//ʱ���
	int room=0;//������

	while (1)//ѡ���ܼ�
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "��ѡ�����ʱ���" <<endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (1)//ѡ��ʱ���
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������!" << endl;
	}
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_comid << "�Ż�����������" << vCom[i].m_nummax << endl;
	}
	while (1)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	cout << "ԤԼ�ɹ�������У�" << endl;
	ofs << "���ڣ�" << data << " ";
	ofs << "ʱ��Σ�" << interval << " ";
	ofs << "������ţ�" << room << " ";
	ofs << "ԤԼѧ�ţ�" << this->m_id << " ";
	ofs << "ԤԼ������" << this->m_name << " ";
	ofs << "ԤԼ״̬��" << "�����" << endl;
	ofs.close();
}

////����ԤԼ
//void Student::applyOrder()
//{
//	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
//	cout << "����������ԤԼ��ʱ�䣺" << endl;
//	cout << "1����һ" << endl;
//	cout << "2���ܶ�" << endl;
//	cout << "3������" << endl;
//	cout << "4������" << endl;
//	cout << "5������" << endl;
//	int date = 0;
//	int interval = 0;
//	int room = 0;
//
//	while (true)
//	{
//		cin >> date;
//		if (date >= 1 && date <= 5)
//		{
//			break;
//		}
//		cout << "������������������" << endl;
//	}
//
//
//	cout << "����������ԤԼ��ʱ��Σ�" << endl;
//	cout << "1������" << endl;
//	cout << "2������" << endl;
//
//	while (true)
//	{
//		cin >> interval;
//		if (interval >= 1 && interval <= 2)
//		{
//			break;
//		}
//		cout << "������������������" << endl;
//	}
//
//	cout << "��ѡ�������" << endl;
//	cout << "1�Ż���������" << vCom[0].m_nummax << endl;
//	cout << "2�Ż���������" << vCom[1].m_nummax << endl;
//	cout << "3�Ż���������" << vCom[2].m_nummax << endl;
//
//	while (true)
//	{
//		cin >> room;
//		if (room >= 1 && room <= 3)
//		{
//			break;
//		}
//		cout << "������������������" << endl;
//	}
//
//	cout << "ԤԼ�ɹ��������" << endl;
//
//	ofstream ofs(ORDER_FILE, ios::app);
//	ofs << "date:" << date << " ";
//	ofs << "interval:" << interval << " ";
//	ofs << "stuId:" << this->m_id << " ";
//	ofs << "stuName:" << this->m_name << " ";
//	ofs << "roomId:" << room << " ";
//	ofs << "status:" << 1 << endl;
//
//	ofs.close();
//
//	system("pause");
//	system("cls");
//}

//�鿴ԤԼ
void Student::showMyOrder()
{

}

//�鿴����ԤԼ
void Student::showAllOrder()
{

}

//ȡ��ԤԼ
void Student::canleOrder()
{

}

//ѧ�������˵�
void StudentMenu(Identity*& person)
{
	while (1)
	{
		//��ӡ�˵�
		person->operMenu();
		//ǿת����
		Student* stu = (Student*)person;
		//�û�����ѡ��
		int select = 0;
		cin >> select;

		if (select==1)
		{
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 4)
		{
			//ȡ��ԤԼ
			stu->canleOrder();
		}
		else
		{
			cout << "ע����¼�ɹ���" << endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
	}
}


//������ʼ�������ĺ���
void  Student::Initcomputer()
{
	//����������Ϣ
	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//������ʱ����
	Computer c;
	while (ifs >> c.m_comid && ifs >> c.m_nummax)
	{
		vCom.push_back(c);
	}
	ifs.close();


}