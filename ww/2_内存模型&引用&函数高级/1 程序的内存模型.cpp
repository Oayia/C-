#include <iostream>
using namespace std;

/*C++程序在执行时，将内容大方向划分为4个区域：
  一、编译操作后，程序运行前代码区和全局区就有了
	·代码区：
		1）存放CPU执行的机器指令
		2）由【操作系统进行管理】
		3）代码区是【共享】的，目的是对于频繁执行的程序，只要在内存中有一份代码即可
		4）代码区是【只读】的，防止程序意外的修改它的指令

	·全局区：
		1）存放【全局变量】、【静态变量】
		2）全局区还包含了常量区，【字符串常量】和【其他常量】(如const修饰的全局变量、字面量10等等)也存放在此
		3）该区域的数据在程序结束后由【操作系统释放】

  二、程序运行后
	·栈区：
		1）由【编译器自动分配释放】，存放形参、局部变量等
		2）【不要返回局部变量的地址】，栈区开辟的数据由编译器自动释放

	·堆区：
		1）在C++中主要利用【new】在堆区开辟内存
		2）由【程序员分配和释放】，若程序员不释放，程序结束时由操作系统回收；

  内存四区意义：
	不同区域存放的数据，赋予不同的生命周期，使得编程更灵活。


*/

//2.1、全局变量，函数体外定义
int g_a = 1;
int g_b = 1;

//2.3.2.2、const修饰的全局变量
const int c_g_a = 2;
const int c_g_b = 2;

int* func(int b);
int* func();
int* fun();

int main1() {
	//1、普通局部变量
	int l_a = 1;
	int l_b = 2;
	cout << "局部变量地址：" << (int)&l_a << " " << (int)&l_b << endl;
	cout << "全局变量地址：" << (int)&g_a << " " << (int)&g_b << endl;

	//2.2、静态变量，普通变量用static修饰
	static int s_l_a = 1;
	static int s_l_b = 1;
	cout << "静态变量地址：" << (int)&s_l_a << " " << (int)&s_l_b << endl;

	//2.3、常量
	//2.3.1、字符串常量
	cout << "字符串常量地址：" << (int)&"rtyui" << endl;

	//2.3.2、const修饰的变量
	//2.3.2.1、const修饰的局部变量
	const int c_l_a = 2;
	const int c_l_b = 2;
	cout << "const修饰的局部变量地址：" << (int)&c_l_a << " " << (int)&c_l_b << endl;
	cout << "const修饰的全局变量地址：" << (int)&c_g_a << " " << (int)&c_g_b << endl;

	//3、栈区
	int* p = func(3);
	cout << *p << endl;  //第一次可以正常输出是因为编译器做了一次保留
	cout << *p << endl;  //第二次数据就不再保留了

	//4、堆区
	int* p1 = func();
	cout << *p1 << endl;  //2
	cout << *p1 << endl;  //2
	delete p1;
	//cout << *p1 << endl; //释放后就不能再使用了

	int* p3 = fun();
	for (int i = 0; i < 3; i++) {
		p3[i] = i + 1;
	}
	for (int i = 0; i < 3; i++) {
		cout << p3[i] << endl;
	}

	delete[] p3; //释放数组是需要加中括号：[]
	return 0;
}

int* func(int b) { //形参也是在栈区
	int a = 1; //局部变量，存在栈区，栈区的数据在函数执行完后自动释放
	return &a; //返回局部变量的地址
}

int* func() {
	int* p = new int(2); //★指针p是局部变量，但是指针保存的数据是放在堆区
	return p;
}

int* fun() {
	int* p = new int[3];  //开辟数组在堆区，3个元素的整型数组，返回的是数组首地址
	return p;
}