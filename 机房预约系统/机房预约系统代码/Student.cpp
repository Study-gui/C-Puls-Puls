
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

	int date=0;//����
	int interval=0;//ʱ���
	int room=0;//������

	while (1)//ѡ���ܼ�
	{
		cin >> date;
		if (date >= 1 && date <= 5)
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
	cout << "ԤԼ�ɹ�������У�" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	
	/*ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;*/
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;


	ofs.close();


	system("pause");
	system("cls");
}


//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	//�ж��Ƿ�ԤԼ
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//��������ԤԼ
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		//��stringתΪint
		//1 ��stringͨ��c_str����תΪconst char*
		//2 ����atoi(const char* )תΪint
		if (m_id == atoi(of.m_orderdata[i]["stuId"].c_str()))
		{
			cout << "ԤԼ����:�� " << of.m_orderdata[i]["date"];
			cout << " ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " �������:" << of.m_orderdata[i]["roomId"];
			//����ԤԼ״̬��־
			string status=" ״̬��";// 1 ����� ��2 ԤԼ�ɹ� ��-1 ԤԼʧ��  
			if (of.m_orderdata[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderdata[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderdata[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");

}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	//����ԤԼ�ļ���
	OrderFile of;
	//�ж��Ƿ���ԤԼ��¼
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�õ������ļ�
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		cout << i << "��";
		cout << "ԤԼ����:�� " << of.m_orderdata[i]["date"];
		cout << " ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
		cout << " �������:" << of.m_orderdata[i]["roomId"];
		cout << " ѧ��ѧ��:" << of.m_orderdata[i]["sutId"];
		cout << " ѧ������:" << of.m_orderdata[i]["stuName"];
		//����ԤԼ״̬��־
		string status = " ״̬��";// 1 ����� ��2 ԤԼ�ɹ� ��-1 ԤԼʧ��  
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
	
}

//ȡ��ԤԼ
void Student::canleOrder()
{
	OrderFile of;
	//�ж�
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	//����ҵļ�¼����
	int index = 1;
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{
		if (m_id == atoi(of.m_orderdata[i]["stuId"].c_str()))
		{
			if (of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")
			{
				cout << index++ << "��";
				v.push_back(i);
				cout << "ԤԼ����:�� " << of.m_orderdata[i]["date"];
				cout << " ʱ��:" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
				cout << " �������:" << of.m_orderdata[i]["roomId"];
				//����ԤԼ״̬��־
				string status = " ״̬��";// 1 ����� ��2 ԤԼ�ɹ� ��-1 ԤԼʧ��  
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.m_orderdata[i]["status"] == "-1")
				{
					status += "���δͨ����ԤԼʧ��";
				}
				else {
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;
			}
			
		}
	}
	cout << "��������Ҫȡ����ԤԼ,0��ʾ���أ�" << endl;
	int select = 0;//0 ��ʾҪ��ȡ��ԤԼ�Ĳ���
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			of.m_orderdata[v[select - 1]]["status"] = "0";
			//����һ��ԤԼ��¼
			of.updataorder();
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}
	cout << "ԤԼ��ȡ��" << endl;
	system("pause");
	system("cls");

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
			stu->showAllOrder();
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