#include <iostream>
using namespace std;

//��ָ����ó�Ա����

class Animal {
public:
	void showClassName() {
		cout << "this is Animal class" << endl;
	}
	void showAnimalAge() {
		if (this == NULL) {  //��д������ǿ����Ľ�׳��
			return;
		}
		cout << age << endl;  //�˴�age����д�����ǣ�this->age

	}
	int age;
};

void test01() {
	Animal* a = NULL;
	a->showClassName(); //�˺�����������
	a->showAnimalAge();  //�˺������ñ�����������Ϊ�����ָ��ΪNULL������û������age

}

int main14() {
	test01();
	return 0;
}