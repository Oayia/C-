#include<iostream>
using namespace std;

/*
	默认情况下，C++编译器至少给类添加3个函数：
		1、默认构造函数（无参，函数体为空）
		2、默认析构函数（无参，函数体为空）
		3、默认拷贝构造函数，对属性进行值拷贝，也就是浅拷贝
	构造函数调用规则：
		·如果用户定义有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
		·如果用户定义拷贝构造函数，C++不会再提供其他构造函数

*/

class Animal {
public:
	Animal() {
		cout << "无参构造函数" << endl;
	}
	Animal(string c) {
		color = c;
		cout << "有参构造函数" << endl;
	}
	Animal(const Animal& a) {
		color = a.color;
		cout << "拷贝构造函数" << endl;
	}
	~Animal() {
		cout << "析构函数" << endl;
	}
	string color;
};

void test1() {
	Animal a("black");
	Animal a1(a);
	cout << a1.color << endl; 
}
int main() {
	test1();
	return 0;
}