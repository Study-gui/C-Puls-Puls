 #define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"


//���캯��
SpeechManager::SpeechManager()
{
	//����ʱ��ʼ����
	this->initSpeech();

	//��ʼ��ѡ����Ϣ
	this->createSpeaker();

	//��ȡ��¼
	this->loadRecord();

}

//�ݽ������˵�
void SpeechManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "***************** ��ӭ�μ��ݽ����� *****************" << endl;
	cout << "***************** 1.��ʼ�ݽ����� *******************" << endl;
	cout << "***************** 2.�鿴�����¼ *******************" << endl;
	cout << "***************** 3.��ձ�����¼ *******************" << endl;
	cout << "***************** 0.�˳��������� *******************" << endl;
	cout << "****************************************************" << endl;
}

//�˳�����
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//������ʼ�����Եĺ���
void SpeechManager::initSpeech()
{
	//��ʼ������Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//��ʼ��Ϊ��һ��
	this->m_Indix = 1;
	
	//��ʼ����¼����������
	this->m_Record.clear();
}
//��ʼ��12��ѡ��
void SpeechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		Speaker sp;
		//��ʼ������
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			//��ʼ������
			sp.M_Socre[j] = 0;
		}
		this->v1.push_back(i + 10001);
		//����ѡ����Ϣ������
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

//������ʼ�ĺ���
void SpeechManager::StartSpeech()
{
	//��һ�ֱ���
	//1 ��ǩ
	this->SpeechDrew();
	//2 ����
	this->SpeechContest();
	//3 ��ʾ�������
	this->ShowScore();
	//�ڶ��ֱ���
	this->m_Indix++;
	//1 ��ǩ
	this->SpeechDrew();
	//2 ����
	this->SpeechContest();
	//3 ��ʾ���ս��
	this->ShowScore();
	//�������
	this->SaveRecord();

	//��Ҫ���³�ʼ���Ա�ʵʱ���¼�¼
	this->initSpeech();

	this->createSpeaker();

	this->loadRecord();

	cout << "���α������" << endl;
	system("pause");
	system("cls");

}
//������ǩ����
void SpeechManager::SpeechDrew()
{
	cout << "�ڡ� " << this->m_Indix << " �������ڳ�ǩ" << endl;
	cout << "------------------------" << endl;
	cout << "��ǩ�������" << endl;
	
	if (this->m_Indix == 1)//�ж�Ϊ�ļ���
	{
		random_shuffle(this->v1.begin(), this->v1.end());//ϴ�ƺ���
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");//�������������
} 

//���������ĺ���
void SpeechManager::SpeechContest()
{
	cout << "------------��" << this->m_Indix << "�ֵı�����ʼ----------------" << endl;

	multimap<double, int, greater<double>>groupScore;//��ʱ���������������Σ�ͨ���Զ�����
	int num = 0;//��¼ÿ�������
	//������Ա������
	vector<int>v_Src;
	if (this->m_Indix == 1)//�ж�Ϊ�ڼ���
	{
		v_Src =v1;
	}
	else {
		v_Src = v2;
	}
	//������������
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
		//ȡÿ�ֵ�ѡ�ֽ��д��
	{
		num++;
		//��Ŵ�ֵ�����
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//������60��100֮��ĸ�����

			d.push_back(score);
		}
		//ȥ����߷ֺ���ͷ�
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();
		//��ȡ�ܷ�
		double sum = accumulate(d.begin(), d.end(),0.0f);
		//��ȡƽ����
		double avg = sum / (double)d.size();

		this->m_Speaker[*it].M_Socre[this->m_Indix - 1] = avg;//����ѡ������
		
		groupScore.insert(make_pair(avg, *it));//������ʱ�����������Զ�����ѡ��ǰ����ѡ��
		//6����һ��
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_Name
					<< " �ɼ���" << this->m_Speaker[it->second].M_Socre[this->m_Indix - 1] << endl;
			}
			//ȡǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Indix == 1)//��һ��
				{
					this->v2.push_back(it->second);
				}
				else {//�ڶ���
					this->vVictory.push_back(it->second);
				}
			}
			groupScore.clear();//�����ʱ�������Է���һ�ֵĵ�һ��Ӱ��ڶ���
			cout << endl;
		}

	}
	cout << "---------------------��" << this->m_Indix << "�ֱ������--------" << endl;
	system("pause");
}

//��ʾ�ɼ��ĺ���
void SpeechManager::ShowScore()
{
	cout << "---------------��" << this->m_Indix << "�ֵĳɼ�����------------" << endl;
	//��¼��ʾ�ɼ�������
	vector<int>v;
	if (this->m_Indix == 1)//�ж��ǵڼ���
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	//��ʾ����
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " �ɼ���" <<
			this->m_Speaker[*it].M_Socre[this->m_Indix - 1] << endl;
	}
	cout << endl;
	system("pause");//���������
	system("cls");
	this->Show_Menu();
}

//�����¼
void SpeechManager::SaveRecord()
{
	ofstream ofs;
	//���ļ�
	ofs.open("speech.csv", ios::out | ios::app);
	
	//��һд��
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].M_Socre[1] << ",";
	}
	ofs << endl;
	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	this->fileISEmpty = false;//�ļ��Ͳ�Ϊ�գ�
}
//��ȡ��¼
void SpeechManager::loadRecord()  
{
	ifstream ifs("speech.csv", ios::in);//���������󣬶�ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileISEmpty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->fileISEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileISEmpty = false;
	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;

	while (ifs >> data)//��һ��ȡÿһ���¼
	{
		vector<string>v;
		//cout << data << endl;
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",", start);//���н�ȡ��źͳɼ�
			if (pos == -1)
			{//û���ҵ������
				break;
			}
			string tmp = data.substr(start, pos - start);//��ȡ�ַ���
			v.push_back(tmp);
			//cout << tmp << endl;
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));//���������¼������
		index++;
	}
	ifs.close();
}

//�鿴�����¼
void SpeechManager::showRecord()
{
	if (this->fileISEmpty)//�����ж��ļ��Ƿ�Ϊ��
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷�:" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷�:" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷�:" << this->m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//����ļ�
void SpeechManager::clearRecord()
{
	cout << "ȷ���Ƿ�Ҫ��գ�" << endl;
	cout << "1,��" << endl;
	cout << "2,��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)//ȷ�����
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��Ҫ��ʼ��������ȫ���
		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "������" << endl;
	}
	system("pause");
	system("cls");
}
//��������
SpeechManager:: ~SpeechManager()
{

}

