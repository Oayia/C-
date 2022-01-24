#include <iostream>
using namespace std;

/*
	1、构造函数和析构函数会【被编译器自动调用】，完成对象的初始化和清理工作。
	2、如果我们没有定义构造函数和析构函数，那么，编译器会提供，但它提供的构造函数和析构函数是空实现（函数体为空）。
*/

class Person {
	string name;
	int age;

public:
	Person(string n, int a) {
		name = n;
		age = a;
		cout << "构造函数调用" << endl;
	}

	~Person() {  //对象在销毁前会自动调用析构函数，而且只会调用一次
		cout << "析构函数调用" << endl;
	}
	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	void setAge(int a) {
		if (a < 0 || a>150) {
			age = 0;
		}
		else {
			age = a;
		}
	}

	int getAge() {
		return age;
	}
;
	
};
int main4() {
	Person p = Person("和花", 1);
	cout << p.getName() << " " << p.getAge() << endl;
	system("pause"); //代码执行到此处中断的意思
	return 0;
}