#include <iostream>
using namespace std;

/* ���ڶ�̬�У�ͨ���������麯��������ʵ��������ģ���Ҫ���ǵ���������д�����ݣ���˿��Խ��麯����Ϊ���麯��
*  �����麯����
		virtual ����ֵ���� ������(�����б�) = 0;
*  �����������˴��麯���������Ҳ��Ϊ������
*  ���������ص㣺
*		�޷�ʵ��������
*		���������д�������е��麯��������Ҳ���ڳ�����
*/


class Animal { //������
public:
	virtual void eat() = 0;  //���麯��
};

class Panda :public Animal {
public:
	void eat() {       //���������д�����еĴ��麯���������޷�ʵ��������
		cout << "����" << endl;
	}
};

void test01() {
	Animal* a = new Panda;
	a->eat();
}

int main() {
	test01();
	return 0;
}