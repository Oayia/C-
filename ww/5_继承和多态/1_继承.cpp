#include <iostream>
using namespace std;

/*
  һ���̳��﷨��class ���� : �̳з�ʽ ����
  �������ݷ���Ȩ���ܽ����ͬ�ķ������ͣ�
		����	  public	protected	private
		ͬһ����	yes		  yes	      yes
		������		yes		  yes	      no
		�ⲿ����	yes		  no	      no

  ���������ÿ�����Ա������ʾ���߲鿴����ģ��
	  ���cl /d1 reportSingleClassLayoutSon 1_�̳�.cpp
		1_�̳�.cpp

		class Son       size(16):
				+---
			0      | +--- (base class Base)
			0      | | a
			4      | | b
			8      | | c
				| +---
		12      | d
				+---
  
  �ġ��̳��еĹ��������˳��ִ��˳��
	   �ȹ��츸�࣬�ٹ������࣬����˳��͹����෴
  �塢�̳�ͬ����Ա����ʽ
	   ��������ͬ����Ա��ֱ�ӷ���
	   ���ʸ���ͬ����Ա��������������
  �����̳�ͬ����̬��Ա����ʽ
	   ��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
 

*/

class Base {
public:
	Base() {
		a = 100;
		cout << "���๹�캯��" << endl;
	}
	~Base() {
		cout << "������������" << endl;
	}
	void func() {
		cout << "�����е�func" << endl;
	}

public:
	int a;
	static int m_a;
protected:
	int b;
private:
	int c;
};

class Son :public Base {
public:
	Son() {
		a = 200;
		cout << "���๹�캯��" << endl;
	}
	~Son() {
		cout << "������������" << endl;
	}
	/*void func() {
		cout << "�����е�func" << endl;
	}*/

public:
	int a;
	static int m_a;
	int d;
};

int Base::m_a = 18;
int Son::m_a = 8;

void test01() {
	//���������зǾ�̬��Ա���Զ��ᱻ����̳�
	//������˽�г�Ա����ȷʵ���̳���ȥ�ˣ����Ǳ������������ˣ���˷��ʲ���
	//cout << sizeof(Son) << endl; //16�ֽ�

	Son s;/*ִ�н����
					���๹�캯��
					���๹�캯��
					������������
					������������
		  */
}

void test02() {
	Son s;
	cout << s.a << endl;  //200
	cout << s.Base::a << endl;  //��ͨ�����������ʸ�����ͬ����ͨ����
}

void test03() {
	Son s;
	s.func();   
	s.Base::func(); //��ͨ�����������ʸ�����ͬ����ͨ��Ա����
}

void test04() {
	//�������е�func����ע�ͣ�Ҳ����������û��func�����ˣ�ֻ�и������У��ǾͿ�ֱ�ӵ��ã�����������Ҳ�ɡ���Ϊ���������Ȼ��������ң�����û�У�Ȼ���ڸ����ҡ�
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	Son s;
	s.func();
}

void test05() {
	cout << Son::m_a << endl;
	cout << Son::Base::m_a << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
} 