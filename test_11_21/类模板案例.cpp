 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include"MyAarry.hpp"

//������ģ�����ʵ����������������Զ������͵ĵĹ���
//����int����
void test01()
{
	MyAarry<int>p1(10);

	MyAarry<int>p2(p1);

	MyAarry<int>p3(20);
	p3 = p1;
	for (int i = 0; i < 10; i++)
	{
		p3.Push_back(i);
	}
	p3.Pop_back();
	cout << "������������: " << p3.Getcapacity() << endl;
	cout << "�������������" << p3.Getsize() << endl;
	cout << "Ҫ���ʵ�Ԫ��: " << p3[5] << endl;

}
//�����Զ�������
class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void printperson(MyAarry<person>& arr)
{
	for (int i = 0; i < arr.Getsize(); i++)
	{
		cout << "������" << arr.pAddress[i].m_name << " ���䣺" << arr.pAddress[i].m_age << endl;
	}
}
void test02()
{
	MyAarry<person> p(5);
	string seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		//name += seed[i];
		person p1(name+seed[i], i);
		p.Push_back(p1);
	}
	printperson(p);
	cout << "������������: " << p.Getcapacity() << endl;
	cout << "�������������" << p.Getsize() << endl;
	cout << "Ҫ���ʵ�Ԫ����Ϣ: " << p[2].m_name << endl;
	p.Pop_back();
	cout << "ɾ�����------------------" << endl;
	printperson(p);
	cout << "������������: " << p.Getcapacity() << endl;
	cout << "�������������" << p.Getsize() << endl;
	cout << "Ҫ���ʵ�Ԫ����Ϣ: " << p[2].m_name << endl;
}
int main()
{

	//test01();
	
	test02();
	system("pause");
	return 0;
}
