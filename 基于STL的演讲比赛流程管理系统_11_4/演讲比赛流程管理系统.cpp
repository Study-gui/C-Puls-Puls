 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"SpeechManager.h"
//#include"Speaker.h"
#include<string>
#include<ctime>

////1.1��������
//? ѧУ����һ���ݽ��Ⱥ�������12��ͬѧ�����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
//? ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ���10001 - 100121
//?��ِ��ʽ�����������ÿ��6���ˣ�
//? ��һ�ַ�Ϊ����С�M�����尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
//? ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣����ƽ����Ϊ����ѡ�ֵĳɼ�
//? ��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
//?�ڶ���Ϊ������ǰ����ʤ��
//? ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ

int main()
{
	

	SpeechManager sm;
	int choice = 0;
	//����
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first << " ������" << it->second.m_Name << " �ɼ���" << it->second.M_Socre[0] << endl;
	//}

	while (1)
	{
		//������������
		srand((unsigned int)time(NULL));
		sm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.StartSpeech();
			break;
		case 2://�鿴�����¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.clearRecord();
			break;
		case 0://�˳�����
			sm.ExitSystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}


	system("pause");
	return 0;
}