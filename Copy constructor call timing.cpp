#include<iostream>
using namespace std;
//拷贝构造函数调用时机
class Person
{
public:
	Person()
	{
		cout << "默认无参构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "有参构造函数调用" << endl;
		m_age = age;
	}
	Person(const Person& p)
	{
		cout << "拷贝构造函数调用" << endl;
		m_age = p.m_age;
	}
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
	int m_age;
};
//1使用一个已经创建完毕的对象来初始化一个对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2的年龄：" << p2.m_age << endl;
}
//2值传递的方式给函数参数传值
void dowork1(Person p)
{

}
void test02()
{
	Person p;
	dowork1(p);
}
//3值方式返回局部对象
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