#include<iostream>
#include<string>
using namespace std;
//类对象作为类成员

//手机类
class Phone
{
public:
	Phone(string pName)
	{
		m_pName = pName;
	}
	~Phone()
	{
		cout << "Phone的析构函数" << endl;
	}
	//手机品牌的名称
	string m_pName;
};
class Person
{
public:
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{

	}
	~Person()
	{
		cout << "Person的析构函数" << endl;
	}
	string m_Name;
	Phone m_Phone;
};
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
void test01()
{
	Person p("洪荣坤", "华为");
	cout << p.m_Name << endl;
	cout << p.m_Phone.m_pName << endl;
}
int main()
{
	test01();
	return 0;
}
