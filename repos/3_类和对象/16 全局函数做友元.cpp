#include <iostream>
using namespace std;

/*����Ԫ
*		�������У���Ŀ�����public�������ң�˽�У����������������Ŀ��˶����Խ�ȥ�������������˽�еģ�ֻ���Լ����Խ��������أ���Ҳ����������ĺù��۽�ȥ��
		�ڳ������Щ˽������Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ��
  ����Ԫ��Ŀ�ľ�����һ�����������������һ������˽�г�Ա��
  ���ؼ��֣�friend
  ����Ԫ����ʵ�֣�
		1��ȫ�ֺ�������Ԫ
		2��������Ԫ
		3�����г�Ա��������Ԫ
	
*/

class Building {
	friend void goodFriend(Building* b);  //�������м���
public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
	string m_SittingRoom; //����
private:
	string m_BedRoom;  //����
};

//ȫ�ֺ���
void goodFriend(Building* b) {
	cout << "������ȫ�ֺ������ڷ��ʣ�" << b->m_SittingRoom << endl;  //���ʹ�������
	cout << "������ȫ�ֺ������ڷ��ʣ�" << b->m_BedRoom << endl;    //����˽������
}

void test01() {
	Building b;
	goodFriend(&b);
}

int main() {
	test01();
	return 0;
}