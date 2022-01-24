#include <iostream>
using namespace std;

/*
	在C++中，类内的成员变量和成员函数分开存储
*/

class Animal {
	int m_A;  //非静态成员变量             属于类的对象上
	static int m_B;  //静态成员变量        不属于类的对象上, 共享
	void fun() {} //非静态成员函数         不属于类的对象上，一份就可以了
	static void fun1() {} //静态成员函数    不属于类的对象上，一份就可以了
};

int Animal::m_B = 0;

void test01() {
	Animal a;
	//空对象占用内存空间:1字节
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << sizeof(a) << endl;
}

void test02() {
	//添加一个整型变量m_A后
	Animal a;
	cout << sizeof(a) << endl;  //★字节大小是4个字节，侧面印证了非静态成员变量是属于类的对象上的
}

void test03() {
	//在第2步操作的基础上，添加一个整型变量m_B
	Animal a;
	cout << sizeof(a) << endl;  //★字节大小还是4个字节，说明静态成员变量是不属于类的对象上的
}

void test04() {
	//在第3步操作的基础上，添加一个非静态成员函数fun
	Animal a;
	cout << sizeof(a) << endl;  //★字节大小还是4个字节，说明非静态成员函数是不属于类的对象上的
}

void test05() {
	//在第4步操作的基础上，添加一个静态成员函数fun1
	Animal a;
	cout << sizeof(a) << endl;  //★字节大小还是4个字节，说明静态成员函数是不属于类的对象上的
}

int main12() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}