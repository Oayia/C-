#include <iostream>
using namespace std;

//浅拷贝：简单的赋值拷贝操作，【浅拷贝带来的问题就是堆区的内存重复释放】，浅拷贝的问题需要深拷贝来解决
//深拷贝：在堆区重新申请空间，进行拷贝操作

class Animal {
public:
	Animal() {
		cout << "无参构造调用" << endl;
	}
	Animal(int a, int h) {
		age = a;
		height = new int(h);
		cout << "有参构造调用" << endl;
	}
	Animal(const Animal& a) {
		age = a.age;
		//height = a.height;  //编译器默认实现就是这行代码
		height = new int(*a.height);   //深拷贝
	}
	~Animal() {
		//析构代码，将堆区开辟的数据做释放操作
		if (height != NULL) {
			//★浅拷贝后对象a和a1的height属性对应的是同一块在堆中的内存，那根据栈先进后出的特点最先来到析构的对象是a1，
			//当对象a再来到此处执行delete时，堆上的这块内存已经释放，已不能再使用
			delete height; 
			height = NULL;
		}
		cout << "析构函数调用" << endl;
	}

	int age;
	int* height;
};

void test1() {
	Animal a(18, 160);
	cout << a.age << " " << *a.height << endl;
	Animal a1(a);
	cout << a1.age << " "<< *a1.height<< endl;
}

int main8() {
	test1();
	return 0;
}