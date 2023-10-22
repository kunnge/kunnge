#include<iostream>
using namespace std;
//构造函数的调用规则
//创建一个类，C++编译器会给每个类都添加至少3个函数
//默认构造（空实现）
//构造函数（空实现）
//拷贝构造（值拷贝）
//2如果我们写了有参构造函数，编译器就不再提供默认构造函数，依然提供拷贝构造
//如果我们写了拷贝构造函数，编译器就不再提供其他构造函数了
//拷贝构造函数>有参构造>无参构造（有了前面的就没有后面的）
class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age)
	{
		cout << "有参构造函数" << endl;
		p_age = age;
	}
	//Person(const Person &p)
	//{
	//	cout << "拷贝构造函数" << endl;
	//	p_age = p.p_age;//默认的拷贝构造函数会把外边来的变量的值赋值到里面变量的值
	//}
	~Person()
	{
		cout << "析构函数" << endl;
	}
	int p_age;
};
void test01()
{
	Person p1;
	p1.p_age = 18;
	Person p2(p1);
	cout << "p2的年龄：" << p2.p_age << endl;
}
void test02()
{
	Person p1(28);
	Person p2(p1);
	cout << "p2的年龄：" << p2.p_age << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}
