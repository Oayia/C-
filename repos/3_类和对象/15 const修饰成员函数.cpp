#include <iostream>
using namespace std;

/*
	��������
		���Ա�������const�����ǳ�֮Ϊ������
		�򳣺����ڲ������޸ĳ�Ա����
		���Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
	������
		����������ǰ��const�ƶ���Ϊ������
		�򳣶���ֻ�ܵ��ó�����
		
*/

class Animal {
public:
	//thisָ��ı�����ָ�볣������ָ���ָ���ǲ������޸ĵģ�ָ��ָ���ֵ�ǿ����޸ĵ�
	//�ڳ�Ա�������const�����ε���thisָ����ָ��ָ���ֵҲ�����޸�
	void showAnimal() const{  //��Ч��const Animal* const this����ָ��ָ���ָ��ָ���ֵ�������޸���
		//age = 2; //������ʾ�����ʽ�����ǿ��޸ĵ���ֵ
		name = "�����";
		cout << name << endl;
	}
	void fun(){}
	int age;
	mutable string name;  //�����������ʹ�ڳ������кͳ�������Ҳ���޸����ֵ���ӹؼ���mutable
};

void test01() {
	Animal a;
	a.showAnimal();
}

//������
void test02() {
	const Animal a;  //�ڶ���ǰ��const���䳣����
	//a.age = 1;
	a.name = "�ͻ�"; //name��mutable���Σ��ڳ�������Ҳ�����޸�
	a.showAnimal();
	//a.fun();  ������ֻ�ܵ��ó����������ܵ���ͨ��Ա��������Ϊ��ͨ��Ա����ʱ�����޸����Ե�
}

int main() {
	test01();
	return 0;
}