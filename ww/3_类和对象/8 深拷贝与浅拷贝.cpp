#include <iostream>
using namespace std;

//ǳ�������򵥵ĸ�ֵ������������ǳ����������������Ƕ������ڴ��ظ��ͷš���ǳ������������Ҫ��������
//������ڶ�����������ռ䣬���п�������

class Animal {
public:
	Animal() {
		cout << "�޲ι������" << endl;
	}
	Animal(int a, int h) {
		age = a;
		height = new int(h);
		cout << "�вι������" << endl;
	}
	Animal(const Animal& a) {
		age = a.age;
		//height = a.height;  //������Ĭ��ʵ�־������д���
		height = new int(*a.height);   //���
	}
	~Animal() {
		//�������룬���������ٵ��������ͷŲ���
		if (height != NULL) {
			//��ǳ���������a��a1��height���Զ�Ӧ����ͬһ���ڶ��е��ڴ棬�Ǹ���ջ�Ƚ�������ص��������������Ķ�����a1��
			//������a�������˴�ִ��deleteʱ�����ϵ�����ڴ��Ѿ��ͷţ��Ѳ�����ʹ��
			delete height; 
			height = NULL;
		}
		cout << "������������" << endl;
	}

	int age;
	int* height;
};

void test1() {
	Animal a(18, 160);
	cout << a.age << " " << *a.height << endl;
	Animal a1(a);
	cout << a1.age << " "<< *a1.height<< endl;
}

int main8() {
	test1();
	return 0;
}