#include <iostream>
using namespace std;

/* 模板配合友元函数的类内和类外实现：
*		全局函数类内实现 - 直接在类内声明友元即可
*		全局函数类外实现 - 需要提前让编译器知道全局函数的存在
*/

//通过全局函数打印Person信息

template<class T1, class T2>
class Person;
//类外实现
template<class T1, class T2>
void printPerson1(Person<T1, T2>& p) {  //函数模板的实现
	cout << p.name << " " << p.age << endl;
}

template<class T1, class T2>
class Person {
	//全局函数 类内实现
	friend void printPerson(Person<T1, T2>& p) {
		cout << p.name << " " << p.age << endl;
	}

	//全局函数 类外实现
	//加空模板参数列表<>
	friend void printPerson1<>(Person<T1, T2>& p);  //普通函数的声明，并非模板类中函数
public:
	Person(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};



//1、全局函数类内实现
void test1() {
	Person<string, int> p("成浪", 3);
	printPerson(p);
}

//1、全局函数类外实现
void test2() {
	Person<string, int> p("成风", 3);
	printPerson1(p);
}

int main() {
	test1();
	test2();
	return 0;
}