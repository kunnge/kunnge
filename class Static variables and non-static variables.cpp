#include<iostream>
using namespace std;
class Person
{
	int m_A;//�Ǿ�̬��Ա����
	static int m_B;//��̬��Ա���� �������������
	void func(){}//�Ǿ�̬��Ա����
	static void func2(){}//��̬��Ա������������Ķ�����
};
int Person::m_B = 0;
void test01()
{
	Person p;
	//�ն���ռ���ڴ�ռ�Ϊ��
	//C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "size of p = " << sizeof(p) << endl;
}
void test02()
{
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}
int main()
{
	test02();
	return 0;
}