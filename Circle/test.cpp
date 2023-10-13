#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"
//class Point
//{
//public:
//	设置x
//	void setx(int x)
//	{
//		m_x = x;
//	}
//	获取x
//	int getx()
//	{
//		return m_x;
//	}
//	设置y
//	void sety(int y)
//	{
//		m_y = y;
//	}
//	获取y
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
//	//设置半径
//	void setR(int r)
//	{
//		C_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return C_R;
//	}
//	//设置圆心
//	void setC(Point Center)
//	{
//		C_Center = Center;
//	}
//	//获取圆心
//	Point getC()
//	{
//		return C_Center;
//	}
//private:
//	int C_R;
//	Point C_Center;
//};
//判断点与圆的关系
void isInCircle(Cricle& c, Point& p)
{
	//计算两点之间距离平方
	int distance =
		(c.getC().getx() - p.getx()) * (c.getC().getx() - p.getx()) +
		(c.getC().gety() - p.gety()) * (c.getC().gety() - p.gety());
	//计算半径的平方
	int rdistance = c.getR() * c.getR();
	//判断关系
	if (distance == rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance)
	{
		cout << "点在园外" << endl;
	}
	else
	{
		cout << "点在园内" << endl;
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
	//创建点
	Point p;
	p.setx(10);
	p.sety(11);
	//判断关系
	isInCircle(c, p);
	return 0;
}