#include <iostream>
using namespace std;

/*
	1����������
		���
			���ء��������ò����������࣬����󳣳�Ϊ����������
			��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�С��º�����
		����:
			��������(�º���)��һ�����ࡿ������һ������

	2����������ʹ��
		�ٺ���������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
		�ں������󳬳���ͨ�����ĸ����������������Լ���״̬
		�ۺ������������Ϊ��������

	3��
*/

class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	void operator()(string s) {
		count++;
		cout << s << endl;
	}
	int count;
};

//�ٺ���������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01() {
	MyAdd myadd;
	cout << myadd(2, 6) << endl;
}


//�ں������󳬳���ͨ�����ĸ����������������Լ���״̬
void test02() {
	MyPrint myprint;
	myprint("�����С����");
	myprint("�ͻ�С�ɰ�");
	myprint("Բ���Ƥ�����");

	cout << "myprint���ô�����" << myprint.count << endl;
}

void DoPrint(MyPrint& mp, string s) {
	mp(s);
}

//�ۺ������������Ϊ��������
void test03() {
	MyPrint myprint;
	DoPrint(myprint, "��������Ҷ���ܵ�");
}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}