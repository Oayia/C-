#include <iostream>
using namespace std;

/* 类模板和函数模板区别主要有两点：
	   1、类模板没有自动类型推导的使用方式
	   2、类模板在模板参数列表中可以有默认参数
*/

template<class NameType, class AgeType = int>  //★默认参数
class Panda {
public:
	Panda(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void showPanda() {
		cout << name << " " << age << endl;
	}
	NameType name;
	AgeType age;
};

//1、类模板没有自动类型推导的使用方式
void test1() {
	//Panda p("和花", 1);  //错误，无法用自动类型推导
	Panda<string, int> p("和花", 1); //正确，只能用显式指定类别
	p.showPanda();
}

//2、类模板在模板参数列表中可以有默认参数
void test2() {
	Panda<string> p("和叶", 1);
	p.showPanda();
}

int main() {
	test1();
	test2();
	return 0;
}