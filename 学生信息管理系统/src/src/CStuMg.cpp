#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include "CStu.h"
#include "CStuMg.h"

using namespace std;

CStudentMg::CStudentMg() {
}
CStudentMg::~CStudentMg() {
}

//增加学生
CStudent CStudentMg::addStudent(map<int, CStudent> & ms, CStudent & stu) {
	ms.insert(make_pair(stu.getId(), stu));
	return stu;
}


//删除学生
bool CStudentMg::deleteStudent(map<int, CStudent> & ms, const int & id) {
	bool b = false;

	map<int, CStudent> ::iterator iter;
	iter = ms.find(id);
	if (iter != ms.end())
	{
		ms.erase(iter);
		b = true; // 删除成功
	}

	return b;

}

//修改学生
CStudent CStudentMg::updateStudent(map<int, CStudent> & ms, const CStudent cStu) {
	CStudent stu;
	int id = cStu.getId();

	map<int, CStudent> ::iterator iter;
	iter = ms.find(id);
	if (iter != ms.end())
	{
		// 修改
		iter->second = cStu;
		stu = cStu; // 把修改后的对象，赋值，再返回上层
	}

	return stu;
}

//查找学生（by id）
CStudent CStudentMg::locatedStudentbyid(const map<int, CStudent> & ms, const int & id) const {
	CStudent stu;

	map<int, CStudent> ::const_iterator iter;
	iter = ms.find(id);
	if (iter != ms.end())
	{
		stu = iter->second;
	}

	return stu;
}

//显示所有学生
void CStudentMg::showAll(const map<int, CStudent> & ms) const {
	for (auto p : ms)
	{
		cout << p.second << endl;
	}
}

//将信息写入txt
bool CStudentMg::savetoFile(const map<int, CStudent> & ms, const string & pathName) const {
	bool b = true;

	//fstream ofs(pathName,ios::out+ios::binary); // 为什么不是以binary保存？
	fstream ofs(pathName, ios::out);
	if (ofs) {
		stringstream ss;

		cout << "文件打开" << endl;

		CStudent stu;
		for (auto p = ms.begin(); p != ms.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // 注意，输出一定是 ss.str();

		ofs.close();
	}
	else
	{
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;
}

//从txt读信息
bool CStudentMg::readfromFile(map<int, CStudent> & ms, string path) {
	bool b = true;

	ms.clear(); // 清掉原来的

	fstream ifs(path, ios::in);
	if (ifs) {
		cout << "文件打开" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // 怎么一行行地读取？
		{
			CStudent cStu;
			ss << s;
			// cout<<ss.str();
			ss >> cStu;
			ss.clear();

			ms.insert(make_pair(cStu.getId(), cStu));

		}

		ifs.close();

	}
	else {
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;
}

