#include <iostream>
using namespace std;

/*C++��struct��classΨһ�����������Ĭ�ϵķ���Ȩ�޲�ͬ
	structĬ��Ȩ����pubic
	classĬ��Ȩ����private
*/
struct Student {
	int age;
};
class Teacher {
	int age;
};

int main3() {
	Student s;
	s.age = 8;
	cout << s.age << endl;

	Teacher t = Teacher();
	//t.age = 10; //�ǲ��ɷ��ʵ�
	return 0;
}