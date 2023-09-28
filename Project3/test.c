#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("************************\n");
	printf("*******1开始游戏********\n");
	printf("*******2退出游戏********\n");
	printf("************************\n");
	printf("************************\n");
}
//扫雷游戏
void game()
{
	char mine[ROWS][CLOS] = {0};//存放布置雷的信息
	char show[ROWS][CLOS] = {0};//存放排除雷的信息
	//初始化
	//mine初始化全为'0'
	Initialize(mine, ROWS, CLOS, '0');
	//show初始化全为'*'
	Initialize(show, ROWS, CLOS, '*');
	//打印
	//DisplayBoard(mine, ROW, CLO);
	//DisplayBoard(show,ROW,CLO);
	//设置雷
	SetMine(mine, ROW, CLO);
	//DisplayBoard(mine, ROW, CLO);
	DisplayBoard(show, ROW, CLO);
	//判断雷
	FindMine(mine, show, ROW, CLO);
}
int main()
{
	do
	{
		int input = 0;
		//设置随机值的生成起点
		srand((unsigned int)time(NULL));
		menu();
		printf("请选择：->");
		scanf("%d",&input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 2 :
			return 0;
		default:
			printf("输入错误,请重新输入\a\n");
			break;
		}
	} while (1);
	return 0;
}