#include<iostream>
using namespace std;
//�����ǳ����
// ǳ������ֱ����һ����ַ�Ͻ������ݸ�ֵ����
// ������ڶ�����������ռ䣬���п�������
//ǰ������������Ƕ������ڴ��ظ��ͷ�
class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int age, int height)
	{
		p_age = age;
		Height=new int(height);
		cout << "�вι��캯��" << endl;
	}
	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	Person(const Person& p)
	{
		cout << "�������캯��" << endl;
		p_age = p.p_age;
		//Height = p.Height;������Ĭ��ʵ�־������д���
		//�������
		Height = new int(*p.Height);
	}
	~Person()
	{
		if (Height !=NULL)
		{
			delete Height;
			Height = NULL;
		}
		cout << "��������" << endl;
	}
	int p_age;
	int* Height;
};
void test01()
{
	Person p1(18,160);
	cout << "p1�����䣺" << p1.p_age<<" p1����ߣ�"<<*p1.Height << endl;
	Person p2(p1);
	cout << "p2�����䣺" << p2.p_age <<" p2����ߣ�" << *p2.Height << endl;
}
int main()
{
	test01();
	return 0;
}