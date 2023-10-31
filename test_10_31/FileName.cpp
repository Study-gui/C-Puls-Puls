 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<ctime>
#define CEHUA 0
#define MEISHU 1
#define YANFA  2
using namespace std;

class worker
{
public:
	/*worker(string name, int salary)
	{
		m_name = name;
		m_salary = salary;
	}*/
	string m_name;
	int m_salary;
};

//����Ա����Ϣ
void createworker(vector<worker>& v)
{
	string newname = "ABCDEFGHIJ";
	for (int i=0;i<10;i++)
	{
		worker w;
		w.m_name = "Ա����";//����Ա������
		w.m_name += newname[i];
		w.m_salary = rand() % 10000 + 10000;//����10000~19999

		v.push_back(w);//����Ա����Ϣ
	}
}
//��Ա�����з���
void SetGroup(vector<worker>&v,multimap<int, worker>& m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int elem = rand() % 3;//0��1��2
		m.insert(make_pair(elem, *it));//����multimap������
	}
}
//
void ShowWorkerBygroup(multimap<int,worker>&m)
{
	multimap<int, worker>::iterator pos = m.find(CEHUA);//�ҵ��߻����ŵĵ�����λ��
	int count = m.count(CEHUA);//ͳ�Ƹ���
	int indix = 0;
	cout << "�߻����ţ�" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " ���ʣ�" << (*pos).second.m_salary << endl;
	}

	cout << "---------------------------" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
	indix = 0;
	cout << "�������ţ�" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " ���ʣ�" << (*pos).second.m_salary << endl;
	}

	cout << "---------------------------" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	indix = 0;
	cout << "�з����ţ�" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " ���ʣ�" << (*pos).second.m_salary << endl;
	}

}
int main()
{
	srand((unsigned int)time(NULL));
	//����Ա��
	vector<worker>vworker;
	createworker(vworker);
	/*for (vector<worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	{
		cout << it->m_name << " ���ʣ�" << it->m_salary << endl;
	}*/
	//Ա������
	multimap<int, worker>mworker;//��������
	SetGroup(vworker,mworker);
	//��ʾԱ��
	ShowWorkerBygroup(mworker);

	system("pause");
	return 0;
}