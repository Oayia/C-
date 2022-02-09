#include <iostream>
using namespace std;

/* ·在多态中，通常父类中虚函数的是现实毫无意义的，主要都是调用子类重写的内容，因此可以将虚函数改为纯虚函数
*  ·纯虚函数：
		virtual 返回值类型 函数名(参数列表) = 0;
*  ·当类中有了纯虚函数，这个类也称为抽象类
*  ·抽象类特点：
*		无法实例化对象
*		子类必须重写抽象类中的虚函数，否则也属于抽象类
*/


class Animal { //抽象类
public:
	virtual void eat() = 0;  //纯虚函数
};

class Panda :public Animal {
public:
	void eat() {       //子类必须重写父类中的纯虚函数，否则无法实例化对象
		cout << "竹子" << endl;
	}
};

void test01() {
	Animal* a = new Panda;
	a->eat();
}

int main() {
	test01();
	return 0;
}