#include <iostream>
using namespace std;

/*
	在开发中，提倡开闭原则
	开闭原则：对扩展进行开放，对修改进行关闭

	★多态带来的好处：
	   1、组织结构清晰
	   2、可读性强
	   3、利于后期扩展和维护
*/

//计算器抽象类
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int num1;
	int num2;
};

//加法计算器类
class AddCalculator :public AbstractCalculator {
	int getResult() {
		return num1 + num2;
	}
};

//减法计算器类
class SubCalculator :public AbstractCalculator {
	int getResult() {
		return num1 - num2;
	}
};

//乘法计算器类
class MulCalculator :public AbstractCalculator {
	int getResult() {
		return num1 * num2;
	}
};

void test() {
	//多态使用条件：父类指针或引用指向子类对象

	//加法
	AbstractCalculator* a = new AddCalculator;
	a->num1 = 4;
	a->num2 = 3;
	cout << a->getResult() << endl;
	//用完后记得销毁
	delete a;
}

int main() {
	
	test();
	return 0;
}