#include <iostream>
using namespace std;

/* C++允许一个类继承多个类
	语法：
	class 子类 :继承方式 父类1, 继承方式 父类2, ...
	
	但在实际开发中，不建议用多继承。因为多继承可能会引发父类中有同名成员出现的问题以及菱形继承问题
*/

class Base1 {
public:
	Base1() {
		a = 1;
		age = 2;
	}
	int a;
	int age;
};

class Base2 {
public:
	Base2() {
		b = 2;
		age = 3;
	}
	int b;
	int age;
};

class Son :public Base1, public Base2 {
public:
	Son() {
		c = 3;
		d = 4;
	}
	int c;
	int d;
};

void test01() {
	Son s;
	cout << sizeof(Son) << endl;
	cout << s.Base1::age << endl;
	cout << s.Base2::age << endl;
}

int main() {
	test01();
	return 0;
}