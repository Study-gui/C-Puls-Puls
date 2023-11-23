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

	//构造函数
	OrderFile();

	//更新预约记录的函数
	void updataorder();

	//预约条数
	int m_size;

	//存放预约条数与之对应预约信息的容器,int 表示条数，map<string ,string>表示的是预约信息和状态
	map<int, map<string, string>> m_orderdata;

};