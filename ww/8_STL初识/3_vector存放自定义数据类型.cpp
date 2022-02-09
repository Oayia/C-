#include <iostream>
#include <vector>
using namespace std;

//vector容器中存放自定义数据类型
class Panda {
public:
	Panda(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test01() {
	vector<Panda> v;
	Panda p1("成风", 2);
	Panda p2("成浪", 2);
	Panda p3("绩笑笑", 2);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for (vector<Panda>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->age << it->name << endl;
	}
}

//存放自定义数据类型 指针
void test02() {
	vector<Panda*> v;
	Panda p1("成风", 2);
	Panda p2("成浪", 2);
	Panda p3("绩笑笑", 2);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	for (vector<Panda*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->age << (*it)->name << endl;
	}
}

int main() {
	//test01();
	test02();
	return 0;
}