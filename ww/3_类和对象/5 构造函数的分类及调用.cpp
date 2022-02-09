#include <iostream>
using namespace std;

/*构造函数两种分类方式：
	按参数划分：有参构造、无参构造（也叫默认构造）
	按类型划分：普通构造、拷贝构造
  三种调用方式：
	括号法
	显示法
	隐式转换法
*/
class Person {
public:
	Person() {
		cout << "无参构造" << endl;
	}
	Person(int a) {
		age = a;
		cout << "有参构造" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}
	~Person() {
		cout << "析构函数" << endl;
	}
	int age;
};

void test01() {
	//1、括号法
	Person p11;  //默认构造
	Person p22(10); //有参构造
	Person p33(p22); //拷贝构造函数

	cout << p22.age << " " << p33.age << endl;

	//★注意事项1：
	//      调用默认构造函数时，不要加括号:()	
	//      因为写法：Person p1();编译器会认为是一个函数的声明，不会认为在创建对象
	
	//2、显示法
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);

	//Person(10); //匿名对象 特点：当前行执行结束后，系统会立即回收掉匿名函数
	//cout << "fghjk" << endl;

	//★注意事项2：
	//		不要利用拷贝构造函数，初始化匿名对象，即写法：Person(p3);
	//		编译器会认为Person(p3);等价于Person p3; 所以会报重定义的错误
	// 
	
	//3、隐式转换法
	Person p4 = 10; //相当于写了：Person p4 = Person(10);  有参构造
	Person p5 = p4; //拷贝构造
}

int main5() {
	test01();
	system("pause");
	return 0;
}