 #define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"Speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

//演讲管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//演讲比赛菜单
	void Show_Menu();



	//析构函数
	~SpeechManager();

	//创建初始化属性的函数
	void initSpeech();

	//退出比赛
	void ExitSystem();

	//初始化12名选手
	void createSpeaker();

	//创建开始比赛的函数
	void StartSpeech();

	//创建抽签函数
	void SpeechDrew();	

	//创建比赛的函数
	void SpeechContest();

	//显示成绩的函数
	void ShowScore();

	//保存记录
	void SaveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileISEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//查看往届记录
	void showRecord();

	//清空文件
	void clearRecord();

	//创建成员
	//第一轮容器,12人
	vector<int>v1;

	//第二轮晋级容器 6人
	vector<int>v2;

	//胜利前三名的容器
	vector<int>vVictory;

	//创建选手编号和对应选手信息的容器
	map<int, Speaker>m_Speaker;

	//创建轮数
	int m_Indix;

};