#include <iostream>
using namespace std;

//空指针调用成员函数

class Animal {
public:
	void showClassName() {
		cout << "this is Animal class" << endl;
	}
	void showAnimalAge() {
		if (this == NULL) {  //该写法可增强代码的健壮性
			return;
		}
		cout << age << endl;  //此处age隐含写法就是：this->age

	}
	int age;
};

void test01() {
	Animal* a = NULL;
	a->showClassName(); //此函数调用正常
	a->showAnimalAge();  //此函数调用报错，报错是因为传入的指针为NULL，根本没有属性age

}

int main14() {
	test01();
	return 0;
}