#include <iostream>
using namespace std;

/*��ʼ���б�
	���ã���ʼ������
	�﷨�����캯��(����1�������� ����1,����2�������� ����2,...):����1(ֵ1),����2(ֵ2) ... {}
	
	*/

class Animal {
public:
	//��ͳ��ʼ������
	/*Animal(int a, int b, int c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}*/

	//��ʼ���б��ʼ������
	Animal(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {
		cout << "��ʼ��" << endl;
	}
	int m_a;
	int m_b;
	int m_c;
};

int main9() {
	Animal a(1, 2, 3);
	cout << a.m_a << " " << a.m_b << " " << a.m_c << endl;
	return 0;
}