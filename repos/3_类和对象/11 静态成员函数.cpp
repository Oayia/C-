#include <iostream>
using namespace std;

/*静态成员：在成员变量和成员函数前加上关键字static，称为静态成员
* 静态成员分为：
*	·静态成员变量
*		①所有对象共享同一份数据
*		②在编译阶段分配内存
*		③类内声明，类外初始化
*	·静态成员函数
*		①所有对象共享同一个函数
*		②静态成员函数只能访问静态成员变量
*/

class Animal {
public:
	//静态成员函数
	static void fun() {
		m_A++;
		//m_B++;  //静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的
		cout<< "static void fun()调用" << endl;
	}
	static int m_A; //静态成员变量
	int m_B; //非静态成员变量
	
	//静态成员函数也是有访问权限的
private:
	static void fun2() {
		cout << "static void fun2" << endl;
	}

};

int Animal::m_A = 0;

void test1() {
	//1、通过对象访问
	Animal a;
	a.fun();
	//2、通过类名调用
	Animal::fun();
	cout << a.m_A << endl;

	//Animal::fun2();  类外访问不到私有静态成员函数
}

int main11() {
	test1();
	return 0;
}