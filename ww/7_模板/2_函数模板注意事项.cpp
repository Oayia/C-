#include <iostream>
using namespace std;

//����ģ��ע������
template<class T>   //typename���滻Ϊclass
void mySwap(T& a,T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
//���Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
void test1() {
	int a = 2;
	int b = 3;
	char c = 'o';
	mySwap(a, b); //��ȷ
	//mySwap(a, c);  //�����Ƶ�����һ�µ�T����
	cout << a << " " << b << endl;

}

//��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func() {
	cout << "func����" << endl;
}
void test2() {
	//func(); //���󣬽����ʽ��������һ�����ͣ��磺func<int>();
	func<int>();
}

int main() {
	//test1();
	test2();
	return 0;
}