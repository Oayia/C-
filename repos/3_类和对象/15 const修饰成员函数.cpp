#include <iostream>
using namespace std;

/*
	常函数：
		Ⅰ成员函数后加const后我们称之为常函数
		Ⅱ常函数内不可以修改成员属性
		Ⅲ成员属性声明时加关键字mutable后，在常函数中依然可以修改
	常对象：
		Ⅰ声明对象前加const称对象为常对象
		Ⅱ常对象只能调用常函数
		
*/

class Animal {
public:
	//this指针的本质是指针常量，即指针的指向是不可以修改的，指针指向的值是可以修改的
	//在成员函数后加const，修饰的是this指向，让指针指向的值也不可修改
	void showAnimal() const{  //等效于const Animal* const this，即指针指向和指针指向的值都不可修改了
		//age = 2; //错误提示：表达式必须是可修改的左值
		name = "福多多";
		cout << name << endl;
	}
	void fun(){}
	int age;
	mutable string name;  //特殊变量，即使在常函数中和常对象下也可修改这个值，加关键字mutable
};

void test01() {
	Animal a;
	a.showAnimal();
}

//常对象
void test02() {
	const Animal a;  //在对象前加const，变常对象
	//a.age = 1;
	a.name = "和花"; //name被mutable修饰，在常对象下也可以修改
	a.showAnimal();
	//a.fun();  常对象只能调用常函数，不能调普通成员函数，因为普通成员函数时可以修改属性的
}

int main() {
	test01();
	return 0;
}