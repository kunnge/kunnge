#include<iostream>
using namespace std;
class Person
{
public:
	//1���ж��󶼹���ͬһ������
	//2����׶ξͷ����ڴ�
	//3���������������ʼ������
	static int m_A;
private:
	static int m_B;
};
int Person::m_A = 100;
int Person::m_B = 100;
void test01()
{
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}
void test02()
{
	//��̬��Ա����������ĳ�������ϣ����ж��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ
	//1ͨ��������з���
	Person p;
	cout << p.m_A << endl;
	//2ͨ���������з���
	cout << Person::m_A << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}