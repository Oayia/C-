#include <iostream>
using namespace std;

//ģ�������
//ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

//�Ա��������Ƿ����
template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(Person& p1, Person& p2) {  //template<>�����߱��������һ�����廯�Ĵ���
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
	Person p1("�ͻ�", 1);
	Person p2("��Ҷ", 1);
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