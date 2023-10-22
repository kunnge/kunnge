#include<iostream>
using namespace std;
//深拷贝与浅拷贝
// 浅拷贝：直接在一个地址上进行数据赋值操作
// 深拷贝：在堆区重新申请空间，进行拷贝操作
//前拷贝的问题就是堆区的内存重复释放
class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age, int height)
	{
		p_age = age;
		Height=new int(height);
		cout << "有参构造函数" << endl;
	}
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "拷贝构造函数" << endl;
		p_age = p.p_age;
		//Height = p.Height;编译器默认实现就是这行代码
		//深拷贝操作
		Height = new int(*p.Height);
	}
	~Person()
	{
		if (Height !=NULL)
		{
			delete Height;
			Height = NULL;
		}
		cout << "析构函数" << endl;
	}
	int p_age;
	int* Height;
};
void test01()
{
	Person p1(18,160);
	cout << "p1的年龄：" << p1.p_age<<" p1的身高："<<*p1.Height << endl;
	Person p2(p1);
	cout << "p2的年龄：" << p2.p_age <<" p2的身高：" << *p2.Height << endl;
}
int main()
{
	test01();
	return 0;
}
