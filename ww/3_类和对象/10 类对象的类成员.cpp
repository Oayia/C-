#include <iostream>
using namespace std;

/*C++���еĳ�Ա��������һ����Ķ������ǳƸó�ԱΪ�����Ա
* ��ô����������Ķ���ʱ�������������Ա�Ĺ����������˳��˭��˭��
* ���ۣ�
*	������������Ϊ�����Ա������ʱ���ȹ����Ա�����ٹ�����������˳��͹����෴
*/

class Student {
public:

	Student(string n):name(n) {
		cout << "Student��ʼ��" << endl;
	}
	~Student() {
		cout << "Student��������" << endl;
	}
	string name;
};
class School {
public:
	School(string n, string s):name(n), stu(s) {   //��Student stu = s; ��ʽת�������ж���Ĵ���
		cout << "School��ʼ��" << endl;
	}
	~School() {
		cout << "School��������" << endl;
	}
	string name;
	Student stu;
};

int main10() {
	/* 38 39�����н����
			Student��ʼ��
			School��ʼ��
			�����
			School��������
			Student��������*/
	School sh("̫������", "�����");
	cout << sh.stu.name << endl;

	return 0;
}