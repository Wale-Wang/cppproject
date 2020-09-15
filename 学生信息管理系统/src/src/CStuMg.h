#pragma once
#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include "CStu.h"
#include <map>
#include <string>

class CStudentMg
{
public:
	CStudentMg();
	~CStudentMg();

	//增加学生
	CStudent addStudent(std::map<int, CStudent> & ms, CStudent & stu);
	
	//删除学生
	bool deleteStudent(std::map<int, CStudent> & ms, const int & id);

	//修改学生信息
	CStudent updateStudent(std::map<int, CStudent> & ms, const CStudent stu);

	//查找学生（by id）
	CStudent locatedStudentbyid(const std::map<int, CStudent> & ms, const int & id) const;

	//显示所有学生
	void showAll(const std::map<int, CStudent> & ms) const;

	//将信息写入txt
	bool savetoFile(const std::map<int, CStudent> & ms, const std::string & path) const;

	//从txt读信息
	bool readfromFile(std::map<int, CStudent> & ms, std::string path);

private:

};

//CStudentMg::CStudentMg()
//{
//}
//
//CStudentMg::~CStudentMg()
//{
//}

#endif // !C_STUDENT_MG_H
