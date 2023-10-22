#include<iostream>
using namespace std;
//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person
{
public:
	//静态成员函数
	static void func()
	{
		m_A = 100;//静态成员函数可以访问静态成员变量
		m_B = 200;//静态成员函数不可以访问非静态成员变量,无法区分到底是哪个对象的m_B属性
		cout << "static void func 调用" << endl;
	}
	static int m_A;//静态成员变量
	int m_B//非静态成员变量
private:
	static void fun2()
	{
		cout << "static void fun2 调用" << endl;
	}
};
int Person::m_A = 0;
void test01()
{
	//两种访问方式
	
	//1.通过对象访问
	Person p;
	p.func();
	//2.通过类名访问
	Person::func();
	//Person::func2();
}

int main()
{
	test01();
	return 0;
}
