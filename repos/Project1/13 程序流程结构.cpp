#include <iostream>
using namespace std;

int main13() {
	//ѡ��ṹ
	int num = 0;
	cout << "���������ĸ߿��ɼ���" << endl;
	cin >> num;
	if (num >= 650) {
		cout << "һ��" << endl;
	}
	else if(num >= 500){
		cout << "����" << endl;
	}
	else {
		cout << "����" << endl;
	}
	
	int a = 0;
	cout << "����õ�Ӱ��֣�" << endl;
	cin >> a;
	switch (a) { //ֻ�������ͻ��ַ��ͣ���������һ�����䣻switchִ��Ч�ʸ�
	case 10:
	case 9:
		cout << "����" << endl;
		break;
	case 8:
	case 7:
		cout << "�ǳ���" << endl;
		break;
	case 6:
	case 5:
		cout << "һ��" << endl;
		break;
	default:
		cout << "��Ƭ" << endl;
		break;
	}
	

	//ѭ���ṹ
	srand((unsigned int)time(NULL)); //������Ҫ����ͷ�ļ�#include <ctime>
	int num1 = rand()%100 +1;
	int num2 = 0;
	cout << num1 << endl;
	while (1) {
		cin >> num2;
		if (num2 > num1) {
			cout << "����" << endl;
		}
		else if (num2 < num1) {
			cout << "С��" << endl;
		}
		else {
			cout << "�¶���" << endl;
			break;
		}
	}
	
	int num3 = 0;
	do {
		cout << num3 << endl;
		num3++;
	} while (num3 < 10);
	
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}
	return 0;
}
