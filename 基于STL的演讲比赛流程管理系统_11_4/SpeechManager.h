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

//�ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	//�ݽ������˵�
	void Show_Menu();



	//��������
	~SpeechManager();

	//������ʼ�����Եĺ���
	void initSpeech();

	//�˳�����
	void ExitSystem();

	//��ʼ��12��ѡ��
	void createSpeaker();

	//������ʼ�����ĺ���
	void StartSpeech();

	//������ǩ����
	void SpeechDrew();	

	//���������ĺ���
	void SpeechContest();

	//��ʾ�ɼ��ĺ���
	void ShowScore();

	//�����¼
	void SaveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileISEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//�鿴�����¼
	void showRecord();

	//����ļ�
	void clearRecord();

	//������Ա
	//��һ������,12��
	vector<int>v1;

	//�ڶ��ֽ������� 6��
	vector<int>v2;

	//ʤ��ǰ����������
	vector<int>vVictory;

	//����ѡ�ֱ�źͶ�Ӧѡ����Ϣ������
	map<int, Speaker>m_Speaker;

	//��������
	int m_Indix;

};