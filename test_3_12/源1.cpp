#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std; //引用的一系列头文件

 struct Guard //创建保安结构体Guard
 {
     string name; //姓名
     int restDay; //休息日
 };

 void saveRestDays(vector<Guard> guards) //创建一函数以存储保安休息日信息
 {
     ofstream file("RestDay.txt",ios::out); //打开文件RestDay.txt
     if (file.is_open()) //判断文件是否打开
     {
         for (const Guard& guard : guards) //遍历每个保安对象
         {
             file << guard.name << " " << guard.restDay << endl; //将保安的姓名，，休息日信息存入文件
         }
         file.close(); //关闭文件
     }
     else {
         cout << "无法打开文件" << endl; //若无法打开文件，则输出错误信息
     }
 }
 vector<Guard>& readRestDays() //创建出一个函数以读取文件信息
 {
     vector<Guard> guards; //创建一个空的guards向量用来存储读取的数据
     ifstream file("RestDay.txt",ios::in); //打开文件
     if (file.is_open()) //判断文件是否打开
     {
         string line;
         while (getline(file, line)) //读取文件中的每一行
         {
             string name;
             int restDay;
             size_t pos = line.find(" ");  //查找空格字符首次出现的位置
             if (pos != string::npos) //string::npos是一个特殊值，表示在字符串中没有找到特定的字符或子字符串，则当括号内条件成立时表示在字符串中找到了空格字符
             {
                 name = line.substr(0, pos); //找着空格字符的情况下，使用sybstr函数从字符串line中提取出部分字符串，该段代码表示从字符串的开头开始提取，长度为pos个字符
                 restDay = stoi(line.substr(pos + 1)); //从空格字符后pos+1的位置开始提取，然后使用stoi函数将提取出的字符串转为整数，stoi函数用于将字符串转换为整数类型，这样，restday存储的即为转换后的整数，表示休息日的数值
             }
             else {
                 cout << "无效的文件格式" << endl;
                 return guards;
             }
             Guard guard = { name, restDay }; //重新创建了一个Guard对象guard并初始化，name和restday为其成员变量
             guards.push_back(guard); //将新创建的guard添加到Guard的末尾 
         }
         file.close(); //关闭文件
     }
     else {
         cout << "无法打开文件" << endl; //若未成功则输出错误信息
     }
     return guards; //返还guards向量
 }

 void promptGuardsForRestDay(vector<Guard>& guards) //创建函数以提醒保安输入休息日信息
 {
     for (Guard& guard : guards) //遍历guards中的每一个guard对象
     {
         cout << guard.name << ", 请输入你的休息日 (1-7): ";
         cin >> guard.restDay;
     }
 }

 // 排班函数
 vector<vector<int>> scheduleRestDays(vector<Guard> guards) {
     vector<vector<int>> solutions;

     // 使用回溯法生成所有可能的排班方案
     void backtrack(vector<vector<int>>&solutions, vector<Guard> guards, vector<int> schedule);
     vector<int> schedule;
     backtrack(solutions, guards, schedule);

     return solutions;
 }

 // 回溯函数
 void backtrack(vector<vector<int>>& solutions, vector<Guard> guards, vector<int> schedule) {
     if (schedule.size() == 7) {
         // 当排班方案长度为 7 时，将其添加到解决方案列表中
         solutions.push_back(schedule);
         return;
     }

     for (int i = 0; i < guards.size(); i++) {
         if (!schedule.empty() && schedule[i] == guards[i].restDay)
         {
             continue;
         }

         // 将当前保安的休息日添加到排班方案中，并递归生成下一位保安的排班方案
         schedule.push_back(guards[i].restDay);
         backtrack(solutions, guards, schedule);
         //schedule.pop_back();
     }
 }int main() {
     vector<Guard> guards = { { "钱", 0 }, { "赵", 0 }, { "孙", 0 }, { "李", 0 }, { "周", 0 }, { "吴", 0 }, { "陈", 0 } };
     cout << "保安休息日排班系统" << endl;
     cout << "1. 显示保安信息" << endl;
     cout << "2. 添加保安信息" << endl;
     cout << "3. 删除保安信息" << endl;
     cout << "4. 设置休假信息" << endl;
     cout << "5. 查看排班方案" << endl;
     cout << "6. 退出系统" << endl;
     cout << "请选择：";
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
             cout << "请输入新保安的姓名: ";
             cin >> newGuard.name;
             cout << "请输入新保安的休息日 (1-7): ";
             cin >> newGuard.restDay;
             guards.push_back(newGuard);
             break;
         }
         case 3:
             if (!guards.empty()) {
                 cout << "请输入要删除的保安的姓名: ";
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
                 cout << "排班方案如下:" << endl;
                 for (const vector<int>& schedule : solutions) {
                     for (int day : schedule) {
                         cout << guards[day - 1].name << " ";
                     }
                     cout << endl;
                 }
             }
             else {
                 cout << "没有满足要求的排班方案" << endl;
             }
             break;
         }
         default:
             cout << "无效的选择，请重新选择" << endl;
         }
         cout << "请选择：";
         cin >> choice;
     }
     return 0;
 }