#include <iostream>
using namespace std;

/*
	��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
		��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
		ģ�����г�Ա�����ڵ���ʱ�Ŵ���  
*/

class Panda1 {
public:
	void showPanda1() {
		cout << "Panda1 show" << endl;
	}
};

class Panda2 {
public:
	void showPanda2() {
		cout << "Panda2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;

	//��ģ���еĳ�Ա����
	void func1() {     //��ģ���еĳ�Ա����������һ��ʼ�ʹ����ģ��ڵ���ʱ��ȥ����
		obj.showPanda1();
	}

	void func2() {
		obj.showPanda2();
	}
};

void test1() {
	MyClass<Panda1> m;
	m.func1();
	//m.func2(); //�����ǿ���ͨ���ģ�������ʱ����Panda1��û�а취��func2�����ģ���Ϊ��û�иú���
}

int main() {
	test1();
	return 0;
}