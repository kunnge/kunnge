#include<iostream>
#include<string>
using namespace std;
//��������
class Building
{
	//goodGayȫ�ֺ�����Building������,���Է���Building��˽�г�Ա
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_BedRoom = "����";
		m_SittingRoom = "����";
	}
public:
	string m_SittingRoom;//����
private:
	string m_BedRoom;//����
};
//ȫ�ֺ���
void goodGay(Building* building)
{
	cout <<"�û���ȫ�ֺ��� ���ڷ��� " << building->m_SittingRoom << endl;
	cout <<"�û���ȫ�ֺ��� ���ڷ��� " << building->m_BedRoom<< endl;
}
void test01()
{
	Building building;
	goodGay(&building);
}
int main()
{
	test01();
	return 0;
}