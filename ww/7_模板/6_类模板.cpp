#include <iostream>
using namespace std;

/* 类模板作用：
*		建立一个通用类，类中的【成员数据类型可以不具体指定】，用一个虚拟的类型来代表
*  语法：
*		template<typename T>
	    附：template ---  声明创建模板
		    typename ---  表明其后面的符号是一种数据类型，可以用class代替
			T        ---  通用的数据类型，名称可以替换，通常为大写字母
*/

template<class NameType, class AgeType>
class Panda {
public:
	Panda(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void showPanda() {
		cout << name << " " << age << endl;
	}
	NameType name;
	AgeType age;
};

void test() {
	Panda<string, int> p("福多多小朋友", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}