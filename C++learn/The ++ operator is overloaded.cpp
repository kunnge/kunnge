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
	//����ǰ��++����� ��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++()
	{
		//�Ƚ���++����
		m_Num++;
		//������������
		return *this;
	}
	//���ú���++�����
	//void operator++(int) int ����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)
	{
		//�ȼ�¼��ʱ���
		//��¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ��
		MyInteger temp = *this;
		//�����
		m_Num++;
		//��󽫼�¼�ṹ������
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