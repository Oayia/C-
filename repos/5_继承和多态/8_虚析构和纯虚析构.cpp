#include <iostream>
using namespace std;
/* ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
   �����ʽ��
	   �������е�����������Ϊ���������ߴ�������
   
   �������ʹ����������ԣ�
       ���Խ������ָ���ͷ��������
	   ����Ҫ�о���ĺ���ʵ��
   �������ʹ�����������
		����Ǵ����������������ڳ����࣬�޷�ʵ��������
*/

class Animal {
public:
	Animal() {
		cout << "Animal���캯��" << endl;
	}
	//������ ���Խ������ָ���ͷ�������󲻸ɾ�������
	/*virtual ~Animal() {    
		cout << "Animal��������" << endl;
	}*/
	//��������  ��Ҫ����Ҳ��Ҫʵ��
	//���˴������� ֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};

//������������ʵ��
Animal::~Animal() {
	cout << "Animal��������";
}

class Cat :public Animal {
public:
	Cat(string name) {
		this->name = new string(name);
		cout << "Cat���캯��" << endl;
	}
	~Cat() {
		if (name != NULL) {
			delete name;
			name = NULL;
			cout << "Cat��������" << endl;
		}
	}
	void speak() {
		cout << *name << " " << "������~" << endl;
	}
	string* name;
};

void test01() {
	Animal* a = new Cat("�����");
	a->speak();
	delete a;   //����ָ��������ʱ�򣬲����������������������������������ж������ԣ������ڴ�й©��������ʽ��������������Ϊ������
	/* ִ�н����˵�������������û���ͷţ������ڴ�й¶
		Animal���캯��
		Cat���캯��
		����� ������~
		Animal��������
	*/
}

int main() {
	test01();
	return 0;
}