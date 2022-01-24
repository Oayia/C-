#include <iostream>
#include <fstream>
using namespace std;

/* 
 �Զ����Ƶķ�ʽ���ļ����ж�д�������򿪷�ʽָ��Ϊios::binary
*/

class Person {
public:
	char name[64];  //��ò�Ҫ��string��C++��string���ܻ����һЩ����
	int age;
};

//������ д
void test1() {
	ofstream ofs("btest.txt", ios::out | ios::binary);
	Person p = { "�����", 1 };
	//����ԭ�ͣ�ostream& write(const char * buffer, int len)���ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
	ofs.write((const char*)(&p), sizeof(Person));
	ofs.close();
}

//������ ��
void test2() {
	ifstream ifs("btest.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Person p;
	//����ԭ�ͣ�istream& read(char* buffer, int len); �ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
	ifs.read((char*)&p, sizeof(Person));
	cout << p.age << " " << p.name << endl;
	ifs.close();
}

int main() {
	//test1();
	test2();
	return 0;
}
