// #define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<string>
//using namespace std;
//
//
//
//int main()
//{
//	fstream ofs;
//	ofs.open("text.txt", ios::out);
//	if (!ofs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		ofs << i << endl;
//	}
//	ofs.close();
//
//	ifstream ifs;//���ļ�
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//	}
//	char arr[10] = { 0 };
//	//while (ifs.getline(arr,sizeof(arr)))
//	//{
//	//	cout << arr << endl;
//	//}
//	//string brr;
//	//while (getline(ifs, brr))
//	//{
//	//	cout << brr;
//	//}
//	//cout << brr;
//	char c;
//	while ((c=ifs.get()) != EOF)
//	{
//		cout << c;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	ifs.close();
//
//	system("pause");
//	return 0;
//}