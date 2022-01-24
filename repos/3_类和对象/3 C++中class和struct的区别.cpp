#include <iostream>
using namespace std;

/*C++中struct和class唯一的区别就在于默认的访问权限不同
	struct默认权限是pubic
	class默认权限是private
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
	//t.age = 10; //是不可访问的
	return 0;
}