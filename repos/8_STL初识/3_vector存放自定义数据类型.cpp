#include <iostream>
#include <vector>
using namespace std;

//vector�����д���Զ�����������
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
	Panda p1("�ɷ�", 2);
	Panda p2("����", 2);
	Panda p3("��ЦЦ", 2);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for (vector<Panda>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->age << it->name << endl;
	}
}

//����Զ����������� ָ��
void test02() {
	vector<Panda*> v;
	Panda p1("�ɷ�", 2);
	Panda p2("����", 2);
	Panda p3("��ЦЦ", 2);
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