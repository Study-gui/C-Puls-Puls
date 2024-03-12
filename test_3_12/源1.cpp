#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std; //���õ�һϵ��ͷ�ļ�

 struct Guard //���������ṹ��Guard
 {
     string name; //����
     int restDay; //��Ϣ��
 };

 void saveRestDays(vector<Guard> guards) //����һ�����Դ洢������Ϣ����Ϣ
 {
     ofstream file("RestDay.txt",ios::out); //���ļ�RestDay.txt
     if (file.is_open()) //�ж��ļ��Ƿ��
     {
         for (const Guard& guard : guards) //����ÿ����������
         {
             file << guard.name << " " << guard.restDay << endl; //������������������Ϣ����Ϣ�����ļ�
         }
         file.close(); //�ر��ļ�
     }
     else {
         cout << "�޷����ļ�" << endl; //���޷����ļ��������������Ϣ
     }
 }
 vector<Guard>& readRestDays() //������һ�������Զ�ȡ�ļ���Ϣ
 {
     vector<Guard> guards; //����һ���յ�guards���������洢��ȡ������
     ifstream file("RestDay.txt",ios::in); //���ļ�
     if (file.is_open()) //�ж��ļ��Ƿ��
     {
         string line;
         while (getline(file, line)) //��ȡ�ļ��е�ÿһ��
         {
             string name;
             int restDay;
             size_t pos = line.find(" ");  //���ҿո��ַ��״γ��ֵ�λ��
             if (pos != string::npos) //string::npos��һ������ֵ����ʾ���ַ�����û���ҵ��ض����ַ������ַ���������������������ʱ��ʾ���ַ������ҵ��˿ո��ַ�
             {
                 name = line.substr(0, pos); //���ſո��ַ�������£�ʹ��sybstr�������ַ���line����ȡ�������ַ������öδ����ʾ���ַ����Ŀ�ͷ��ʼ��ȡ������Ϊpos���ַ�
                 restDay = stoi(line.substr(pos + 1)); //�ӿո��ַ���pos+1��λ�ÿ�ʼ��ȡ��Ȼ��ʹ��stoi��������ȡ�����ַ���תΪ������stoi�������ڽ��ַ���ת��Ϊ�������ͣ�������restday�洢�ļ�Ϊת�������������ʾ��Ϣ�յ���ֵ
             }
             else {
                 cout << "��Ч���ļ���ʽ" << endl;
                 return guards;
             }
             Guard guard = { name, restDay }; //���´�����һ��Guard����guard����ʼ����name��restdayΪ���Ա����
             guards.push_back(guard); //���´�����guard��ӵ�Guard��ĩβ 
         }
         file.close(); //�ر��ļ�
     }
     else {
         cout << "�޷����ļ�" << endl; //��δ�ɹ������������Ϣ
     }
     return guards; //����guards����
 }

 void promptGuardsForRestDay(vector<Guard>& guards) //�������������ѱ���������Ϣ����Ϣ
 {
     for (Guard& guard : guards) //����guards�е�ÿһ��guard����
     {
         cout << guard.name << ", �����������Ϣ�� (1-7): ";
         cin >> guard.restDay;
     }
 }

 // �Űຯ��
 vector<vector<int>> scheduleRestDays(vector<Guard> guards) {
     vector<vector<int>> solutions;

     // ʹ�û��ݷ��������п��ܵ��Ű෽��
     void backtrack(vector<vector<int>>&solutions, vector<Guard> guards, vector<int> schedule);
     vector<int> schedule;
     backtrack(solutions, guards, schedule);

     return solutions;
 }

 // ���ݺ���
 void backtrack(vector<vector<int>>& solutions, vector<Guard> guards, vector<int> schedule) {
     if (schedule.size() == 7) {
         // ���Ű෽������Ϊ 7 ʱ��������ӵ���������б���
         solutions.push_back(schedule);
         return;
     }

     for (int i = 0; i < guards.size(); i++) {
         if (!schedule.empty() && schedule[i] == guards[i].restDay)
         {
             continue;
         }

         // ����ǰ��������Ϣ����ӵ��Ű෽���У����ݹ�������һλ�������Ű෽��
         schedule.push_back(guards[i].restDay);
         backtrack(solutions, guards, schedule);
         //schedule.pop_back();
     }
 }int main() {
     vector<Guard> guards = { { "Ǯ", 0 }, { "��", 0 }, { "��", 0 }, { "��", 0 }, { "��", 0 }, { "��", 0 }, { "��", 0 } };
     cout << "������Ϣ���Ű�ϵͳ" << endl;
     cout << "1. ��ʾ������Ϣ" << endl;
     cout << "2. ��ӱ�����Ϣ" << endl;
     cout << "3. ɾ��������Ϣ" << endl;
     cout << "4. �����ݼ���Ϣ" << endl;
     cout << "5. �鿴�Ű෽��" << endl;
     cout << "6. �˳�ϵͳ" << endl;
     cout << "��ѡ��";
     int choice;
     cin >> choice;
     while (choice != 6)
     {
         switch (choice)
         {
         case 1:
             for (const Guard& guard : guards)
             {
                 cout << guard.name << ": " << guard.restDay << endl;
             }
             break;
         case 2:
         {
             struct Guard newGuard;
             cout << "�������±���������: ";
             cin >> newGuard.name;
             cout << "�������±�������Ϣ�� (1-7): ";
             cin >> newGuard.restDay;
             guards.push_back(newGuard);
             break;
         }
         case 3:
             if (!guards.empty()) {
                 cout << "������Ҫɾ���ı���������: ";
                 string name;
                 cin >> name;
                 guards.erase(remove_if(guards.begin(), guards.end(), [&](const Guard& guard) { return guard.name == name; }));
             }
             break;
         case 4:
             promptGuardsForRestDay(guards);
             saveRestDays(guards);
             break;
         case 5:
         {
             vector<vector<int>> solutions = scheduleRestDays(guards);
             if (!solutions.empty()) {
                 cout << "�Ű෽������:" << endl;
                 for (const vector<int>& schedule : solutions) {
                     for (int day : schedule) {
                         cout << guards[day - 1].name << " ";
                     }
                     cout << endl;
                 }
             }
             else {
                 cout << "û������Ҫ����Ű෽��" << endl;
             }
             break;
         }
         default:
             cout << "��Ч��ѡ��������ѡ��" << endl;
         }
         cout << "��ѡ��";
         cin >> choice;
     }
     return 0;
 }