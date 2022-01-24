#include <iostream>
using namespace std;

/*
  一、继承语法：class 子类 : 继承方式 父类
  二、根据访问权限总结出不同的访问类型：
		访问	  public	protected	private
		同一个类	yes		  yes	      yes
		派生类		yes		  yes	      no
		外部的类	yes		  no	      no

  三、可利用开发人员命令提示工具查看对象模型
	  命令：cl /d1 reportSingleClassLayoutSon 1_继承.cpp
		1_继承.cpp

		class Son       size(16):
				+---
			0      | +--- (base class Base)
			0      | | a
			4      | | b
			8      | | c
				| +---
		12      | d
				+---
  
  四、继承中的构造和析构顺序执行顺序
	   先构造父类，再构造子类，析构顺序和构造相反
  五、继承同名成员处理方式
	   访问子类同名成员，直接访问
	   访问父类同名成员，需加作用域访问
  六、继承同名静态成员处理方式
	   静态成员和非静态成员出现同名，处理方式一致
 

*/

class Base {
public:
	Base() {
		a = 100;
		cout << "父类构造函数" << endl;
	}
	~Base() {
		cout << "父类析构函数" << endl;
	}
	void func() {
		cout << "父类中的func" << endl;
	}

public:
	int a;
	static int m_a;
protected:
	int b;
private:
	int c;
};

class Son :public Base {
public:
	Son() {
		a = 200;
		cout << "子类构造函数" << endl;
	}
	~Son() {
		cout << "子类析构函数" << endl;
	}
	/*void func() {
		cout << "子类中的func" << endl;
	}*/

public:
	int a;
	static int m_a;
	int d;
};

int Base::m_a = 18;
int Son::m_a = 8;

void test01() {
	//父类中所有非静态成员属性都会被子类继承
	//父类中私有成员属性确实被继承下去了，但是被编译器隐藏了，因此访问不到
	//cout << sizeof(Son) << endl; //16字节

	Son s;/*执行结果：
					父类构造函数
					子类构造函数
					子类析构函数
					父类析构函数
		  */
}

void test02() {
	Son s;
	cout << s.a << endl;  //200
	cout << s.Base::a << endl;  //★通过子类对象访问父类中同名普通属性
}

void test03() {
	Son s;
	s.func();   
	s.Base::func(); //★通过子类对象访问父类中同名普通成员函数
}

void test04() {
	//将子类中的func函数注释，也就是子类中没有func方法了，只有父类中有，那就可直接调用，不加作用域也可。因为编译器是先会在自身找，发现没有，然后在父类找。
	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	Son s;
	s.func();
}

void test05() {
	cout << Son::m_a << endl;
	cout << Son::Base::m_a << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
} 