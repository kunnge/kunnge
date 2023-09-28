#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
void menu()
{
	printf("*************************\n");
	printf("********1.开始***********\n");
	printf("********2.退出***********\n");
	printf("*************************\n");
}
void game()//三子棋
{
	char arr[ROW][CLO] = {0};
	//初始化棋盘
	InitBoard(arr, ROW, CLO);
	Displayboard(arr,ROW,CLO);
	//开始下棋
	while (1)
	{
		int num = 0;
		PlayerMove(arr,ROW,CLO);
		Displayboard(arr, ROW, CLO);
		num = IsWin(arr, ROW, CLO);
		if (1 == num || 2 == num || 3 == num || 4 == num )
		{
			printf("玩家赢了\n");
			break;
		}
		if (5 == num)
		{
			printf("平局\n");
			break;
		}
		ComputerMove(arr,ROW,CLO);
		Displayboard(arr, ROW, CLO);
		num = IsWin(arr, ROW, CLO);
		if (1 == num || 2 == num || 3 == num || 4 == num)
		{
			printf("电脑赢了\n");
			break;
		}
		if (5 == num)
		{
			printf("平局\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	do
	{
		int num = 0;
		menu();
		printf("请选择：");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();//三子棋
			break;
		case 2:
			printf("退出成功\a");
			break;
		default:
			printf("输入错误请重新输入\a\n");
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