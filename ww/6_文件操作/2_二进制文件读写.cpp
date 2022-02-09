#include <iostream>
#include <fstream>
using namespace std;

/* 
 以二进制的方式对文件进行读写操作，打开方式指定为ios::binary
*/

class Person {
public:
	char name[64];  //最好不要用string，C++的string可能会出现一些问题
	int age;
};

//二进制 写
void test1() {
	ofstream ofs("btest.txt", ios::out | ios::binary);
	Person p = { "福多多", 1 };
	//函数原型：ostream& write(const char * buffer, int len)，字符指针buffer指向内存中一段存储空间，len是读写的字节数
	ofs.write((const char*)(&p), sizeof(Person));
	ofs.close();
}

//二进制 读
void test2() {
	ifstream ifs("btest.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	Person p;
	//函数原型：istream& read(char* buffer, int len); 字符指针buffer指向内存中一段存储空间，len是读写的字节数
	ifs.read((char*)&p, sizeof(Person));
	cout << p.age << " " << p.name << endl;
	ifs.close();
}

int main() {
	//test1();
	test2();
	return 0;
}
