#include <iostream>
using namespace std;
/*
	常量引用：主要用来修饰形参，防止误操作
*/

void showValue(const int& val) {   //★常量引用使用场景
	//val = 1000;
	cout << val << endl;
}

int main2_3() {
	//int a = 10;
	//int& ref = 10; //引用必须引一块合法的内存空间（如：栈或堆区的数据），而字面量10是在常量区。把10换成a，那就是可以的
	//const int& ref = 10; //加入const就可以了。只是因为编译器对代码进行了优化：int tmp = 10;  const int& ref = tmp; 但这样这个引用引的是一块临时的空间，但这个空间，我们想要操作它找不到它的原名，原名是编译器帮忙起的
	//ref = 20; //加const后变为只读，不可以修改了

	int a = 9;
	showValue(a);
	cout << a << endl;
	return 0;
}