#include"orderFile.h"


//构造函数
OrderFile::OrderFile()
{
	//要读预约文件的函数
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	//判断是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	string date;      //日期
	string interval;  //时间段
	string stuid;     //学生编号
	string stuname;   //学生姓名
	string roomid;    //机房编号
	string status;    //预约状态

	//cout << "你好" << endl;
	//string arr;
	//cout << arr << endl;

	//预约条数
	this->m_size = 1;

	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid 
		&& ifs >> status)
	{
		//测试代码
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuid << endl;
		cout << stuname << endl;
		cout << roomid << endl;
		cout << status << endl;*/

		string key;//每条预约的，每个预约信息的键值
		string value;//每条预约的，每个预约信息的值
		map<string, string> m;//存放每条预约的临时容器

		//截取 日期的 信息
		int pos = date.find(":");
		if (pos != -1)
		{//date:1
			//日期名称
			key = date.substr(0, pos);
			//日期时间
			value = date.substr(pos+1, date.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}
		//截取时间段的信息
		 pos =interval.find(":");
		if (pos != -1)
		{//date:1
			//时间段名称
			key = interval.substr(0, pos);
			//时间段时间
			value = interval.substr(pos+1, interval.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}
		//截取学生学号信息
		pos = stuid.find(":");
		if (pos != -1)
		{//date:1
			//学号名称名称
			key = stuid.substr(0, pos);
			//学号
			value = stuid.substr(pos+1, stuid.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}
		//截取学习姓名信息
		pos = stuname.find(":");
		if (pos != -1)
		{//date:1
			//姓名名称
			key = stuname.substr(0, pos);
			//姓名
			value = stuname.substr(pos+1, stuname.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}
		//截取机房编号
		pos = roomid.find(":");
		if (pos != -1)
		{//date:1
			//机房编号名称
			key = roomid.substr(0, pos);
			//机房编号
			value = roomid.substr(pos+1, roomid.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}

		//截取审核状态
		pos = status.find(":");
		if (pos != -1)
		{//date:1
			//审核名称
			key = status.substr(0, pos);
			//审核状态
			value = status.substr(pos+1, status.size() - pos - 1);
			//存入临时map中
			m.insert(make_pair(key, value));
		}
		//放入预约总容器
		this->m_orderdata.insert(make_pair(this->m_size, m));
		this->m_size++;

		//测试代码,能否正常截取
		/*for (map<int, map<string, string>>::iterator it = this->m_orderdata.begin(); it != this->m_orderdata.end(); it++)
		{
			cout << "预约第" << it->first << "条" << endl;
			for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
			{
				cout << " key= " << mit->first << " value= " << mit->second << endl;
			}
			cout << endl;
		}*/

	}
}

//更新预约记录的函数
void OrderFile::updataorder()
{
	//打开文件，进行写入所有文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);//以创建新的文件的形式进行写入

	for (int i = 1; i <= this->m_orderdata.size(); i++)
	{
		ofs << "date:" << m_orderdata[i]["date"] << " ";
		ofs << "interval:" << m_orderdata[i]["interval"] << " ";
		ofs << "stuId:" << m_orderdata[i]["stuId"] << " ";
		ofs << "stuName:" << m_orderdata[i]["stuName"] << " ";
		ofs << "roomId:" << m_orderdata[i]["roomId"] << " ";
		ofs << "status:" << m_orderdata[i]["status"] << endl;
	}

	ofs.close();
	/*cout << "更新完成！" << endl;
	system("pause");
	system("cls");*/
}