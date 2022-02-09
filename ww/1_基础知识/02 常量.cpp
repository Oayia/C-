#include <iostream>
using namespace std;
#define Day 7  //不需要加分号哦

/*
	C++定义常量的两种方式：
		1、#define 常量名 常量值
		2、const修饰的变量
*/

int main2() {

	cout << "一周有" << Day << "天" << endl;

	const string name = "东皇太一";
	cout << name << endl;
	system("pause");
	return 0;
}