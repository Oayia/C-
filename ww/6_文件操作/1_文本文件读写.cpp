#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*���ļ�������
		�������в��������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷţ�ͨ���ļ����Խ����ݳ־û�
		C++�ж��ļ�������Ҫ������ͷ�ļ�<fstream>��

  ���ļ����ͷ�Ϊ���֣�
		�ı��ļ�����ASCII����ʽ�洢�ڼ������
		�������ļ������ı��Ķ�������ʽ�洢�ڼ������У��û�һ�㲻��ֱ�Ӷ���

  �������ļ��������ࣺ
		ofstream��д������������ļ���cout�������Ļ��
		ifstream���������������ڴ棨cin�����ڴ渳ֵ��ĳ������
		fstream����д����

  ���ļ��򿪷�ʽ��
	   �򿪷�ʽ		         ����
		ios:in			Ϊ���ļ������ļ�
		ios:out			Ϊд�ļ������ļ�
		ios:ate			��ʼλ�ã��ļ�β
		ios:app			׷�ӷ�ʽд�ļ�
		ios:trunc		����ļ�������ɾ���ٴ���
		ios:binary		�����Ʒ�ʽ
	 ע�⣺�ļ��򿪷�ʽ�������ʹ�ã�����|�����������ö����Ʒ�ʽд�ļ���ios:binary|ios:out��
*/

//�ı��ļ� д�ļ�
void test1() {
	ofstream ofs;
	ofs.open("test1.txt", ios::out);
	ofs << "�����С����" << endl;
	ofs << "�ͻ���ҶС����" << endl;
	ofs.close();
}

//�ı��ļ� ���ļ�
void test2() {
	ifstream ifs;
	ifs.open("test1.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//������
	//��ʽһ
	//char buf[1024] = { 0 };
	//while (ifs >> buf) { //һ��һ�ж�������buf��ȥ
	//	cout << buf << endl;
	//}
	//ifs.close();

	//��ʽ��
	/*char buf1[1024] = { 0 };
	while (ifs.getline(buf1, sizeof(buf1))) {
		cout << buf1 << endl;
	}*/

	//��ʽ��
	string buf2;
	while (getline(ifs, buf2)) {
		cout << buf2 << endl;
	}

	//��ʽ�ģ�һ���ַ�һ���ַ��Ķ���������ʹ��
	//char c;
	//while ((c = ifs.get()) != EOF) { //EOF end of file
	//	cout << c;
	//}
}

int main() {
	//test1();
	test2();
	return 0;
}