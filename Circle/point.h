#pragma once
#include<iostream>
using namespace std;
class Point
{
public:
	//设置x
	void setx(int x);
	//获取x
	int getx();
	//设置y
	void sety(int y);
	//获取y
	int gety();
private:
	int m_x;
	int m_y;
};
