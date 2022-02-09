#include <iostream>
#include <queue>
using namespace std;

/*
	1��queue����
		��queue��һ���Ƚ��ȳ���First in First Out�������ݽṹ��������������
		�ڶ������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
		�۶�����ֻ�ж�ͷ��front���Ͷ�β��back���ſ��Ա����ʹ�ã���ˣ����в������б�����Ϊ
		�ܶ����У������ݳ�Ϊ��� push�������ݳ�Ϊ���� pop
	
	2�����캯��:
		queue<T> que; //queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ 
		queue(const queue &que); //�������캯�� 
	
	3����ֵ����:
		queue& operator=(const queue &que); //���صȺŲ����� 
	
	4�����ݴ�ȡ:
		push(elem); //����β���Ԫ�� 
		pop(); //�Ӷ�ͷ�Ƴ���һ��Ԫ�� 
		back(); //�������һ��Ԫ�� 
		front(); /���ص�һ��Ԫ�� 
	
	5����С����:
		empty(); //�ж϶�ջ�Ƿ�Ϊ�� 
		size(); //����ջ�Ĵ�С
*/

class Panda {
public:
	Panda(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};

void test() {
	queue<Panda> q;
	Panda p1("�ͻ�", 1);
	Panda p2("��Ҷ", 1);
	Panda p3("�����", 1);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	if (!q.empty()) {
		cout << q.size() << endl;		//3
		cout << q.front().name << " " << q.front().age << endl;	//�ͻ� 1
		cout << q.back().name << " " << q.back().age << endl;	//����� 1
	}
	q.pop();
	cout << q.front().name << " " << q.front().age << endl;		//��Ҷ 1
	cout << q.size() << endl;			//2
}

int main() {
	test();
	return 0;
}