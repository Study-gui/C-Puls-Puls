// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<deque>
//#include<string>
//#include<algorithm>
//#include<ctime>
//
//using namespace std;
//class person//创建选手类
//{
//public:
//	person(string name, int score)
//	{
//		this->m_name = name;
//		this->m_score = score;
//	}
//	string m_name;
//	int m_score;
//
//};
//void createperson(vector<person>&v)//引用可以不用传指针，就能改变内部值，创建选手信息
//{
//	string nameseed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "选手";
//		name += nameseed[i];
//		int score = 0;
//		person p(name, score);
//		v.push_back(p);//创建选手信息
//	}
//}
//void setScore(vector<person>&v)//创建选手分数
//{
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		deque<int>d;//创建分数的deque容器。通过该容器去掉最大值和最小值，并排序
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand()%41+60;//随机产生60~100之间的数
//			d.push_back(score);
//		}
//		sort(d.begin(), d.end());//排升序
//		d.pop_back();//去最大数
//		d.pop_front();//去最小数
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
//		{
//			sum += *dit;
//		}
//		int avg = sum / d.size();
//		it->m_score = avg;//插入选手的分数
//	}
//}
//void showScore(vector<person>& v)
//{
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名: " << it->m_name <<"  平均分： " << it->m_score  << endl;
//	}
//}
//int main()
//{
//	//生成随机数种子
//
//	srand((unsigned)time(NULL));
//	//1，创建选手信息
//
//	vector<person>v;//创建选手类的容器
//	createperson(v);
//
//	//2，给选手打分
//
//	setScore(v);
//	//3，打印输出
//
//	showScore(v);
//
//	system("pause");
//	return 0;
//}
