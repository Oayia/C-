#include <iostream>
using namespace std;

/*
	我们知道，在C++中，成员变量和成员函数是分开存储的，每一个非静态成员函数只会诞生一份函数实例，即多个同类型的对象会公用一块代码
	那么，问题是：这一块代码是如何区分是哪个对象调用自己的呢？
	C++提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象。

	this指针是隐含在每一个非静态成员内的一种指针，不需要定义，直接使用即可

	this指针使用场景：
		·当形参和成员变量同名时，可用this指针来区分
		·在类的非静态成员函数中返回对象本身，可使用return *this
*/

class Animal {
public:
	Animal(int age) {
		this->age = age;
	}
	Animal& AnimalAddAge(Animal& a) {   //此处返回值如果是Animal，不是引用：Animal&，那么每次*this返回的都是一个新的副本，并不是a1本身，所以在最后输出a1的age时还是20，而不是40
		this->age += a.age;
		cout << this->age << endl;
		return *this;    //★this指向a1的指针，而*this指向的是a1这个对象的本体
	}
	int age;
};

//1、解决名称冲突
void test01() {
	Animal a(18);
	cout << a.age << endl;
}
//2、返回对象本身用*this
void test02() {
	Animal a1(10);
	Animal a2(10);
	//链式编程思想
	a1.AnimalAddAge(a2).AnimalAddAge(a2).AnimalAddAge(a2);
	cout << a1.age << endl;
}

int main13() {
	//test01();
	test02();
	return 0;
}