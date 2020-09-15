// src.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <string>
#include <map>
#include "CStu.h"
#include "CStuMg.h"
#include "CMainView.h"

using namespace std;

int main() {

	string pathName = "d:/dstudent_manegement.txt";

	map<int, CStudent> stu_v1;

	CMainView cView;

	cView.welcome();
	cView.showMenu();

	string operateType;
	cin >> operateType;

	while (operateType != "0")
	{
		if (operateType == "1") {// 录入
			cView.addStuAtView(stu_v1);
		}
		else if (operateType == "2") { // 修改
			cView.updateByIdAtView(stu_v1);
		}
		else if (operateType == "3") { // 查找
			cView.findStuAtView(stu_v1);
		}
		else if (operateType == "4") {
			cView.deleteByIdAtView(stu_v1);
		}
		else if (operateType == "5") { // 显示所有
			cView.showAllStuAtView(stu_v1);
		}
		else if (operateType == "6") {  // 保存至文件
			cView.saveToFileAtView(stu_v1, pathName);
		}
		else if (operateType == "7") {// 从文件读取
			cView.readFromFileAtView(stu_v1, pathName);
		}
		else {

			cView.welcome();
			cView.showMenu();
		}

		cin >> operateType;
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
