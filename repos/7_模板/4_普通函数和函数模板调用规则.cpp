#include <iostream>
using namespace std;

/*
	��ͨ�����ͺ���ģ���ǿ��Է����������صģ����ù������£�
		1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
		2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
		3������ģ��Ҳ���Է�������
		4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

*/

void myPrint(int a, int b) {
	cout << "��ͨ����myPrint" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "ģ�庯��myPrint" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "��������ģ�庯��myPrint" << endl;
}

void test1() {
	int a = 9;
	int b = 8;
	//1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	myPrint(a, b); 
	//2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);
	//3������ģ��Ҳ���Է�������
	myPrint(a, b, 1);
	//4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);  //myPrint(int a, int b) �� void myPrint(T a, T b)��������ѡ���Ǻ���ģ�壬��Ϊ����������ѡ��int�Ļ�����ת��
}

int main() {
	test1();
	return 0;
}