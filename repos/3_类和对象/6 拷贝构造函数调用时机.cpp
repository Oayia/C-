#include <iostream>
using namespace std;

/*C++中拷贝构造函数调用时机通常有三种情况：
*	1、使用一个已经创建完毕的对象来初始化一个新对象
*	2、值传递的方式给参数传值
*	3、以值方式返回局部对象
*/

class Person {
public:
	Person() {
		cout << "默认构造" << endl;
	}
	Person(int a) {
		age = a;
		cout << "有参构造" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造" << endl;
	}
	~Person() { 
		cout << "析构函数" << endl;
	}
	int age;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
	Person p1(20);
	Person p2(p1);
	cout << p2.age << endl;
}

//2、值传递的方式给函数参数传值(实参传给形参的时候调用拷贝构造)
//★值传递是拷贝出临时副本！！！
void doWork(Person p) {

}

void test02() {
	Person p;
	doWork(p);
}



//3、以值方式返回局部对象
Person doWork02() {
	Person p;
	cout << (int)&p << endl;
	return p;  //返回的是p的副本
}

void test03() {
	Person p = doWork02();
	cout << (int)&p << endl;
}
int main6() {
	//test01();
	//test02();
	test03();   //test03()结束后，p的副本也会被释放
	return 0;
}