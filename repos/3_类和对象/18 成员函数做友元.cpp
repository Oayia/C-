#include <iostream>
using namespace std;

class Building;
class GoodGirl {
public:
	GoodGirl();
	void visit(); //让该函数可访问Building中私有成员
	void visit1();  //该函数不可以访问Building中私有成员


public:
	Building* building;
};

class Building {
	friend void GoodGirl::visit(); //★告诉编译器GoodGirl下的visit函数是本类的友元类
public:
	Building();


public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGirl::GoodGirl() {
	building = new Building;
}
void GoodGirl::visit() {
	cout << "visit正在访问客厅：" << building->m_SittingRoom << endl;
	cout << "visit正在访问卧室：" << building->m_BedRoom << endl;
}
void GoodGirl::visit1() {
	cout << "visit1正在访问客厅：" << building->m_SittingRoom << endl;
	//cout << "visit1正在访问卧室：" << building->m_BedRoom << endl;
}

void test01() {
	GoodGirl g;
	g.visit();
	g.visit1();
}
int main() {
	test01();
	return 0;
}