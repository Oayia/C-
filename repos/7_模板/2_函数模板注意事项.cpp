#include <iostream>
using namespace std;

//函数模板注意事项
template<class T>   //typename可替换为class
void mySwap(T& a,T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
//①自动类型推导，必须推导出一致的数据类型T才可以使用
void test1() {
	int a = 2;
	int b = 3;
	char c = 'o';
	mySwap(a, b); //正确
	//mySwap(a, c);  //错误，推导不出一致的T类型
	cout << a << " " << b << endl;

}

//②模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
	cout << "func调用" << endl;
}
void test2() {
	//func(); //错误，解决方式就是随便给一个类型，如：func<int>();
	func<int>();
}

int main() {
	//test1();
	test2();
	return 0;
}