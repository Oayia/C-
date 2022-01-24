#include <iostream>
using namespace std;

/*
本质：
	引用在C++内部实现是一个【指针常量】，即指针的指向是不可以修改的，指针指向的值是可以修改的
	*/

//发现是引用，转换为：int * const ref = &a
void func(int& ref) { 
	ref = 100; //ref是引用，转换为：*ref = 100
}
int main2_2() {
	int a = 10;
	int& ref = a; //自动转换为：int* const ref = &a; 指针常量指针指向不可改，也说明为什么引用不可更改
	ref = 20;  //内部发现ref是引用，自动帮我们转换为：*ref = 20;
	cout << a << " " << ref << endl;
	func(a);
	cout << a << " " << ref << endl;

	return 0;
}