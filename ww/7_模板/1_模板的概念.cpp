#include <iostream>
using namespace std;

/* 模板特点：
	   1、模板不可以直接使用，它只是一个框架
	   2、模板的通用并不是万能的

   C++另一种编程思想称为泛型编程，主要利用的就是模板。C++提供两种模板机制：函数模板和类模板。
     1、函数模板
	   作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型代表
	   语法：
			template<typename T>    
			函数声明或定义
		    附：
				template：声明创建模板；
				typename：表明其后面的符号是一种数据类型，可以用class代替；  
				T：通用的数据类型
	   目的：为了提高复用性，将类型参数化
	   
*/

//函数模板
template<typename T>   //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

void test1() {
	int a = 10;
	int b = 2;
	cout << a << " " << b << endl;
	//利用函数模板进行交换
	//1、自动类型推导
	//mySwap(a,b);
	//2、显式指定类型  ★建议使用该方式
	mySwap<int>(a, b);
	cout << a << " " << b << endl;
}

int main() {
	test1();
	return 0;
}