#include <iostream>
using namespace std;

//������Ԫ
class Building;
class GoodGirl {
public:
	GoodGirl();
	void visit(); //�ιۺ��� ����Building�е�����

public:
	Building* building;
};

class Building {
	friend class GoodGirl;     //GoodGirl�Ǳ������Ԫ��
public:
	Building();

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//����д��Ա����
Building::Building() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
GoodGirl::GoodGirl() {
	//�������������
	building = new Building;  //��new ������������newʲô�����������;ͷ���ʲô�������͵�ָ��
}
void GoodGirl::visit() {   //��ֻ���ں�����ǰ���
	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
}

void test01() {
	GoodGirl g;
	g.visit();
}
int main() {
	test01();
	return 0;

}