#include <iostream>
using namespace std;

/*������sizeof�����������ռ���ڴ��С
  �﷨��
	sizeof(��������/����)
*/

int main5() {
	short num1 = 2;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "shortռ���ڴ�ռ�Ϊ��" << sizeof(num1) << endl;
	cout << "intռ���ڴ�ռ�Ϊ��" << sizeof(int) << endl;
	cout << "longռ���ڴ�ռ�Ϊ��" << sizeof(num3) << endl;
	cout << "long longռ���ڴ�ռ�Ϊ��" << sizeof(num4) << endl;
	system("pause");
	return 0;
}