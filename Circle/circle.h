#pragma once
#include<iostream>
using namespace std;
#include"point.h"
class Cricle
{
public:
	//设置半径
	void setR(int r);
	//获取半径
	int getR();
	//设置圆心
	void setC(Point Center);
	//获取圆心
	Point getC();
private: 
	int C_R;
	Point C_Center;
};