#include <iostream>
using namespace std;

/*C++�п������캯������ʱ��ͨ�������������
*	1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
*	2��ֵ���ݵķ�ʽ��������ֵ
*	3����ֵ��ʽ���ؾֲ�����
*/

class Person {
public:
	Person() {
		cout << "Ĭ�Ϲ���" << endl;
	}
	Person(int a) {
		age = a;
		cout << "�вι���" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "��������" << endl;
	}
	~Person() { 
		cout << "��������" << endl;
	}
	int age;
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {
	Person p1(20);
	Person p2(p1);
	cout << p2.age << endl;
}

//2��ֵ���ݵķ�ʽ������������ֵ(ʵ�δ����βε�ʱ����ÿ�������)
//��ֵ�����ǿ�������ʱ����������
void doWork(Person p) {

}

void test02() {
	Person p;
	doWork(p);
}



//3����ֵ��ʽ���ؾֲ�����
Person doWork02() {
	Person p;
	cout << (int)&p << endl;
	return p;  //���ص���p�ĸ���
}

void test03() {
	Person p = doWork02();
	cout << (int)&p << endl;
}
int main6() {
	//test01();
	//test02();
	test03();   //test03()������p�ĸ���Ҳ�ᱻ�ͷ�
	return 0;
}