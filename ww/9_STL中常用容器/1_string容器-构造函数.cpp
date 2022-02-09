#include <iostream>
using namespace std;

/* �����ʣ�
		string��C++�����ַ���������������һ���࣬ά��C���Ե��ַ���char*
   ��string��char*������
		char*��һ��ָ��
		string��һ���࣬���ڲ���װ��char*����������ַ�����һ��char*�͵�����
   ���ص㣺
		string���ڲ���װ�˺ܶ��Ա�������磺����find������copy��ɾ��delete���滻replace������insert
		string����char*��������ڴ棬���õ��ĸ�ֵԽ���ȡֵԽ�磬�����ڲ����и���
   ��string���캯����
		���캯��ԭ�ͣ�
			string();                    //����һ���յ��ַ��� ���磺string str;
			string(const char* s);       //ʹ���ַ���s��ʼ��
			string(const string& str);   //ʹ��һ��string�����ʼ����һ��string����
			string(int n, char c);       //ʹ��n���ַ�c��ʼ��
*/

//string�Ĺ��캯��
void test01() {
	string str1;
	string str2 = "dfghjk";
	string str3 = str2;
	string str4(6, 'o');
	str1 = str4;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << typeid(str2).name() << endl; //class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
	cout << typeid("dfghjk").name() << endl; //char const [7]
	//char c = "dfghjk";  //������ʾ��const char *���͵�ֵ�������ڳ�ʼ��char���͵�ʵ��
}

void test02() {
	string s1; //Ĭ�Ϲ���
	s1 = "yuio";
	cout << s1 << endl;
	
	const char* str = "Oayia";  //C���Է���ַ���
	char str1[] = "hello";    //C���Է���ַ���
	string s2(str);
	string s3(str1);
	cout << s2 << endl;
	cout << s3 << endl;

	string s4(s3);
	cout << s4 << endl;


}
int main() {
	//test01();
	test02();
	return 0;
}