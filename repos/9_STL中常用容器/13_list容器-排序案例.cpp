#include <iostream>
#include <list>
using namespace std;

/*
	按照年龄进行升序，年龄相同按照身高降序
*/

class Panda {
public:
	Panda(string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}
	string name;
	int age;
	int height;
};

void printPanda(const list<Panda>& l) {
	for (list<Panda>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << it->name << " " << it->age << " " << it->height << endl;
	}
}

bool comparePanda(Panda& p1, Panda& p2) {
	if (p1.age == p2.age) {
		return p1.height > p2.height;
	}
	return p1.age > p2.age;
}

void test() {
	list<Panda> l;

	Panda p1("绩笑", 35, 175);
	Panda p2("成风", 45, 180);
	Panda p3("成浪", 40, 170);
	Panda p4("和花", 25, 190);
	Panda p5("和叶", 35, 160);
	Panda p6("福多多", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);
	
	printPanda(l);
	cout << "-------------------------" << endl;
	cout << "排序后：" << endl;
	l.sort(comparePanda);
	printPanda(l);
	
}

int main() {
	test();
	return 0;
}