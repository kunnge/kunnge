#include<iostream>
using namespace std;
//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person
{
public:
	//��̬��Ա����
	static void func()
	{
		m_A = 100;//��̬��Ա�������Է��ʾ�̬��Ա����
		m_B = 200;//��̬��Ա���������Է��ʷǾ�̬��Ա����,�޷����ֵ������ĸ������m_B����
		cout << "static void func ����" << endl;
	}
	static int m_A;//��̬��Ա����
	int m_B//�Ǿ�̬��Ա����
private:
	static void fun2()
	{
		cout << "static void fun2 ����" << endl;
	}
};
int Person::m_A = 0;
void test01()
{
	//���ַ��ʷ�ʽ
	
	//1.ͨ���������
	Person p;
	p.func();
	//2.ͨ����������
	Person::func();
	//Person::func2();
}

int main()
{
	test01();
	return 0;
}