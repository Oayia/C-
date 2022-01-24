#include <iostream>
using namespace std;

/* 
* 普通函数和函数模板的区别：
*	 ①普通函数调用时可以发生自动类型转换（隐式类型转换）
*	 ②函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
*    ③如果利用显示指定类型的方式，可以发生隐式类型转换
* 
*/
//普通函数  可以发生自动类型转换（隐式类型转换）
int add1(int a, int b) {
	return a + b;
}

void test1() {
	int a = 9;
	int b = 3;
	char c = 'c';  //a - 97 c - 99
	cout << add1(a, b) << endl;
	cout << add1(a, c) << endl;
}

//函数模板
template<class T>
T add(T a, T b) {
	return a + b;
}

void test() {
	int a = 9;
	int b = 3;
	char c = 'c';
	//自动类型推导  不会发生隐式类型转换
	cout << add(a, b) << endl;
	//cout << add(a, c) << endl; //报错

	//显式指定类型  可以发生隐式类型转换
	cout << add<int>(a, c) << endl;
}

int main() {
	test1();
	test();
	return 0;
}