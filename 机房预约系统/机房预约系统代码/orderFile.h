#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"glabalFile.h"
#include<fstream>
#include<string>


class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼�ĺ���
	void updataorder();

	//ԤԼ����
	int m_size;

	//���ԤԼ������֮��ӦԤԼ��Ϣ������,int ��ʾ������map<string ,string>��ʾ����ԤԼ��Ϣ��״̬
	map<int, map<string, string>> m_orderdata;

};