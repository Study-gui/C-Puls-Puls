#include"orderFile.h"


//���캯��
OrderFile::OrderFile()
{
	//Ҫ��ԤԼ�ļ��ĺ���
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	//�ж��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	string date;      //����
	string interval;  //ʱ���
	string stuid;     //ѧ�����
	string stuname;   //ѧ������
	string roomid;    //�������
	string status;    //ԤԼ״̬

	//cout << "���" << endl;
	//string arr;
	//cout << arr << endl;

	//ԤԼ����
	this->m_size = 1;

	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid 
		&& ifs >> status)
	{
		//���Դ���
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuid << endl;
		cout << stuname << endl;
		cout << roomid << endl;
		cout << status << endl;*/

		string key;//ÿ��ԤԼ�ģ�ÿ��ԤԼ��Ϣ�ļ�ֵ
		string value;//ÿ��ԤԼ�ģ�ÿ��ԤԼ��Ϣ��ֵ
		map<string, string> m;//���ÿ��ԤԼ����ʱ����

		//��ȡ ���ڵ� ��Ϣ
		int pos = date.find(":");
		if (pos != -1)
		{//date:1
			//��������
			key = date.substr(0, pos);
			//����ʱ��
			value = date.substr(pos+1, date.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}
		//��ȡʱ��ε���Ϣ
		 pos =interval.find(":");
		if (pos != -1)
		{//date:1
			//ʱ�������
			key = interval.substr(0, pos);
			//ʱ���ʱ��
			value = interval.substr(pos+1, interval.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}
		//��ȡѧ��ѧ����Ϣ
		pos = stuid.find(":");
		if (pos != -1)
		{//date:1
			//ѧ����������
			key = stuid.substr(0, pos);
			//ѧ��
			value = stuid.substr(pos+1, stuid.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}
		//��ȡѧϰ������Ϣ
		pos = stuname.find(":");
		if (pos != -1)
		{//date:1
			//��������
			key = stuname.substr(0, pos);
			//����
			value = stuname.substr(pos+1, stuname.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}
		//��ȡ�������
		pos = roomid.find(":");
		if (pos != -1)
		{//date:1
			//�����������
			key = roomid.substr(0, pos);
			//�������
			value = roomid.substr(pos+1, roomid.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}

		//��ȡ���״̬
		pos = status.find(":");
		if (pos != -1)
		{//date:1
			//�������
			key = status.substr(0, pos);
			//���״̬
			value = status.substr(pos+1, status.size() - pos - 1);
			//������ʱmap��
			m.insert(make_pair(key, value));
		}
		//����ԤԼ������
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;

		//���Դ���,�ܷ�������ȡ
		/*for (map<int, map<string, string>>::iterator it = this->m_orderdata.begin(); it != this->m_orderdata.end(); it++)
		{
			cout << "ԤԼ��" << it->first << "��" << endl;
			for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			{
				cout << " key= " << mit->first << " value= " << mit->second << endl;
			}
			cout << endl;
		}*/

	}
}

//����ԤԼ��¼�ĺ���
void OrderFile::updataorder()
{
	//���ļ�������д�������ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);//�Դ����µ��ļ�����ʽ����д��

	for (int i = 1; i <= this->m_orderdata.size(); i++)
	{
		ofs << "date:" << m_orderdata[i]["date"] << " ";
		ofs << "interval:" << m_orderdata[i]["interval"] << " ";
		ofs << "stuId:" << m_orderdata[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderdata[i]["stuName"] << " ";
		ofs << "roomId:" << m_orderdata[i]["roomId"] << " ";
		ofs << "status:" << m_orderdata[i]["status"] << endl;
	}

	ofs.close();
	/*cout << "������ɣ�" << endl;
	system("pause");
	system("cls");*/
}