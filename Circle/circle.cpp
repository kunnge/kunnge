#include"circle.h"
	//���ð뾶
	void Cricle::setR(int r)
	{
		C_R = r;
	}
	//��ȡ�뾶
	int Cricle::getR()
	{
		return C_R;
	}
	//����Բ��
	void Cricle::setC(Point Center)
	{
		C_Center = Center;
	}
	//��ȡԲ��
	Point Cricle::getC()
	{
		return C_Center;
	}
	int C_R;
	Point C_Center;

