#include <iostream>
//�����ʽһ���޸�Ϊ #include "panda.cpp"  
//����panda.hͷ�ļ���ʱ���൱�ڰ�ͷ�ļ����Ƕδ����ñ����������ˣ�����������cpp�ļ���������.h�ļ�����������������������panda.cpp�е����ݱ���������û�м�����
#include "panda.hpp"    
using namespace std;

/*
	��ģ����ļ���д���⣺
		��ģ���г�Ա��������ʱ�����ڵ���ʱ�����·��ļ���дʱ���Ӳ���
	�����������ַ�ʽ��
		1��ֱ�Ӱ���.cpp�ļ�   һ����˵û������ȥ���ģ��������ñ���ȥ��Դ��Դ�ļ�
		2��������.h��ʵ��.cppд��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�����ǿ��
*/

//template<class T1, class T2>
//class Panda {
//public:
//	Panda(T1 name, T2 age);
//	void showPanda();
//	T1 name;
//	T2 age;
//};

//template<class T1, class T2>
//Panda<T1, T2>::Panda(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
//template<class T1, class T2>
//void Panda<T1, T2>::showPanda() {
//	cout << name << " " << age << endl;
//}

void test() {
	Panda<string, int> p("�����", 1);
	p.showPanda();
}

int main() {
	test();
	return 0;
}