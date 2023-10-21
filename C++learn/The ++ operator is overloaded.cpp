#include<iostream>
using namespace std;
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重置前置++运算符 返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		//先进行++运算
		m_Num++;
		//后将自身做返回
		return *this;
	}
	//重置后置++运算符
	//void operator++(int) int 代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		//先记录当时结果
		//记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，
		MyInteger temp = *this;
		//后递增
		m_Num++;
		//最后将记录结构做返回
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}