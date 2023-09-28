#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initialize(char arr[ROWS][CLOS], int rows, int clos,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < clos; j++)
		{
			arr[i][j] = set;
		}
	}
}
void DisplayBoard(char arr[ROWS][CLOS], int row, int clo)
{
	printf("****扫雷 游戏****\n");
	for (int k = 1; k < clo+1; k++)
	{
		if (k == 1)
		{
			printf("  ");
		}
		printf("%d ", k);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= clo; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("****扫雷 游戏****\n");
}
void SetMine(char arr[ROWS][CLOS], int row, int clo)
{
	for (int i = 0; i < BOMB; i++)
	{
		int x = rand() % row + 1;//1~9
		int y = rand() % clo + 1;//1~9
		if (arr[x][y] == '1')
		{
			i--;
			continue;
		}
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
		}
	}
}
//判断雷的个数
int get_mine_bomb(char mine[ROWS][CLOS], int x, int y)
{
	int count = 0;
	for (int i = x-1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
//展开一片
void Unfold(char mine[ROWS][CLOS], char show[ROWS][CLOS],int x, int y,int* win)
{
		for (int i = x - 1; i <= x + 1; i++)//找到此坐标的周围坐标
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i > 0 && i <= ROW && j > 0 && j <= CLO && show[i][j] =='*')//坐标合法，且坐标之前未被展开
				{
					int count = get_mine_bomb(mine, i, j);
					if (count == 0)
					{
						if (show[i][j] != '0')
						{
							show[i][j] = '0';
							*win += 1;
							Unfold(mine, show, i, j, win);
						}
					}
					else
					{
						show[i][j] = count + '0';
						*win += 1;
					}
				}
			}
		}
}
void FindMine(char mine[ROWS][CLOS], char show[ROWS][CLOS], int row, int clo)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*clo-BOMB)
	{
		printf("请输入排查雷的坐标：");
		scanf("%d%d", &x, &y);
		if (show[x][y] !='*')
		{
			printf("该坐标已经排查过，不能重复排查\a\n");
		}
		else
		{	

			//坐标合法
			if (x > 0 && x <= row && y > 0 && y <= clo)
			{
				//坐标有雷
				if (mine[x][y] == '1')
				{
					printf("踩到雷了，游戏结束\a\n");
					DisplayBoard(mine, ROW, CLO);
					break;
				}
				else
				{
					int count = get_mine_bomb(mine, x, y);
					if (count == 0)
					{
						Unfold(mine, show, x, y,&win);//展开一片
					}
					else
					{
						for (int i = x - 1; i <= x + 1; i++)//找到此坐标的周围坐标
						{
							for (int j = y - 1; j <= y + 1; j++)
							{
								if ((i > 0 && i <= ROW && j > 0 && j <= CLO) && show[i][j] == '*'&& mine[i][j] =='0')//坐标合法
								{
									show[i][j] = get_mine_bomb(mine,i,j)+'0';//显示炸弹数
									win++;
								}
							}
						}
					}
					DisplayBoard(show, ROW, CLO);
				}

			}
			else
			{
				printf("请重新输入坐标\a\n");
			}
		}
	}
	if (win == row * clo - BOMB)
	{
		printf("恭喜，排雷成功\a\n");
	}
}