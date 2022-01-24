#include <iostream>
using namespace std;

/* C++����һ����̳ж����
	�﷨��
	class ���� :�̳з�ʽ ����1, �̳з�ʽ ����2, ...
	
	����ʵ�ʿ����У��������ö�̳С���Ϊ��̳п��ܻ�������������ͬ����Ա���ֵ������Լ����μ̳�����
*/

class Base1 {
public:
	Base1() {
		a = 1;
		age = 2;
	}
	int a;
	int age;
};

class Base2 {
public:
	Base2() {
		b = 2;
		age = 3;
	}
	int b;
	int age;
};

class Son :public Base1, public Base2 {
public:
	Son() {
		c = 3;
		d = 4;
	}
	int c;
	int d;
};

void test01() {
	Son s;
	cout << sizeof(Son) << endl;
	cout << s.Base1::age << endl;
	cout << s.Base2::age << endl;
}

int main() {
	test01();
	return 0;
}