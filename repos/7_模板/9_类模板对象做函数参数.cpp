#include <iostream>
using namespace std;

//类模板对象做函数参数
template<class T1, class T2>
class Panda {
public:
	Panda(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
	void showPanda() {
		cout << name << " " << age << endl;
	}
	T1 name;
	T2 age;
};

//1、指定传入的类型  ★最常用
void printPanda1(Panda<string, int>& p) {
	p.showPanda();
}
void test1() {
	Panda<string, int> p("绩笑", 3);
	printPanda1(p);
}

//2、参数模板化
template<class T1, class T2>
void printPanda2(Panda<T1, T2>& p) {
	p.showPanda();
	cout << typeid(T1).name() << "  " << typeid(T2).name() << endl;
}
void test2() {
	Panda<string, int> p("成风", 3);
	printPanda2(p);
}
//3、整个类模板化
template<class T>
void printPanda3(T& p) {
	p.showPanda();
	cout << typeid(T).name() << endl;
}
void test3() {
	Panda<string, int> p("成浪", 3);
	printPanda3(p);
}

int main() {
	test1();
	test2();
	test3();
	return 0;
}