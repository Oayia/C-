#include <iostream>
using namespace std;

/* ��ģ��ͺ���ģ��������Ҫ�����㣺
	   1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
	   2����ģ����ģ������б��п�����Ĭ�ϲ���
*/

template<class NameType, class AgeType = int>  //��Ĭ�ϲ���
class Panda {
public:
	Panda(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void showPanda() {
		cout << name << " " << age << endl;
	}
	NameType name;
	AgeType age;
};

//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test1() {
	//Panda p("�ͻ�", 1);  //�����޷����Զ������Ƶ�
	Panda<string, int> p("�ͻ�", 1); //��ȷ��ֻ������ʽָ�����
	p.showPanda();
}

//2����ģ����ģ������б��п�����Ĭ�ϲ���
void test2() {
	Panda<string> p("��Ҷ", 1);
	p.showPanda();
}

int main() {
	test1();
	test2();
	return 0;
}