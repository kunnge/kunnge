#include<iostream>
using namespace std;
class Person
{
public:
	//无参构造函数
	Person()
	{
		cout << "Person的无构造函数的调用" << endl;
	}
	//有参构造函数
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数的调用" << endl;
	}
	//析构函数
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		cout << "Person的拷贝析构函数调用" << endl;
		age = p.age;
	}
	void test01()
	{
		Person p;
	}
	int age;
};

int main()
{		
	//括号法
	// 注意：Person p1();这是函数声明而不是构造函数
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	//cout << p2.age << endl;
	//cout << p3.age << endl;
	//显示法
	//Person p1;
	//Person p2=Person(10);
	//Person p3=Person(p2);
	//cout << "dddd" << endl;
	//隐式转换法
	Person p4 = 10;
	Person p5 = p4;
	//system("pause");
	return 0;
}