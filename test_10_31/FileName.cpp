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

//传入员工信息
void createworker(vector<worker>& v)
{
	string newname = "ABCDEFGHIJ";
	for (int i=0;i<10;i++)
	{
		worker w;
		w.m_name = "员工：";//传入员工姓名
		w.m_name += newname[i];
		w.m_salary = rand() % 10000 + 10000;//工资10000~19999

		v.push_back(w);//插入员工信息
	}
}
//将员工进行分组
void SetGroup(vector<worker>&v,multimap<int, worker>& m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int elem = rand() % 3;//0，1，2
		m.insert(make_pair(elem, *it));//插入multimap容器中
	}
}
//
void ShowWorkerBygroup(multimap<int,worker>&m)
{
	multimap<int, worker>::iterator pos = m.find(CEHUA);//找到策划部门的迭代器位置
	int count = m.count(CEHUA);//统计个数
	int indix = 0;
	cout << "策划部门：" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " 工资：" << (*pos).second.m_salary << endl;
	}

	cout << "---------------------------" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
	indix = 0;
	cout << "美术部门：" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " 工资：" << (*pos).second.m_salary << endl;
	}

	cout << "---------------------------" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	indix = 0;
	cout << "研发部门：" << endl;
	for (; pos != m.end() && indix < count; pos++, indix++)
	{
		cout << pos->second.m_name << " 工资：" << (*pos).second.m_salary << endl;
	}

}
int main()
{
	srand((unsigned int)time(NULL));
	//创建员工
	vector<worker>vworker;
	createworker(vworker);
	/*for (vector<worker>::iterator it = vworker.begin(); it != vworker.end(); it++)
	{
		cout << it->m_name << " 工资：" << it->m_salary << endl;
	}*/
	//员工分组
	multimap<int, worker>mworker;//创建容器
	SetGroup(vworker,mworker);
	//显示员工
	ShowWorkerBygroup(mworker);

	system("pause");
	return 0;
}