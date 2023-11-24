
#include"Teacher.h"




//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι��죬��ʦ��ţ���ʦ���룬��ʦ����
Teacher::Teacher(int EmpId,string name, string Pwd)
{
	this->m_EmpId = EmpId;
	this->m_name = name;
	this->m_pwd = Pwd;
}

//�����˵�
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	//�ж�
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	//��ʾ����ԤԼ��¼
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

//���ԤԼ
void Teacher::VailOrder()
{
	OrderFile of;
	//�ж�
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�õ������ļ�
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int>v;//���״̬ʱ����е�iֵ
	int index = 1;
	for (int i = 1; i <= of.m_orderdata.size(); i++)
	{//1 ����У�2 ԤԼ�ɹ� ,-1 ��ʾԤԼʧ�� ��0  ԤԼȡ��  
		if (of.m_orderdata[i]["status"] == "1")
		{
			cout << index++ << "�� ";
			v.push_back(i);
			cout << "ԤԼ����: ��" << of.m_orderdata[i]["date"];
			cout << " ʱ��: " << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " ����: " << of.m_orderdata[i]["roomId"];
			cout << " ѧ��ѧ��:" << of.m_orderdata[i]["sutId"];
			cout << " ѧ������:" << of.m_orderdata[i]["stuName"];
			cout << " ״̬: " << of.m_orderdata[i]["status"] << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼,0������" << endl;
	//�û�ѡ��
	int select = 0;//ѡ��ڼ���
	int ret = 0;//ѡ���Ƿ�ͨ��
	while (1)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			cin >> ret;
			if (ret == 1)
			{
				of.m_orderdata[v[select - 1]]["status"] = "2";
			}
			else if (ret == 2)
			{
				of.m_orderdata[v[select - 1]]["status"] = "-1";
			}

			//����ԤԼ
			of.updataorder();

			break;

		}
		else {
			cout << "������������������" << endl;
		}
	}

	system("pause");
	system("cls");

}

//������ʦ�����Ӳ˵�
void TeacherMenu(Identity*& person)
{

	while (1)
	{
		//���ö�̬��ӡ�˵�
		person->operMenu();
		//ת��
		Teacher* tea = (Teacher*)person;

		//�û�����ѡ��
		int select = 0;
		cin >> select;

		//�鿴����ԤԼ
		if (select == 1)
		{
			tea->showAllOrder();
		}

		//���ԤԼ
		else if (select == 2)
		{
			tea->VailOrder();
		}

		else {
			delete tea;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return ;
		}

	
	}


}
