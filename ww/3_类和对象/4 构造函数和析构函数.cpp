#include <iostream>
using namespace std;

/*
	1�����캯�������������᡾���������Զ����á�����ɶ���ĳ�ʼ������������
	2���������û�ж��幹�캯����������������ô�����������ṩ�������ṩ�Ĺ��캯�������������ǿ�ʵ�֣�������Ϊ�գ���
*/

class Person {
	string name;
	int age;

public:
	Person(string n, int a) {
		name = n;
		age = a;
		cout << "���캯������" << endl;
	}

	~Person() {  //����������ǰ���Զ�������������������ֻ�����һ��
		cout << "������������" << endl;
	}
	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	void setAge(int a) {
		if (a < 0 || a>150) {
			age = 0;
		}
		else {
			age = a;
		}
	}

	int getAge() {
		return age;
	}
;
	
};
int main4() {
	Person p = Person("�ͻ�", 1);
	cout << p.getName() << " " << p.getAge() << endl;
	system("pause"); //����ִ�е��˴��жϵ���˼
	return 0;
}