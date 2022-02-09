#include <iostream>
using namespace std;

/* ģ�������Ԫ���������ں�����ʵ�֣�
*		ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
*		ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
*/

//ͨ��ȫ�ֺ�����ӡPerson��Ϣ

template<class T1, class T2>
class Person;
//����ʵ��
template<class T1, class T2>
void printPerson1(Person<T1, T2>& p) {  //����ģ���ʵ��
	cout << p.name << " " << p.age << endl;
}

template<class T1, class T2>
class Person {
	//ȫ�ֺ��� ����ʵ��
	friend void printPerson(Person<T1, T2>& p) {
		cout << p.name << " " << p.age << endl;
	}

	//ȫ�ֺ��� ����ʵ��
	//�ӿ�ģ������б�<>
	friend void printPerson1<>(Person<T1, T2>& p);  //��ͨ����������������ģ�����к���
public:
	Person(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};



//1��ȫ�ֺ�������ʵ��
void test1() {
	Person<string, int> p("����", 3);
	printPerson(p);
}

//1��ȫ�ֺ�������ʵ��
void test2() {
	Person<string, int> p("�ɷ�", 3);
	printPerson1(p);
}

int main() {
	test1();
	test2();
	return 0;
}