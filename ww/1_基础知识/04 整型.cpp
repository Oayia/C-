#include <iostream>
using namespace std;

/* C++�涨�ڴ���һ����������ʱ������Ҫָ����Ӧ���������ͣ������޷������������ڴ�
	��������				ռ�ÿռ�													ȡֵ��Χ
	short�������ͣ�			2�ֽ�													��-2^15��2^15-1��
	int�����ͣ�				4�ֽ�													��-2^31��2^31-1��
	long�������ͣ�			WindowsΪ4�ֽڣ�LinuxΪ4�ֽڣ�32λ����8�ֽڣ�64λ��		��-2^31��2^31-1��
	long long���������ͣ�	8�ֽ�                                                   ��-2^63��2^63-1��
  ���ʹ�С�Ƚϣ�short < int <= long <= long long

  �������ʹ��ڵ����壺
	������������ʵ��ڴ�ռ�
*/
int main4() {
	short num1 = 2;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "num1��" << num1 << endl;
	cout << "num2��" << num2 << endl;
	cout << "num3��" << num3 << endl;
	cout << "num4��" << num4 << endl;
	system("pause");
	return 0;
}