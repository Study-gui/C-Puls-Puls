#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyAarry
{
public:
	//构造函数
	MyAarry(int capacity)
	{
		//cout << "构造函数的调用" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	//拷贝构造
	MyAarry(const MyAarry& arr)
	{
		//cout << " 拷贝构造函数的调用" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//深拷贝
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < arr.m_capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=号构造
	MyAarry& operator=(const MyAarry& arr)
	{
		//cout << "=号构造函数的调用" << endl;
		if (this->pAddress != NULL)
		{
			this->m_capacity = 0;
			this->m_size = 0;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < arr.m_capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插数据
	void Push_back(T& value)
	{
		if (this->m_capacity == this->m_size)
		{
			cout << "容量已满" << endl;
			return;
		}
		this->pAddress[this->m_size] = value;
		this->m_size++;
	}
	//尾删
	void Pop_back()
	{
		this->m_size--;
	}
	//获取容量大小
	int Getcapacity()
	{
		return this->m_capacity;
	}
	//获取数据个数
	int Getsize()
	{
		return this->m_size;
	}
	//利用下标返回数据,重载[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	
	//析构函数
	~MyAarry()
	{
		//cout << "析构函数的调用" << endl;
		if (this->pAddress != NULL)
		{
			this->m_capacity = 0;
			this->m_size = 0;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
	T* pAddress;
	int m_capacity;
	int m_size;
};
