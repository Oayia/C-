#include <iostream>
using namespace std;

/* 
* ��ͨ�����ͺ���ģ�������
*	 ����ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
*	 �ں���ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
*    �����������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
* 
*/
//��ͨ����  ���Է����Զ�����ת������ʽ����ת����
int add1(int a, int b) {
	return a + b;
}

void test1() {
	int a = 9;
	int b = 3;
	char c = 'c';  //a - 97 c - 99
	cout << add1(a, b) << endl;
	cout << add1(a, c) << endl;
}

//����ģ��
template<class T>
T add(T a, T b) {
	return a + b;
}

void test() {
	int a = 9;
	int b = 3;
	char c = 'c';
	//�Զ������Ƶ�  ���ᷢ����ʽ����ת��
	cout << add(a, b) << endl;
	//cout << add(a, c) << endl; //����

	//��ʽָ������  ���Է�����ʽ����ת��
	cout << add<int>(a, c) << endl;
}

int main() {
	test1();
	test();
	return 0;
}