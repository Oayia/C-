#include <iostream>
using namespace std;

/* 当类模板碰到继承时，需要注意的点：
	  ·当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
	  ·如果不指定，编译器无法给子类分配内存
	  ·如果想灵活指定出父类中T的类型，子类也需变为类模板
*/

template<class T>
class Animal {
	T m;
};


class Panda : public Animal<char> {  //指定类型，不指定类型编译器没办法去计算从父类继承来的需要占多大内存

};

void test() {
	Panda p;
}

//如果想灵活指定父类中T的类型，子类也需要变模板
template<class T1, class T2>
class Cat : public Animal<T2> {
public:
	Cat() {
		cout << typeid(T1).name() << "  " << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test1() {
	Cat<int, char> c;
}

int main() {
	test1();
	return 0;
}