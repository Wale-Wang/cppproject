#include "CStu.h"
#include <iostream>
#include <string>

using namespace std;

CStudent::CStudent() { this->id = -1; }
CStudent::~CStudent() {}

int CStudent::getId() const { return id; }
void CStudent::setId(int val) { id = val; }

string CStudent::getName() const { return name; }
void CStudent::setName(string val) { name = val; }

int CStudent::getAge() const { return age; }
void CStudent::setAge(int val) { age = val; }

//对<<和>>的重载

std::ostream & operator<<(std::ostream & os, CStudent & stu) {
	os << stu.getId() << "    " << stu.getName() << "    " << stu.getAge();
	return os;
}

std::istream & operator>>(std::istream & is, CStudent & stu) {
	is >> stu.id >> stu.name >> stu.age;
	return is;
}