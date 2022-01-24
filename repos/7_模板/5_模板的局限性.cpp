#include <iostream>
using namespace std;

//模板局限性
//模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

//对比两个数是否相等
template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person& p1, Person& p2) {  //template<>：告诉编译器这个一个具体化的代码
	if (p1.name == p2.name && p1.age == p2.age) {
		return true;
	}
	else {
		return false;
	}
}

void test() {
	int a = 9;
	int b = 8;
	if (myCompare(a, b)) {
		cout << "a==b" << endl;
	}
	else {
		cout << "a!=b" << endl;
	}
}

void test1() {
	Person p1("和花", 1);
	Person p2("和叶", 1);
	if (myCompare(p1, p2)) {
		cout << "p1==p2" << endl;
	}
	else {
		cout << "p1!=p2" << endl;
	}
}

int main() {
	//test();
	test1();
	return 0;
}