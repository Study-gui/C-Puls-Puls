
#include"Manager.h"
#include<fstream>
#include"glabalFile.h"
#include<algorithm>


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι��죬����Ա����������Ա����
Manager::Manager(string name, string Pwd)
{
	this->m_name = name;
	this->m_pwd = Pwd;

	//��ʼ��ѧ���ͽ�ʦ��������ȡ��Ϣ
	this->Initvector();

	//��ʼ��������Ϣ
	this->Initcomputer();
}

//����Ա�����˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}



//����˺�
void Manager::AddPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string errortip;//��ʾ�ظ��Ĵ������
	string fname;//Ҫ��ӵ��ļ���
	ofstream ofs;//Ҫд����ļ�

	int select = 0;//ѡ���������
	cin >> select;
	if (select == 1)
	{
		fname = STUDENT_FILE;
		errortip = "ѧ��ѧ�����ظ�,����������";
		cout << "������ѧ����ѧ�ţ�" << endl;
	}
	else if (select == 2)
	{
		fname = TEACHER_FILE;
		errortip = "��ְ������ظ�������������";
		cout << "�������ְ���ţ�" << endl;
	}

	ofs.open(fname, ios::out | ios::app);//��׷�ӵ���ʽ��д�ļ�

	int id=0;
	string name;
	string pwd;
 
	while (1)
	{
		cin >> id;
		bool ret = this->cheekRapeat(id, select);
		if (ret)//Ϊ������ظ�
		{
			cout << errortip << endl;
		}
		else {
			break;
		}

	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�!" << endl;

	
	system("pause");
	system("cls");
	this->Initvector();
	ofs.close();
}
//student�º���
void printstudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << " ������" << s.m_name << " ѧ�����룺" << s.m_pwd << endl;
}
//teacher�º���
void printteacher(Teacher& t)
{
	cout << "��ְ���ţ�" << t.m_EmpId << " ������" << t.m_name << " ��ʦ���룺" << t.m_pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	
	int select = 0;
	cin >> select;
	if (select == 1)//��ʾΪ��ʾѧ����Ϣ
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else {
		cout << "���н�ʦ��Ϣ����" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}


//�鿴������Ϣ
void Manager::showComputerroom()
{
	cout << "������Ϣ����" << endl;
	for (vector<Computer>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ�" << it->m_comid << " ��������������" << it->m_nummax << endl;
	}
	system("pause");
	system("cls");
}


//���ԤԼ��¼
void Manager::cleanFlie()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��������Ա�����˵�
void ManagerMenu(Identity*& manager)
{
	//
	while (1)
	{
		//���ö�̬�������Ա�˵�
		manager->operMenu();
		//��managerǿתΪ����Ա���ͣ��Ա�ʹ�����ĳ�Ա����
		Manager* man = (Manager*)manager;
		//�û�����ѡ��
		int select = 0;

		cin >> select;

		if (select == 1)//����˺�
		{
			//����˺�
			man->AddPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//�鿴�˺�
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			//�鿴����
			man->showComputerroom();
		}
		else if (select == 4)//���ԤԼ
		{
			//���ԤԼ
			man->cleanFlie();
		}
		else {
			cout << "ע���ɹ���" << endl;
			delete man;
			system("pause");
			system("cls");
			return;
		}


	}
}

//������ʼ�������ĺ���
void Manager::Initvector()
{
	//�������
	vstu.clear();
	vtea.clear();

	//�õ�ѧ������Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	//�ж��ͷŴ򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//������ʱ����
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vstu.push_back(s);
	}
	cout << "��ǰѧ��������" <<vstu.size() << endl;
	ifs.close();

	//��ȡ��ʦ����Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//������ʱ����
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ��������" << vtea.size()<<endl;
	ifs.close();

}


//������ʼ��
void Manager::Initcomputer()
{
	//��ȡ������Ϣ
	ifstream ifs;

	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Computer com;

	while (ifs >> com.m_comid && ifs >> com.m_nummax)
	{
		vcom.push_back(com);
	}

	cout << "��ǰ��������Ϊ�� " << vcom.size() << endl;

	ifs.close();

}

//�����鿴id�Ƿ��ظ��ĺ�����trueΪ�ظ���falseΪ���ظ�
bool Manager::cheekRapeat(int id, int type)
{
	if (type == 1)//��ʾ��ѧ��id
	{
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else//��ʾΪ��ʦid
	{
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}