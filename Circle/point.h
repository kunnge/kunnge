#pragma once
#include<iostream>
using namespace std;
class Point
{
public:
	//����x
	void setx(int x);
	//��ȡx
	int getx();
	//����y
	void sety(int y);
	//��ȡy
	int gety();
private:
	int m_x;
	int m_y;
};
