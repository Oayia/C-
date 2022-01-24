#include <iostream>
using namespace std;

/* string�ַ���ƴ��
	 ����ԭ��:
		1��string& operator+=(const char* str);					//����+=������ 
		2��string& operator+=(const char c);					//����+=������ 
		3��string& operator+=(const string& str);				//����+=������ 
		4��string& append(const char* s);						//���ַ���s���ӵ���ǰ�ַ�����β 
		5��string& append(const char* s,int n);					//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β 
		6��string& append(const string& s);						//ͬoperator+=(const string&str) 
		7��string& append(const string& s, int pos, int n);		//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/

void test01() {
	string str1 = "��";
	str1 += "������Ϸ";           //1��string & operator+=(const char* str);
	cout << "str1��" << str1 << endl;

	str1 += 'o';           //2��string& operator+=(const char c);
	cout << "str1��" << str1 << endl;  

	string str2 = "uuu";
	str1 += str2;     //3��string& operator+=(const string& str);
	cout << "str1��" << str1 << endl;

	str1.append("yyyy");     //4��string& append(const char* s);
	cout << "str1��" << str1 << endl;

	str1.append("iiiii", 2);   //5��string& append(const char* s, int n);
	cout << "str1��" << str1 << endl;

	str1.append(str2);       //6��string& append(const string& s);
	cout << "str1��" << str1 << endl;

	str1.append(str2, 1, 1);     //7��string& append(const string& s, int pos, int n);
	cout << "str1��" << str1 << endl;
}

int main() {
	test01();
	return 0;
}