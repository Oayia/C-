#include <iostream>
using namespace std;

/*
	��ֵ�ĺ���ԭ��:
		1��string& operatod=(const char* s);		//const char*�����ַ�����ֵ����ǰ���ַ��� 
		2��string& operator=(const string& s);		//���ַ���s������ǰ���ַ��� 
		3��string& operator=(char c);				//�ַ���ֵ����ǰ���ַ��� 
		4��string& assign(const char* s);			//���ַ���s������ǰ���ַ��� 
		5��string& assign(const char* s,int n);	    //���ַ���s��ǰn���ַ�������ǰ���ַ��� 
		6��string& assign(const string& s);			//���ַ���s������ǰ�ַ��� 
		7��string& assign(int n, char c);			//��n���ַ�c������ǰ�ַ���
	
	һ��Ⱥž͹����ˣ�ǰ������������һ�㶼������ôȥд������Ա����assign�ķ�ʽ�˽⼴��
*/

void test1() {
	string str1;
	str1 = "�����";  //1��string& operatod=(const char* s);  const char*�����ַ�����ֵ����ǰ���ַ���
	cout << "str1��" << str1 << endl;

	string str2;
	str2= str1;  //2��string& operator=(const string& s);	���ַ���s������ǰ���ַ��� 
	cout << "str2��" << str2 << endl;

	string str3;
	str3 = 'o';  //3��string& operator=(char c);   �ַ���ֵ����ǰ���ַ��� 
	cout << "str3��" << str3 << endl; 

	string str4;
	str4.assign("Oayia");  //4��string& assign(const char* s);  ���ַ���s������ǰ���ַ��� 
	cout << "str4��" << str4 << endl;

	string str5; 
	str5.assign("hjdfghj", 3);       //5��string& assign(const char* s,int n);  ���ַ���s��ǰn���ַ�������ǰ���ַ���
	cout << "str5��" << str5 << endl; 

	string str6;
	str6.assign(str1);         //6��string& assign(const string& s);	 ���ַ���s������ǰ�ַ��� 
	cout << "str6��" << str6 << endl;

	string str7;
	str7.assign(9, 'u');   //7��string & assign(int n, char c);  ��n���ַ�c������ǰ�ַ���
	cout << "str7��" << str7 << endl;
}

int main() {
	test1();
	return 0;
}