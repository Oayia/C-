#include <iostream>
using namespace std;
/*
	�������ã���Ҫ���������βΣ���ֹ�����
*/

void showValue(const int& val) {   //�ﳣ������ʹ�ó���
	//val = 1000;
	cout << val << endl;
}

int main2_3() {
	//int a = 10;
	//int& ref = 10; //���ñ�����һ��Ϸ����ڴ�ռ䣨�磺ջ����������ݣ�����������10���ڳ���������10����a���Ǿ��ǿ��Ե�
	//const int& ref = 10; //����const�Ϳ����ˡ�ֻ����Ϊ�������Դ���������Ż���int tmp = 10;  const int& ref = tmp; �������������������һ����ʱ�Ŀռ䣬������ռ䣬������Ҫ�������Ҳ�������ԭ����ԭ���Ǳ�������æ���
	//ref = 20; //��const���Ϊֻ�����������޸���

	int a = 9;
	showValue(a);
	cout << a << endl;
	return 0;
}