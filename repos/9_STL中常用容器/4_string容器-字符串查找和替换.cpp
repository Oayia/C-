#include <iostream>
using namespace std;

/* �ַ������Һ��滻��
	����ԭ��:
	  ���ң�
		1��int find(const string& str, int pos=0) const;			//����str��һ�γ���λ�ô�pos��ʼ���� 
		2��int find(const char* s, int pos=0) const;				//����s��һ�γ���λ�ô�pos��ʼ���� 
		3��int find(const char* s, int pos, int n) const;			//��posλ�ò���s��ǰn���ַ���һ��λ�� 
		4��int find(const char c, int pos=0) const;					//�����ַ�c��һ�γ���λ�� 
		5��int rfind(const string& str, int pos=npos) const;		//����str���һ��λ�ô�pos��ʼ���� 
		6��int rfind(const char* s, int pos=npos) const;			//����s���һ�γ���λ�ô�pos��ʼ���� 
		7��int rfind(const char* s, int pos, int n) const;			//��pos����s��ǰn���ַ����һ��λ�� 
		8��int rfind(const char c, int pos=0) const;				//�����ַ�c���һ�γ���λ�� 
	  �滻��
		1��string& replace(int pos, int n, const string& str):		//�滻��pos��ʼn���ַ�Ϊ�ַ���str 
		2��string& replace(int pos, int n, const char* s);			//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/

//����  ���÷���
void test() {
	//find �������� �ҵ����ص�һ�����������ĵ�һ���ַ���λ�ã��Ҳ�������-1
	string s = "helloo C++oo";
	//�Ҳ���ʱ��
	int index = s.find("lll");
	cout << index << endl;    //-1
	cout << s.find("lll") << endl;  //4294967295  4294967295���޷���λ���������ֵ��Ҳ�����з���λ����-1
	if (s.find("lll") == -1) {
		cout << "rTYUIop" << endl;   //rTYUIop
	}
	//�ҵ�ʱ 
	index = s.find("oo");
	cout << "oo��" << index << endl;


	//rfind  ��������
	index = s.rfind("lll");
	cout << index << endl;    //-1
	cout << s.rfind("lll") << endl;   //4294967295

}

//�滻
void test02() {
	string s = "sdfghjkl";  //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
	s.replace(1, 3, "oo");
	cout << s << endl;   //soohjkl
}



int main() {
	test();
	//test02();
	return 0;
} 
