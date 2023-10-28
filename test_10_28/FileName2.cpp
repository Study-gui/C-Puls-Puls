 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
bool compare(Person& p1, Person& p2)
{//函数就是按年龄升序排列，年龄一样按身高降序排列
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	else {
		return p2.m_age > p1.m_age;
	}
}
int main()
{
	list<Person>L;

	Person p1("刘备",35,175);
	Person p2("曹操",45,180);
	Person p3("孙权",40,170);
	Person p4("赵云",25,190);
	Person p5("张飞",35,160);
	Person p6("关羽",35,200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "排序前   " << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_name << " 年龄 " << it->m_age << " 身高 " << it->m_height << endl;
	}
	cout << "-------------------------------------" << endl<<"排序后"<<endl;

	L.sort(compare);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_name << " 年龄 " << it->m_age << " 身高 " << it->m_height << endl;
	}





	system("pause");
	return 0;
}
