#include <iostream>
using namespace std;

/*
	���ַ����л�ȡ��Ҫ���Ӵ���
		string substr(int pos = 0, int n = npos) const;   //������pos��ʼ����n���ַ���ɵ��ַ���
*/

void test() {
	string s = "dfghjk";
	string ss = s.substr(3, 2);  //hj
	cout << ss << endl;
}

//ʵ�ò���
void test01() {
	string s = "ww@sina.com";
	//���ʼ��л�ȡ�û�����Ϣ
	int index = s.find("@");
	cout << s.substr(0, index) << endl;
}

int main() {
	//test();
	test01();
	return 0;
}