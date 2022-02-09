#include <iostream>
using namespace std;

/*
	普通函数和函数模板是可以发生函数重载的，调用规则如下：
		1、如果函数模板和普通函数都可以实现，优先调用普通函数
		2、可以通过空模板参数列表来强制调用函数模板
		3、函数模板也可以发生重载
		4、如果函数模板可以产生更好的匹配，优先调用函数模板

*/

void myPrint(int a, int b) {
	cout << "普通函数myPrint" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "模板函数myPrint" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "三个参数模板函数myPrint" << endl;
}

void test1() {
	int a = 9;
	int b = 8;
	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
	myPrint(a, b); 
	//2、可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b);
	//3、函数模板也可以发生重载
	myPrint(a, b, 1);
	//4、如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);  //myPrint(int a, int b) 和 void myPrint(T a, T b)，编译器选的是函数模板，因为编译器觉得选择int的话还得转换
}

int main() {
	test1();
	return 0;
}