#include<iostream>
using namespace std;
//���캯���ĵ��ù���
//����һ���࣬C++���������ÿ���඼�������3������
//Ĭ�Ϲ��죨��ʵ�֣�
//���캯������ʵ�֣�
//�������죨ֵ������
//2�������д���вι��캯�����������Ͳ����ṩĬ�Ϲ��캯������Ȼ�ṩ��������
//�������д�˿������캯�����������Ͳ����ṩ�������캯����
//�������캯��>�вι���>�޲ι��죨����ǰ��ľ�û�к���ģ�
class Person
{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int age)
	{
		cout << "�вι��캯��" << endl;
		p_age = age;
	}
	//Person(const Person &p)
	//{
	//	cout << "�������캯��" << endl;
	//	p_age = p.p_age;//Ĭ�ϵĿ������캯�����������ı�����ֵ��ֵ�����������ֵ
	//}
	~Person()
	{
		cout << "��������" << endl;
	}
	int p_age;
};
void test01()
{
	Person p1;
	p1.p_age = 18;
	Person p2(p1);
	cout << "p2�����䣺" << p2.p_age << endl;
}
void test02()
{
	Person p1(28);
	Person p2(p1);
	cout << "p2�����䣺" << p2.p_age << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}