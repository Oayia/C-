#include <iostream>
using namespace std;

class Student {
private:
	string name;
	string id;
public:
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	void setId(string i) {
		id = i;
	}

	string getId() {
		return id;
	}

	void printStudentInfo() {
		cout << name << " " << id;
	}
};

int main2() {
	Student s = Student();
	s.setName("¸£¶à¶à");
	s.setId("02152027");
	s.printStudentInfo();
	return 0;
}