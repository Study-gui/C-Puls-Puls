 #define _CRT_SECURE_NO_WARNINGS
#include"SpeechManager.h"


//构造函数
SpeechManager::SpeechManager()
{
	//构造时初始化类
	this->initSpeech();

	//初始化选手信息
	this->createSpeaker();

	//读取记录
	this->loadRecord();

}

//演讲比赛菜单
void SpeechManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "***************** 欢迎参加演讲比赛 *****************" << endl;
	cout << "***************** 1.开始演讲比赛 *******************" << endl;
	cout << "***************** 2.查看往届记录 *******************" << endl;
	cout << "***************** 3.清空比赛记录 *******************" << endl;
	cout << "***************** 0.退出比赛程序 *******************" << endl;
	cout << "****************************************************" << endl;
}

//退出比赛
void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//创建初始化属性的函数
void SpeechManager::initSpeech()
{
	//初始化容器为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//初始化为第一轮
	this->m_Indix = 1;
	
	//初始化记录比赛的容器
	this->m_Record.clear();
}
//初始化12名选手
void SpeechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];
		Speaker sp;
		//初始化姓名
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			//初始化分数
			sp.M_Socre[j] = 0;
		}
		this->v1.push_back(i + 10001);
		//创建选手信息的容器
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

//创建开始的函数
void SpeechManager::StartSpeech()
{
	//第一轮比赛
	//1 抽签
	this->SpeechDrew();
	//2 比赛
	this->SpeechContest();
	//3 显示晋级结果
	this->ShowScore();
	//第二轮比赛
	this->m_Indix++;
	//1 抽签
	this->SpeechDrew();
	//2 比赛
	this->SpeechContest();
	//3 显示最终结果
	this->ShowScore();
	//保存分数
	this->SaveRecord();

	//需要重新初始化以便实时更新记录
	this->initSpeech();

	this->createSpeaker();

	this->loadRecord();

	cout << "本次比赛完毕" << endl;
	system("pause");
	system("cls");

}
//创建抽签函数
void SpeechManager::SpeechDrew()
{
	cout << "第《 " << this->m_Indix << " 》轮正在抽签" << endl;
	cout << "------------------------" << endl;
	cout << "抽签结果如下" << endl;
	
	if (this->m_Indix == 1)//判断为的几轮
	{
		random_shuffle(this->v1.begin(), this->v1.end());//洗牌函数
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
	system("pause");//进行任意键继续
} 

//创建比赛的函数
void SpeechManager::SpeechContest()
{
	cout << "------------第" << this->m_Indix << "轮的比赛开始----------------" << endl;

	multimap<double, int, greater<double>>groupScore;//临时容器存放排序的名次，通过自动排序
	int num = 0;//记录每组的人数
	//比赛人员的容器
	vector<int>v_Src;
	if (this->m_Indix == 1)//判断为第几轮
	{
		v_Src =v1;
	}
	else {
		v_Src = v2;
	}
	//遍历整个容器
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
		//取每轮的选手进行打分
	{
		num++;
		//存放打分的容器
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//分数在60到100之间的浮点数

			d.push_back(score);
		}
		//去掉最高分和最低分
		sort(d.begin(), d.end(), greater<double>());
		d.pop_back();
		d.pop_front();
		//获取总分
		double sum = accumulate(d.begin(), d.end(),0.0f);
		//获取平均分
		double avg = sum / (double)d.size();

		this->m_Speaker[*it].M_Socre[this->m_Indix - 1] = avg;//存入选手容器
		
		groupScore.insert(make_pair(avg, *it));//存入临时容器，利用自动排序，选出前三名选手
		//6个人一组
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_Name
					<< " 成绩：" << this->m_Speaker[it->second].M_Socre[this->m_Indix - 1] << endl;
			}
			//取前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Indix == 1)//第一轮
				{
					this->v2.push_back(it->second);
				}
				else {//第二轮
					this->vVictory.push_back(it->second);
				}
			}
			groupScore.clear();//清空临时容器，以防第一轮的第一组影响第二组
			cout << endl;
		}

	}
	cout << "---------------------第" << this->m_Indix << "轮比赛完毕--------" << endl;
	system("pause");
}

//显示成绩的函数
void SpeechManager::ShowScore()
{
	cout << "---------------第" << this->m_Indix << "轮的成绩如下------------" << endl;
	//记录显示成绩的容器
	vector<int>v;
	if (this->m_Indix == 1)//判断是第几轮
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	//显示分数
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 成绩：" <<
			this->m_Speaker[*it].M_Socre[this->m_Indix - 1] << endl;
	}
	cout << endl;
	system("pause");//任意键继续
	system("cls");
	this->Show_Menu();
}

//保存记录
void SpeechManager::SaveRecord()
{
	ofstream ofs;
	//打开文件
	ofs.open("speech.csv", ios::out | ios::app);
	
	//逐一写入
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].M_Socre[1] << ",";
	}
	ofs << endl;
	//关闭文件
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileISEmpty = false;//文件就不为空，
}
//读取记录
void SpeechManager::loadRecord()  
{
	ifstream ifs("speech.csv", ios::in);//输入流对象，读取文件

	if (!ifs.is_open())
	{
		this->fileISEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->fileISEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileISEmpty = false;
	ifs.putback(ch);//读取的单个字符放回去

	string data;
	int index = 0;

	while (ifs >> data)//逐一读取每一届记录
	{
		vector<string>v;
		//cout << data << endl;
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",", start);//进行截取编号和成绩
			if (pos == -1)
			{//没有找到的情况
				break;
			}
			string tmp = data.substr(start, pos - start);//获取字符串
			v.push_back(tmp);
			//cout << tmp << endl;
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));//放入往届记录容器中
		index++;
	}
	ifs.close();
}

//查看往届记录
void SpeechManager::showRecord()
{
	if (this->fileISEmpty)//进行判断文件是否为空
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" <<
				"冠军编号：" << this->m_Record[i][0] << " 得分:" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分:" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分:" << this->m_Record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//清空文件
void SpeechManager::clearRecord()
{
	cout << "确定是否要清空：" << endl;
	cout << "1,是" << endl;
	cout << "2,否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)//确定清空
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//需要初始化才算完全清空
		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "清空完成" << endl;
	}
	system("pause");
	system("cls");
}
//析构函数
SpeechManager:: ~SpeechManager()
{

}

