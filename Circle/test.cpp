#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"
//class Point
//{
//public:
//	����x
//	void setx(int x)
//	{
//		m_x = x;
//	}
//	��ȡx
//	int getx()
//	{
//		return m_x;
//	}
//	����y
//	void sety(int y)
//	{
//		m_y = y;
//	}
//	��ȡy
//	int gety()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};

//class Cricle
//{
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		C_R = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return C_R;
//	}
//	//����Բ��
//	void setC(Point Center)
//	{
//		C_Center = Center;
//	}
//	//��ȡԲ��
//	Point getC()
//	{
//		return C_Center;
//	}
//private:
//	int C_R;
//	Point C_Center;
//};
//�жϵ���Բ�Ĺ�ϵ
void isInCircle(Cricle& c, Point& p)
{
	//��������֮�����ƽ��
	int distance =
		(c.getC().getx() - p.getx()) * (c.getC().getx() - p.getx()) +
		(c.getC().gety() - p.gety()) * (c.getC().gety() - p.gety());
	//����뾶��ƽ��
	int rdistance = c.getR() * c.getR();
	//�жϹ�ϵ
	if (distance == rdistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "����԰��" << endl;
	}
	else
	{
		cout << "����԰��" << endl;
	}
}
int main()
{
	Cricle c;
	c.setR(10);
	Point center;
	center.setx(10);
	center.sety(0);
	c.setC(center); 
	//������
	Point p;
	p.setx(10);
	p.sety(11);
	//�жϹ�ϵ
	isInCircle(c, p);
	return 0;
}