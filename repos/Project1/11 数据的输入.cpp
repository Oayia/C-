#include <iostream>
#include <typeinfo>
using namespace std;

/*ͨ��cin���������ֵ�ڲ�����ת*/
int main11() {
	//����
	int a = 0;
	cout << "������һ��������" << endl;
	cin >> a;
	cout << a << endl;
	cout << typeid(a).name() << endl;

	//С��
	float b = 3.14f;
	cout << "������һ��С����" << endl;
	cin >> b;
	cout << b << endl;
	cout << typeid(b).name() << endl;

	//�ַ���
	string c = "hhhjk";
	cout << "������һ���ַ�����" << endl;
	cin >> c;
	cout << c << endl;
	cout << typeid(c).name() << endl;
	return 0;
}