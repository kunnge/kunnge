#include<iostream>
#include<string>
using namespace std;
//建筑物类
class Building
{
	//goodGay全局函数是Building好朋友,可以访问Building中私有成员
	friend void goodGay(Building* building);
public:
	Building()
	{
		m_BedRoom = "卧室";
		m_SittingRoom = "客厅";
	}
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};
//全局函数
void goodGay(Building* building)
{
	cout <<"好基友全局函数 正在访问 " << building->m_SittingRoom << endl;
	cout <<"好基友全局函数 正在访问 " << building->m_BedRoom<< endl;
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