#include<iostream>
#include<string>
using namespace std;
//�������Ϊ���Ա

//�ֻ���
class Phone
{
public:
	Phone(string pName)
	{
		m_pName = pName;
	}
	~Phone()
	{
		cout << "Phone����������" << endl;
	}
	//�ֻ�Ʒ�Ƶ�����
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
		cout << "Person����������" << endl;
	}
	string m_Name;
	Phone m_Phone;
};
//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������
void test01()
{
	Person p("������", "��Ϊ");
	cout << p.m_Name << endl;
	cout << p.m_Phone.m_pName << endl;
}
int main()
{
	test01();
	return 0;
}