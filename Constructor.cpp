#include<iostream>
using namespace std;
class Person
{
public:
	//�޲ι��캯��
	Person()
	{
		cout << "Person���޹��캯���ĵ���" << endl;
	}
	//�вι��캯��
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯���ĵ���" << endl;
	}
	//��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}
	//�������캯��
	Person(const Person &p)
	{
		cout << "Person�Ŀ���������������" << endl;
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
	//���ŷ�
	// ע�⣺Person p1();���Ǻ������������ǹ��캯��
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	//cout << p2.age << endl;
	//cout << p3.age << endl;
	//��ʾ��
	//Person p1;
	//Person p2=Person(10);
	//Person p3=Person(p2);
	//cout << "dddd" << endl;
	//��ʽת����
	Person p4 = 10;
	Person p5 = p4;
	//system("pause");
	return 0;
}