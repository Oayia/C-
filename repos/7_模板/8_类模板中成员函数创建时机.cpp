#include <iostream>
using namespace std;

/*
	类模板中成员函数和普通类中成员函数创建时机是有区别的：
		普通类中的成员函数一开始就可以创建
		模板类中成员函数在调用时才创建  
*/

class Panda1 {
public:
	void showPanda1() {
		cout << "Panda1 show" << endl;
	}
};

class Panda2 {
public:
	void showPanda2() {
		cout << "Panda2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;

	//类模板中的成员函数
	void func1() {     //类模板中的成员函数并不是一开始就创建的，在调用时才去创建
		obj.showPanda1();
	}

	void func2() {
		obj.showPanda2();
	}
};

void test1() {
	MyClass<Panda1> m;
	m.func1();
	//m.func2(); //编译是可以通过的，但运行时发现Panda1是没有办法调func2函数的，因为它没有该函数
}

int main() {
	test1();
	return 0;
}