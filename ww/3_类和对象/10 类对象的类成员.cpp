#include <iostream>
using namespace std;

/*C++类中的成员可以是另一个类的对象，我们称该成员为对象成员
* 那么，当创建类的对象时，类对象与对象成员的构造和析构的顺序谁先谁后？
* 结论：
*	当其他对象作为本类成员，构造时是先构造成员对象，再构造自身，析构顺序和构造相反
*/

class Student {
public:

	Student(string n):name(n) {
		cout << "Student初始化" << endl;
	}
	~Student() {
		cout << "Student析构函数" << endl;
	}
	string name;
};
class School {
public:
	School(string n, string s):name(n), stu(s) {   //★Student stu = s; 隐式转换法进行对象的创建
		cout << "School初始化" << endl;
	}
	~School() {
		cout << "School析构函数" << endl;
	}
	string name;
	Student stu;
};

int main10() {
	/* 38 39行运行结果：
			Student初始化
			School初始化
			福多多
			School析构函数
			Student析构函数*/
	School sh("太阳产房", "福多多");
	cout << sh.stu.name << endl;

	return 0;
}