#include <iostream>
using namespace std;

int func(int a, int b=20, int c=30) {  //1��Ĭ�ϲ�����������β��б�����
	return a + b + c;
}

//2��������ʵ��ֻ����һ����Ĭ�ϲ����������������֪��ѡ��������ʱ��Ĭ�ϲ���������ʵ��ʱ��Ĭ�ϲ�������������ֶ�����
int func1(int num1, int num2 = 3);
int func1(int num1, int num2) {
	return num1 + num2;
}

int main3_1() {
	cout << func(1) << endl;
	cout << func1(4) << endl;
	return 0;
}

