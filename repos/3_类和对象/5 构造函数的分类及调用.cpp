#include <iostream>
using namespace std;

/*���캯�����ַ��෽ʽ��
	���������֣��вι��졢�޲ι��죨Ҳ��Ĭ�Ϲ��죩
	�����ͻ��֣���ͨ���졢��������
  ���ֵ��÷�ʽ��
	���ŷ�
	��ʾ��
	��ʽת����
*/
class Person {
public:
	Person() {
		cout << "�޲ι���" << endl;
	}
	Person(int a) {
		age = a;
		cout << "�вι���" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		cout << "�������캯��" << endl;
	}
	~Person() {
		cout << "��������" << endl;
	}
	int age;
};

void test01() {
	//1�����ŷ�
	Person p11;  //Ĭ�Ϲ���
	Person p22(10); //�вι���
	Person p33(p22); //�������캯��

	cout << p22.age << " " << p33.age << endl;

	//��ע������1��
	//      ����Ĭ�Ϲ��캯��ʱ����Ҫ������:()	
	//      ��Ϊд����Person p1();����������Ϊ��һ��������������������Ϊ�ڴ�������
	
	//2����ʾ��
	Person p1;
	Person p2 = Person(10);
	Person p3 = Person(p2);

	//Person(10); //�������� �ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
	//cout << "fghjk" << endl;

	//��ע������2��
	//		��Ҫ���ÿ������캯������ʼ���������󣬼�д����Person(p3);
	//		����������ΪPerson(p3);�ȼ���Person p3; ���Իᱨ�ض���Ĵ���
	// 
	
	//3����ʽת����
	Person p4 = 10; //�൱��д�ˣ�Person p4 = Person(10);  �вι���
	Person p5 = p4; //��������
}

int main5() {
	test01();
	system("pause");
	return 0;
}