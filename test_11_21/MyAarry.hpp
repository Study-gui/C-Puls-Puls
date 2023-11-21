#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyAarry
{
public:
	//���캯��
	MyAarry(int capacity)
	{
		//cout << "���캯���ĵ���" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	//��������
	MyAarry(const MyAarry& arr)
	{
		//cout << " �������캯���ĵ���" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//���
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < arr.m_capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=�Ź���
	MyAarry& operator=(const MyAarry& arr)
	{
		//cout << "=�Ź��캯���ĵ���" << endl;
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
	//β������
	void Push_back(T& value)
	{
		if (this->m_capacity == this->m_size)
		{
			cout << "��������" << endl;
			return;
		}
		this->pAddress[this->m_size] = value;
		this->m_size++;
	}
	//βɾ
	void Pop_back()
	{
		this->m_size--;
	}
	//��ȡ������С
	int Getcapacity()
	{
		return this->m_capacity;
	}
	//��ȡ���ݸ���
	int Getsize()
	{
		return this->m_size;
	}
	//�����±귵������,����[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	
	//��������
	~MyAarry()
	{
		//cout << "���������ĵ���" << endl;
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
