#include <iostream>
using namespace std;

/* ����ģ�������̳�ʱ����Ҫע��ĵ㣺
	  ��������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
	  �������ָ�����������޷�����������ڴ�
	  ����������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/

template<class T>
class Animal {
	T m;
};


class Panda : public Animal<char> {  //ָ�����ͣ���ָ�����ͱ�����û�취ȥ����Ӹ���̳�������Ҫռ����ڴ�

};

void test() {
	Panda p;
}

//��������ָ��������T�����ͣ�����Ҳ��Ҫ��ģ��
template<class T1, class T2>
class Cat : public Animal<T2> {
public:
	Cat() {
		cout << typeid(T1).name() << "  " << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test1() {
	Cat<int, char> c;
}

int main() {
	test1();
	return 0;
}