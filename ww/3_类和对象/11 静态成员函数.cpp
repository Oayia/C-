#include <iostream>
using namespace std;

/*��̬��Ա���ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա
* ��̬��Ա��Ϊ��
*	����̬��Ա����
*		�����ж�����ͬһ������
*		���ڱ���׶η����ڴ�
*		�����������������ʼ��
*	����̬��Ա����
*		�����ж�����ͬһ������
*		�ھ�̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/

class Animal {
public:
	//��̬��Ա����
	static void fun() {
		m_A++;
		//m_B++;  //��̬��Ա���������Է��ʷǾ�̬��Ա�������޷����ֵ������ĸ������
		cout<< "static void fun()����" << endl;
	}
	static int m_A; //��̬��Ա����
	int m_B; //�Ǿ�̬��Ա����
	
	//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static void fun2() {
		cout << "static void fun2" << endl;
	}

};

int Animal::m_A = 0;

void test1() {
	//1��ͨ���������
	Animal a;
	a.fun();
	//2��ͨ����������
	Animal::fun();
	cout << a.m_A << endl;

	//Animal::fun2();  ������ʲ���˽�о�̬��Ա����
}

int main11() {
	test1();
	return 0;
}