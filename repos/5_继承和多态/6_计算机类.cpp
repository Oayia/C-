#include <iostream>
using namespace std;

/*
	�ڿ����У��ᳫ����ԭ��
	����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�

	���̬�����ĺô���
	   1����֯�ṹ����
	   2���ɶ���ǿ
	   3�����ں�����չ��ά��
*/

//������������
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int num1;
	int num2;
};

//�ӷ���������
class AddCalculator :public AbstractCalculator {
	int getResult() {
		return num1 + num2;
	}
};

//������������
class SubCalculator :public AbstractCalculator {
	int getResult() {
		return num1 - num2;
	}
};

//�˷���������
class MulCalculator :public AbstractCalculator {
	int getResult() {
		return num1 * num2;
	}
};

void test() {
	//��̬ʹ������������ָ�������ָ���������

	//�ӷ�
	AbstractCalculator* a = new AddCalculator;
	a->num1 = 4;
	a->num2 = 3;
	cout << a->getResult() << endl;
	//�����ǵ�����
	delete a;
}

int main() {
	
	test();
	return 0;
}