#pragma once
#include<iostream>
using namespace std;
#include"point.h"
class Cricle
{
public:
	//���ð뾶
	void setR(int r);
	//��ȡ�뾶
	int getR();
	//����Բ��
	void setC(Point Center);
	//��ȡԲ��
	Point getC();
private: 
	int C_R;
	Point C_Center;
};