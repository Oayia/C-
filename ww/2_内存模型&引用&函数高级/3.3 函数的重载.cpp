#include <iostream>
using namespace std;

/* 函数重载
   可以让函数名相同，提高复用性

   函数重载满足条件：
	·在同一作用域下
	·函数名相同
	·函数【参数类型】不同 或者 【个数】不同 或者 【顺序】不同
   附：函数的返回值不可以作为函数重载的条件

   ★函数重载的注意事项：
		1、引用作为重载的条件
		2、函数重载碰到默认参数
*/

void func() {
	cout << "func的调用" << endl;
}
// 1、引用作为重载的条件
void fun(int& a) {  //int& a = 10; 不合法
	cout << "fun(int& a)的调用" << endl;
}
void fun(const int& a) { //const int& a = 10; 合法
	cout << "fun(const int& a)的调用" << endl;
}

//2、函数重载碰到默认参数
void fun2(int a, int b = 8) {
	cout << "fun2(int a, int b = 8)的调用" << endl;
}
void fun2(int a) {
	cout << "fun2(int a)的调用" << endl;
}

int main3_3() {
	int a = 10;
	fun(a); //调用的是不含const的函数
	fun(10); //调用的是含有const的函数

	//fun2(2);  //此时编译器不知道该调用那个函数了，即出现二义性
	fun2(1, 2);
	return 0;

}