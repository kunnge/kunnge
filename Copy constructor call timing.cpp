#include<iostream>
using namespace std;
//�������캯������ʱ��
class Person
{
public:
	Person()
	{
		cout << "Ĭ���޲ι��캯������" << endl;
	}
	Person(int age)
	{
		cout << "�вι��캯������" << endl;
		m_age = age;
	}
	Person(const Person& p)
	{
		cout << "�������캯������" << endl;
		m_age = p.m_age;
	}
	~Person()
	{
		cout << "������������" << endl;
	}
	int m_age;
};
//1ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ������
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2�����䣺" << p2.m_age << endl;
}
//2ֵ���ݵķ�ʽ������������ֵ
void dowork1(Person p)
{

}
void test02()
{
	Person p;
	dowork1(p);
}
//3ֵ��ʽ���ؾֲ�����
Person dowork2()
{
	Person p1;
	cout<<(int*)&p1<<endl;
	return p1;
}
void test03()
{
	Person p = dowork2();
	cout << (int*)&p << endl;

}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}