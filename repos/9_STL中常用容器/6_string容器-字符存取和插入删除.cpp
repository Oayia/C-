#include <iostream>
using namespace std;

/* 
	��string�е����ַ��Ĳ�ѯ�޸ģ�
		char& operator[](int n);		//ͨ��[]��ʽȡ�ַ�
		char& at(int n);				//ͨ��at��ʽ��ȡ�ַ�
	   ���ַ�ʽ������ɵ����ַ��Ĳ�ѯ�޸Ĳ���
	��string�����ɾ��
		string& insert(int pos, const char* s);			//�����ַ��� 
		string& insert(int pos, const string& str);		//�����ַ��� 
		string& insert(int pos, int n, char c);			//��ָ��λ�ò���n���ַ�C 
		
		string& erase(int pos, int n = npos);			//ɾ����Pos��ʼ��n���ַ�
*/

//��ѯ �޸�
void test() {
	string s = "hello";
	cout << s << endl;
	//��ѯ
	//ͨ��[]���ʵ����ַ�
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	//ͨ��at���ʵ����ַ�
	for (int i = 0; i < s.size(); i++) {
		cout << s.at(i) << " ";
	}
	cout << endl;

	//�޸ĵ����ַ�
	s[0] = 'u';
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	s.at(0) = 'g';
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

//���� ɾ��
void test1() {
	string s = "hello";
	//����
	s.insert(1, "yuio");   //hyuioello
	cout << s << endl;    
	s.insert(1, 5, 'j');  //hjjjjjyuioello
	cout << s << endl;
	//ɾ��
	s.erase(1, 5);
	cout << s << endl;

}

int main() {
	//test();
	test1();
	return 0;
}