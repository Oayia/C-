#pragma once  //防止头文件重复包含
#include <iostream>
using namespace std;

template<class T1, class T2>
class Panda {
public:
	Panda(T1 name, T2 age);
	void showPanda();
	T1 name;
	T2 age;
};

template<class T1, class T2>
Panda<T1, T2>::Panda(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Panda<T1, T2>::showPanda() {
	cout << name << " " << age << endl;
}
