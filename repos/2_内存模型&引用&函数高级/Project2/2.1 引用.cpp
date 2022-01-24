#include <iostream>
using namespace std;

/*
  引用：给变量起别名
  语法：数据类型 & 别名
  
  注意事项：
	1）引用必须初始化
	2）引用在初始化后，不可以改变
*/

int add(int& a, int& b);
int& test01();
int& test02();

int main2_1() {
	int a = 1;
	int& b = a; 
	cout << a << " " << b << endl;
	b = 100;	
	cout << a << " " << b << endl;

	//1、引用作函数参数
	int num1 = 2;
	int num2 = 3;
	cout << add(num1, num2) << endl;

	//2、引用作返回值
	//★2.1、不要返回局部变量的引用
	//int& ref = test01();
	//cout << ref << endl;
	//cout << ref << endl; //第二次结果错误，因为局部变量a的内存已经释放，第一次正确只是因为编译器做了短暂的保留

	//2.2、函数的调用可以作为左值
	int& ref2 = test02();
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 1000;
	cout << ref2 << endl;
	cout << ref2 << endl;
	return 0;
}

int add(int& a, int& b) {   //形参相当于是实参的别名
	a = 99; //地址传递和引用，形参会修饰实参
	return a + b;
}


int& test01() {
	int a = 456;
	return a;
}

int& test02() {
	static int a = 456; //静态变量，存在全局区，全局区数据在程序结束后由系统释放
	return a;
}
