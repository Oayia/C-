#include <iostream>
//解决方式一：修改为 #include "panda.cpp"  
//包含panda.h头文件的时候相当于把头文件中那段代码让编译器看到了，但并不会在cpp文件中生成在.h文件中声明的那两函数，并且panda.cpp中的内容编译器从来没有见到过
#include "panda.hpp"    
using namespace std;

/*
	类模板分文件编写问题：
		类模板中成员函数创建时机是在调用时，导致份文件编写时链接不到
	解决问题的两种方式：
		1、直接包含.cpp文件   一般来说没有这样去做的，不可能让别人去看源码源文件
		2、将声明.h和实现.cpp写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不强制
*/

//template<class T1, class T2>
//class Panda {
//public:
//	Panda(T1 name, T2 age);
//	void showPanda();
//	T1 name;
//	T2 age;
//};

//template<class T1, class T2>
//Panda<T1, T2>::Panda(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
//template<class T1, class T2>
//void Panda<T1, T2>::showPanda() {
//	cout << name << " " << age << endl;
//}

void test() {
	Panda<string, int> p("福多多", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}