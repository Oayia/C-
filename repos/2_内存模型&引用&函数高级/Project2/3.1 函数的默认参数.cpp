#include <iostream>
using namespace std;

int func(int a, int b=20, int c=30) {  //1、默认参数必须放在形参列表的最后
	return a + b + c;
}

//2、声明和实现只能有一个有默认参数，否则编译器不知道选函数声明时的默认参数，还是实现时的默认参数，即程序出现二义性
int func1(int num1, int num2 = 3);
int func1(int num1, int num2) {
	return num1 + num2;
}

int main3_1() {
	cout << func(1) << endl;
	cout << func1(4) << endl;
	return 0;
}

