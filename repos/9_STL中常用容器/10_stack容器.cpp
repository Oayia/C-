#include <iostream>
#include <stack>
using namespace std;

/*
	1��stack����
		stack��һ���Ƚ������First In Last Out,FILO�������ݽṹ����ֻ��һ�����ڡ�ջ��ֻ�ж���Ԫ�زſ��Ա����ʹ�ã���ˣ�ջ�������б�����Ϊ
		push����ջ��pop����ջ
	
	2�����캯��:
		stack<T> stk;				//stack����ģ����ʵ�֣�stack�����Ĭ�Ϲ�����ʽ 
		stack(const stack &stk);	//�������캯�� 
	
	3����ֵ����:
		stack& operator=(const stack &stk);		//���صȺŲ����� 
	
	4�����ݴ�ȡ:
		push(elem);			//��ջ�����Ԫ�� 
		pop();				//��ջ���Ƴ���һ��Ԫ�� 
		top();				//����ջ��Ԫ�� 
	
	5����С����:
		empty(); //�ж϶�ջ�Ƿ�Ϊ�� 
		size(); //����ջ�Ĵ�С
*/

void test01() {
	stack<int> s;		//Ĭ�Ϲ���
	for (int i = 0; i < 5; i++) {
		s.push(i);
	}
	cout << "Ԫ�ظ�����" << s.size() << endl;
	//ֻҪջ��Ϊ�գ��鿴ջ������ִ�г�ջ����
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "Ԫ�ظ�����" << s.size() << endl;

}

int main() {
	test01();
	return 0;
}