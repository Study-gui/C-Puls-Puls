 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"SpeechManager.h"
//#include"Speaker.h"
#include<string>
#include<ctime>

////1.1比赛规则
//? 学校举行一场演讲比寒，共有12个同学。比赛共两轮，第一轮为淘汰寒，第二轮为决赛。
//? 每名选手都有对应的编号，如10001 - 100121
//?比賽方式：分组比赛，每组6个人；
//? 第一轮分为两个小組，整体按照选手编号进行抽签后顺序演讲。
//? 十个评委分别给每名选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩
//? 当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
//?第二轮为决寒，前三名胜出
//? 每轮比赛过后需要显示晋级选手的信息

int main()
{
	

	SpeechManager sm;
	int choice = 0;
	//测试
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first << " 姓名：" << it->second.m_Name << " 成绩：" << it->second.M_Socre[0] << endl;
	//}

	while (1)
	{
		//添加随机数种子
		srand((unsigned int)time(NULL));
		sm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.StartSpeech();
			break;
		case 2://查看往届记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
			break;
		case 0://退出比赛
			sm.ExitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}


	system("pause");
	return 0;
}