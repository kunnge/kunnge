#include"circle.h"
	//设置半径
	void Cricle::setR(int r)
	{
		C_R = r;
	}
	//获取半径
	int Cricle::getR()
	{
		return C_R;
	}
	//设置圆心
	void Cricle::setC(Point Center)
	{
		C_Center = Center;
	}
	//获取圆心
	Point Cricle::getC()
	{
		return C_Center;
	}
	int C_R;
	Point C_Center;

