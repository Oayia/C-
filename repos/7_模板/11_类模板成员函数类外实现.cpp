#include <iostream>
using namespace std;

//��ģ���Ա��������ʵ��
template<class T1, class T2>
class Panda {
public:
	Panda(T1 name, T2 age);
	void showPanda();

	T1 name;
	T2 age;
};

//���캯������ʵ��
template<class T1, class T2>
Panda<T1, T2>::Panda(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//��Ա��������ʵ��
template<class T1, class T2>
void Panda<T1, T2>::showPanda() {  //��Panda<T1, T2> ���߱�����������ģ�壬һ��Ҫ�Ӽ�����
	cout << name << " " << age << endl;
}

void test() {
	Panda<string, int> p("�����", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}