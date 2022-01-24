#include <iostream>
using namespace std;

/* 多态
*  多态分为两类：
*	  静态多态：函数重载 和 运算符重载属于静态重载，复用函数名
*     动态重载：派生类和虚函数实现运行时多态
* 
*  静态多态和动态多态区别：
*		静态多态的函数地址早绑定 - 编译阶段确定函数地址
*		动态多态的函数地址晚绑定 - 运行阶段确定函数地址
* 
*  动态多态满足条件：
*		1、有继承关系
*		2、子类重写父类的虚函数
* 
*  动态多态的使用：父类的引用指向子类对象
*/

class Animal {
public:
	//虚函数
	virtual void speak() {    //★在父类的方法前加virtual关键字可实现晚绑定
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	//重写：函数返回值类型、函数名及参数列表完全相同
	void speak() {
		cout << "喵喵喵~" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "汪汪汪~" << endl;
	}
};

//地址早绑定 在编译阶段确定函数地址，因为此时的引用是Animal的引用
void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	Dog d;
	Cat c;
	doSpeak(d);   //加virtual前结果是：动物在说话
	doSpeak(c);   //加virtual前结果是：动物在说话
}

int main() {
	test01();
	return 0;
}