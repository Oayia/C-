#include <iostream>
using namespace std;

/*
	1、函数对象
		概念：
			重载【函数调用操作符】的类，其对象常称为【函数对象】
			函数对象使用重载的()时，行为类似函数调用，也叫【仿函数】
		本质:
			函数对象(仿函数)是一个【类】，不是一个函数

	2、函数对象使用
		①函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
		②函数对象超出普通函数的概念，函数对象可以有自己的状态
		③函数对象可以作为参数传递

	3、
*/

class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	void operator()(string s) {
		count++;
		cout << s << endl;
	}
	int count;
};

//①函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01() {
	MyAdd myadd;
	cout << myadd(2, 6) << endl;
}


//②函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02() {
	MyPrint myprint;
	myprint("福多多小朋友");
	myprint("和花小可爱");
	myprint("圆润调皮机灵鬼");

	cout << "myprint调用次数：" << myprint.count << endl;
}

void DoPrint(MyPrint& mp, string s) {
	mp(s);
}

//③函数对象可以作为参数传递
void test03() {
	MyPrint myprint;
	DoPrint(myprint, "花花：和叶臭弟弟");
}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}