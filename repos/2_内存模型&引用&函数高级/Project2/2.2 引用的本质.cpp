#include <iostream>
using namespace std;

/*
���ʣ�
	������C++�ڲ�ʵ����һ����ָ�볣��������ָ���ָ���ǲ������޸ĵģ�ָ��ָ���ֵ�ǿ����޸ĵ�
	*/

//���������ã�ת��Ϊ��int * const ref = &a
void func(int& ref) { 
	ref = 100; //ref�����ã�ת��Ϊ��*ref = 100
}
int main2_2() {
	int a = 10;
	int& ref = a; //�Զ�ת��Ϊ��int* const ref = &a; ָ�볣��ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	ref = 20;  //�ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref = 20;
	cout << a << " " << ref << endl;
	func(a);
	cout << a << " " << ref << endl;

	return 0;
}