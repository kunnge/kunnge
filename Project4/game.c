#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char arr[ROW][CLO], int row, int clo)//初始化棋盘
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < clo; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void Displayboard(char arr[ROW][CLO], int row, int clo)//打印棋盘
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < clo; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < clo-1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (int k = 0; k < clo; k++)
		{
			printf("---");
			if (k < clo - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}
void PlayerMove(char arr[ROW][CLO], int row, int clo)//玩家下棋
{
	int x = 0;
	int y = 0;
	printf("玩家下棋\n");
	printf("请输入坐标：");
	scanf("%d %d", &x, &y);
	while (1)
	{	
		if (x > 0 && x <= 3 && y > 0 && y <= 3)//判断坐标是否符合
		{
			if (arr[x-1][y-1] == ' ')//判断坐标是否占用
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已占用\n");
				rewind(stdin);
			}
		}
		else
		{
			printf("坐标无效\a\n");
			rewind(stdin);
		}
	}
}
void ComputerMove(char arr[ROW][CLO], int row, int clo)//电脑下棋
{
	printf("正在等待电脑下棋\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % clo;//0~2
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
	Sleep(2000);//过两秒
}
int IsFull(char arr[ROW][CLO], int row, int clo)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < CLO; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//判断输赢
int IsWin(char arr[ROW][CLO], int row, int clo)
{
	//行赢
	for (int i = 0; i < ROW; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return 1;
		}
	}
	//列赢
	for (int j = 0; j < CLO; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return 2;
		}
	}
	//左对角线赢
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	{
		return 3;
	}
	//右对角线赢
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] !=' ')
	{
		return 4;
	}
	//平局
	if (IsFull(arr, row, clo))
	{
		return 5;//平局了
	}
		return 6;//继续
}