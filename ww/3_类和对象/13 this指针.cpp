#include <iostream>
using namespace std;

/*
	����֪������C++�У���Ա�����ͳ�Ա�����Ƿֿ��洢�ģ�ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ���������ͬ���͵Ķ���ṫ��һ�����
	��ô�������ǣ���һ�����������������ĸ���������Լ����أ�
	C++�ṩ����Ķ���ָ�룬thisָ�룬����������⡣thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

	thisָ����������ÿһ���Ǿ�̬��Ա�ڵ�һ��ָ�룬����Ҫ���壬ֱ��ʹ�ü���

	thisָ��ʹ�ó�����
		�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		������ķǾ�̬��Ա�����з��ض�������ʹ��return *this
*/

class Animal {
public:
	Animal(int age) {
		this->age = age;
	}
	Animal& AnimalAddAge(Animal& a) {   //�˴�����ֵ�����Animal���������ã�Animal&����ôÿ��*this���صĶ���һ���µĸ�����������a1����������������a1��ageʱ����20��������40
		this->age += a.age;
		cout << this->age << endl;
		return *this;    //��thisָ��a1��ָ�룬��*thisָ�����a1�������ı���
	}
	int age;
};

//1��������Ƴ�ͻ
void test01() {
	Animal a(18);
	cout << a.age << endl;
}
//2�����ض�������*this
void test02() {
	Animal a1(10);
	Animal a2(10);
	//��ʽ���˼��
	a1.AnimalAddAge(a2).AnimalAddAge(a2).AnimalAddAge(a2);
	cout << a1.age << endl;
}

int main13() {
	//test01();
	test02();
	return 0;
}