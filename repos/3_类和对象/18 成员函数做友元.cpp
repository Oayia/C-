#include <iostream>
using namespace std;

class Building;
class GoodGirl {
public:
	GoodGirl();
	void visit(); //�øú����ɷ���Building��˽�г�Ա
	void visit1();  //�ú��������Է���Building��˽�г�Ա


public:
	Building* building;
};

class Building {
	friend void GoodGirl::visit(); //����߱�����GoodGirl�µ�visit�����Ǳ������Ԫ��
public:
	Building();


public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGirl::GoodGirl() {
	building = new Building;
}
void GoodGirl::visit() {
	cout << "visit���ڷ��ʿ�����" << building->m_SittingRoom << endl;
	cout << "visit���ڷ������ң�" << building->m_BedRoom << endl;
}
void GoodGirl::visit1() {
	cout << "visit1���ڷ��ʿ�����" << building->m_SittingRoom << endl;
	//cout << "visit1���ڷ������ң�" << building->m_BedRoom << endl;
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