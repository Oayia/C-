#include <iostream>
using namespace std;

/*�ṹ�壺�û��Զ����������ͣ������û��洢��ͬ����������
* struct �ṹ���� {�ṹ���Ա�б�}
	*/

//�ṹ��Ķ���
struct Student {
	string name;
	int age;
}s3;

struct Teacher {
	string name;
	int age;
};

struct Schcool {
	string name;
	Student s;
	Teacher t;
};

void printStudents(const Student* s);

int main() {
	//�ṹ�������ʹ�÷�ʽһ
	Student s1;
	s1.age = 14;
	s1.name = "�ǻ�";
	cout << s1.name << " " << s1.age << endl;

	//�ṹ�������ʹ�÷�ʽ��
	Student s2 = {"ѩŮ", 18};
	cout << s2.name << " " << s2.age << endl;

	//�ṹ�������ʹ�÷�ʽ��������ṹʱ˳�㴴���ṹ�������������
	s3.name = "�߽���";
	s3.age = 17;
	cout << s3.name << " " << s3.age << endl;


	/*
		�ṹ��ָ��
	*/
	Student s = { "����", 22 };
	Student* p = &s;
	cout << p->name << " " << p->age << endl;

	/*�ṹ��Ƕ�׽ṹ��*/
	Schcool sh = {
		"�����ʵ��ѧ",
		{"����", 22},
		{"������", 8}
	};
	cout << sh.name << " " << sh.s.name << " " << sh.t.name << endl;

	/*��ṹ����constʹ�ó���*/
	printStudents(&s);
	return 0;
}

void printStudents(const Student* s) {   //ָ�봫�ݿɽ�ʡ�ռ�
	//s->name = "sdfghjk";    //����const��һ�����޸Ĳ����ͻᱨ���ɷ�ֹ�����
	cout << s->name << " " << s->age << endl;
}
