#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void menu()
{
	printf("*************************\n");
	printf("********1.��ʼ***********\n");
	printf("********2.�˳�***********\n");
	printf("*************************\n");
}
void game()//������
{
	char arr[ROW][CLO] = {0};
	//��ʼ������
	InitBoard(arr, ROW, CLO);
	Displayboard(arr,ROW,CLO);
	//��ʼ����
	while (1)
	{
		int num = 0;
		PlayerMove(arr,ROW,CLO);
		Displayboard(arr, ROW, CLO);
		num = IsWin(arr, ROW, CLO);
		if (1 == num || 2 == num || 3 == num || 4 == num )
		{
			printf("���Ӯ��\n");
			break;
		}
		if (5 == num)
		{
			printf("ƽ��\n");
			break;
		}
		ComputerMove(arr,ROW,CLO);
		Displayboard(arr, ROW, CLO);
		num = IsWin(arr, ROW, CLO);
		if (1 == num || 2 == num || 3 == num || 4 == num)
		{
			printf("����Ӯ��\n");
			break;
		}
		if (5 == num)
		{
			printf("ƽ��\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));//������������������
	do
	{
		int num = 0;
		menu();
		printf("��ѡ��");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();//������
			break;
		case 2:
			printf("�˳��ɹ�\a");
			break;
		default:
			printf("�����������������\a\n");
			rewind(stdin);
			break;
		}
		if (2 == num)
		{
			break;
		}
	} while (1);
	return 0;
}