#include <iostream>
using namespace std;

/* ��������
   �����ú�������ͬ����߸�����

   ������������������
	����ͬһ��������
	����������ͬ
	���������������͡���ͬ ���� ����������ͬ ���� ��˳�򡿲�ͬ
   ���������ķ���ֵ��������Ϊ�������ص�����

   �ﺯ�����ص�ע�����
		1��������Ϊ���ص�����
		2��������������Ĭ�ϲ���
*/

void func() {
	cout << "func�ĵ���" << endl;
}
// 1��������Ϊ���ص�����
void fun(int& a) {  //int& a = 10; ���Ϸ�
	cout << "fun(int& a)�ĵ���" << endl;
}
void fun(const int& a) { //const int& a = 10; �Ϸ�
	cout << "fun(const int& a)�ĵ���" << endl;
}

//2��������������Ĭ�ϲ���
void fun2(int a, int b = 8) {
	cout << "fun2(int a, int b = 8)�ĵ���" << endl;
}
void fun2(int a) {
	cout << "fun2(int a)�ĵ���" << endl;
}

int main3_3() {
	int a = 10;
	fun(a); //���õ��ǲ���const�ĺ���
	fun(10); //���õ��Ǻ���const�ĺ���

	//fun2(2);  //��ʱ��������֪���õ����Ǹ������ˣ������ֶ�����
	fun2(1, 2);
	return 0;

}