#include <iostream>
using namespace std;

/* ��ģ�����ã�
*		����һ��ͨ���࣬���еġ���Ա�������Ϳ��Բ�����ָ��������һ�����������������
*  �﷨��
*		template<typename T>
	    ����template ---  ��������ģ��
		    typename ---  ���������ķ�����һ���������ͣ�������class����
			T        ---  ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
*/

template<class NameType, class AgeType>
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

void test() {
	Panda<string, int> p("�����С����", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}