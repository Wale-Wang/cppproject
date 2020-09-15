#pragma once
#ifndef c_student_h
#define c_student_h
#include<string>
#include<iostream>

class CStudent
{
	/*
	对iostream中的'<<'运算符和'>>'运算符进行重载
	将其设为友元函数，在类的外部定义，但是可以访问类的成员，即可以在外部进行对学生数据的读入和写出
	*/
	friend std::ostream & operator<<(std::ostream & os, CStudent & stu);
	friend std::istream & operator>>(std::istream & is, CStudent & stu);
public:
	CStudent();
	~CStudent();

	int getId() const; //const的作用是该函数无权对成员变量进行修改
	void setId(int val);

	std::string getName() const;
	void setName(std::string val);

	int getAge() const;
	void setAge(int val);



private:
	int id;
	std::string name;
	int age;

};

//cstudent::cstudent()
//{
//}
//
//cstudent::~cstudent()
//{
//}
#endif // !c_student_h
