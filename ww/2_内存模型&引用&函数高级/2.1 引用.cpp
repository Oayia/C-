#include <iostream>
using namespace std;

/*
  ���ã������������
  �﷨���������� & ����
  
  ע�����
	1�����ñ����ʼ��
	2�������ڳ�ʼ���󣬲����Ըı�
*/

int add(int& a, int& b);
int& test01();
int& test02();

int main2_1() {
	int a = 1;
	int& b = a; 
	cout << a << " " << b << endl;
	b = 100;	
	cout << a << " " << b << endl;

	//1����������������
	int num1 = 2;
	int num2 = 3;
	cout << add(num1, num2) << endl;

	//2������������ֵ
	//��2.1����Ҫ���ؾֲ�����������
	//int& ref = test01();
	//cout << ref << endl;
	//cout << ref << endl; //�ڶ��ν��������Ϊ�ֲ�����a���ڴ��Ѿ��ͷţ���һ����ȷֻ����Ϊ���������˶��ݵı���

	//2.2�������ĵ��ÿ�����Ϊ��ֵ
	int& ref2 = test02();
	cout << ref2 << endl;
	cout << ref2 << endl;
	test02() = 1000;
	cout << ref2 << endl;
	cout << ref2 << endl;
	return 0;
}

int add(int& a, int& b) {   //�β��൱����ʵ�εı���
	a = 99; //��ַ���ݺ����ã��βλ�����ʵ��
	return a + b;
}


int& test01() {
	int a = 456;
	return a;
}

int& test02() {
	static int a = 456; //��̬����������ȫ������ȫ���������ڳ����������ϵͳ�ͷ�
	return a;
}
