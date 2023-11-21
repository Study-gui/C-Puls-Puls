 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include"MyAarry.hpp"

//利用类模板进行实现内置类型数组和自定义类型的的功能
//测试int数组
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
	cout << "返回数组容量: " << p3.Getcapacity() << endl;
	cout << "返回数组个数：" << p3.Getsize() << endl;
	cout << "要访问的元素: " << p3[5] << endl;

}
//测试自定义类型
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
		cout << "姓名：" << arr.pAddress[i].m_name << " 年龄：" << arr.pAddress[i].m_age << endl;
	}
}
void test02()
{
	MyAarry<person> p(5);
	string seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		//name += seed[i];
		person p1(name+seed[i], i);
		p.Push_back(p1);
	}
	printperson(p);
	cout << "返回数组容量: " << p.Getcapacity() << endl;
	cout << "返回数组个数：" << p.Getsize() << endl;
	cout << "要访问的元素信息: " << p[2].m_name << endl;
	p.Pop_back();
	cout << "删除后的------------------" << endl;
	printperson(p);
	cout << "返回数组容量: " << p.Getcapacity() << endl;
	cout << "返回数组个数：" << p.Getsize() << endl;
	cout << "要访问的元素信息: " << p[2].m_name << endl;
}
int main()
{

	//test01();
	
	test02();
	system("pause");
	return 0;
}
