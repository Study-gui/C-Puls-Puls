// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<deque>
//#include<string>
//#include<algorithm>
//#include<ctime>
//
//using namespace std;
//class person//����ѡ����
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
//void createperson(vector<person>&v)//���ÿ��Բ��ô�ָ�룬���ܸı��ڲ�ֵ������ѡ����Ϣ
//{
//	string nameseed = "ABCDE";
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "ѡ��";
//		name += nameseed[i];
//		int score = 0;
//		person p(name, score);
//		v.push_back(p);//����ѡ����Ϣ
//	}
//}
//void setScore(vector<person>&v)//����ѡ�ַ���
//{
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		deque<int>d;//����������deque������ͨ��������ȥ�����ֵ����Сֵ��������
//		for (int i = 0; i < 10; i++)
//		{
//			int score = rand()%41+60;//�������60~100֮�����
//			d.push_back(score);
//		}
//		sort(d.begin(), d.end());//������
//		d.pop_back();//ȥ�����
//		d.pop_front();//ȥ��С��
//		int sum = 0;
//		for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
//		{
//			sum += *dit;
//		}
//		int avg = sum / d.size();
//		it->m_score = avg;//����ѡ�ֵķ���
//	}
//}
//void showScore(vector<person>& v)
//{
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "����: " << it->m_name <<"  ƽ���֣� " << it->m_score  << endl;
//	}
//}
//int main()
//{
//	//�������������
//
//	srand((unsigned)time(NULL));
//	//1������ѡ����Ϣ
//
//	vector<person>v;//����ѡ���������
//	createperson(v);
//
//	//2����ѡ�ִ��
//
//	setScore(v);
//	//3����ӡ���
//
//	showScore(v);
//
//	system("pause");
//	return 0;
//}
