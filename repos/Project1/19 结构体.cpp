#include <iostream>
using namespace std;

/*结构体：用户自定义数据类型，允许用户存储不同的数据类型
* struct 结构体名 {结构体成员列表}
	*/

//结构体的定义
struct Student {
	string name;
	int age;
}s3;

struct Teacher {
	string name;
	int age;
};

struct Schcool {
	string name;
	Student s;
	Teacher t;
};

void printStudents(const Student* s);

int main() {
	//结构体变量的使用方式一
	Student s1;
	s1.age = 14;
	s1.name = "星魂";
	cout << s1.name << " " << s1.age << endl;

	//结构体变量的使用方式二
	Student s2 = {"雪女", 18};
	cout << s2.name << " " << s2.age << endl;

	//结构体变量的使用方式三，定义结构时顺便创建结构体变量，不常用
	s3.name = "高渐离";
	s3.age = 17;
	cout << s3.name << " " << s3.age << endl;


	/*
		结构体指针
	*/
	Student s = { "盖聂", 22 };
	Student* p = &s;
	cout << p->name << " " << p->age << endl;

	/*结构体嵌套结构体*/
	Schcool sh = {
		"西安邮电大学",
		{"盖聂", 22},
		{"荆天明", 8}
	};
	cout << sh.name << " " << sh.s.name << " " << sh.t.name << endl;

	/*★结构体中const使用场景*/
	printStudents(&s);
	return 0;
}

void printStudents(const Student* s) {   //指针传递可节省空间
	//s->name = "sdfghjk";    //加入const后一旦有修改操作就会报错，可防止误操作
	cout << s->name << " " << s->age << endl;
}
