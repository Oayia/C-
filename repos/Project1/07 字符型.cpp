#include <iostream>
using namespace std;

int main7() {
	/*ע�⣺
		1��ֻ���ǵ����ַ���ʹ�õ����ţ�
		2��C/C++���ַ��ͱ���ֻռ��1���ַ���
		3���ַ��ͱ��������ǰ��ַ�����Ž��ڴ��д洢�����ǽ���Ӧ��ASCII�������洢��Ԫ*/
	char ch = 'w'; 
	cout << ch << endl;
	cout << int(ch) << endl; //�ַ�������Ӧ��ASCII����
	cout << "�ڴ���ռ�ڴ��С��" << sizeof(ch) << "�ֽ�" << endl;

	//char ch1 = "w"; //������ʾ��const char *���͵ı����������ڳ�ʼ��char���͵�ʵ��
	//char ch2 = 'fghjkl'; //������ʾ���ַ������е��ַ�����
	system("pause");
	return 0;
}