#include <iostream>
using namespace std;

/* ��̬
*  ��̬��Ϊ���ࣺ
*	  ��̬��̬���������� �� ������������ھ�̬���أ����ú�����
*     ��̬���أ���������麯��ʵ������ʱ��̬
* 
*  ��̬��̬�Ͷ�̬��̬����
*		��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
*		��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ
* 
*  ��̬��̬����������
*		1���м̳й�ϵ
*		2��������д������麯��
* 
*  ��̬��̬��ʹ�ã����������ָ���������
*/

class Animal {
public:
	//�麯��
	virtual void speak() {    //���ڸ���ķ���ǰ��virtual�ؼ��ֿ�ʵ�����
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal {
public:
	//��д����������ֵ���͡��������������б���ȫ��ͬ
	void speak() {
		cout << "������~" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "������~" << endl;
	}
};

//��ַ��� �ڱ���׶�ȷ��������ַ����Ϊ��ʱ��������Animal������
void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	Dog d;
	Cat c;
	doSpeak(d);   //��virtualǰ����ǣ�������˵��
	doSpeak(c);   //��virtualǰ����ǣ�������˵��
}

int main() {
	test01();
	return 0;
}