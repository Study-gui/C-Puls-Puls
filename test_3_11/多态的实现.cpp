 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Animal
{
public:
	virtual void speack()
	{ 
		cout << "������˵��" << endl;
	}
};


class Cat : public Animal
{
public:
	void speack()
	{
		cout << "Сè��˵��" << endl;
	}

};
class base
{
public:
	virtual void func() = 0;

};

class son : public base
{
public:
	void func()
	{
		cout << "func�����ĵ���" << endl;
	}
};
void AnimalSpeack(Animal& cat)
{
	cat.speack();
}

void test01()
{
	Cat cat;
	AnimalSpeack(cat);

}


void test02()
{
	base* b=new son;
	b->func();

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}