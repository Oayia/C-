#include<iostream>
using namespace std;

/*
	Ĭ������£�C++���������ٸ������3��������
		1��Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
		2��Ĭ�������������޲Σ�������Ϊ�գ�
		3��Ĭ�Ͽ������캯���������Խ���ֵ������Ҳ����ǳ����
	���캯�����ù���
		������û������вι��캯����C++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
		������û����忽�����캯����C++�������ṩ�������캯��

*/

class Animal {
public:
	Animal() {
		cout << "�޲ι��캯��" << endl;
	}
	Animal(string c) {
		color = c;
		cout << "�вι��캯��" << endl;
	}
	Animal(const Animal& a) {
		color = a.color;
		cout << "�������캯��" << endl;
	}
	~Animal() {
		cout << "��������" << endl;
	}
	string color;
};

void test1() {
	Animal a("black");
	Animal a1(a);
	cout << a1.color << endl; 
}
int main() {
	test1();
	return 0;
}