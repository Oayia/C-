#include <iostream>
using namespace std;

//类模板成员函数类外实现
template<class T1, class T2>
class Panda {
public:
	Panda(T1 name, T2 age);
	void showPanda();

	T1 name;
	T2 age;
};

//构造函数类外实现
template<class T1, class T2>
Panda<T1, T2>::Panda(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//成员函数类外实现
template<class T1, class T2>
void Panda<T1, T2>::showPanda() {  //★Panda<T1, T2> 告诉编译器我这是模板，一定要加尖括号
	cout << name << " " << age << endl;
}

void test() {
	Panda<string, int> p("福多多", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}