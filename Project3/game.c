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
	printf("****ɨ�� ��Ϸ****\n");
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
	printf("****ɨ�� ��Ϸ****\n");
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
//�ж��׵ĸ���
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
//չ��һƬ
void Unfold(char mine[ROWS][CLOS], char show[ROWS][CLOS],int x, int y,int* win)
{
		for (int i = x - 1; i <= x + 1; i++)//�ҵ����������Χ����
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i > 0 && i <= ROW && j > 0 && j <= CLO && show[i][j] =='*')//����Ϸ���������֮ǰδ��չ��
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
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		if (show[x][y] !='*')
		{
			printf("�������Ѿ��Ų���������ظ��Ų�\a\n");
		}
		else
		{	

			//����Ϸ�
			if (x > 0 && x <= row && y > 0 && y <= clo)
			{
				//��������
				if (mine[x][y] == '1')
				{
					printf("�ȵ����ˣ���Ϸ����\a\n");
					DisplayBoard(mine, ROW, CLO);
					break;
				}
				else
				{
					int count = get_mine_bomb(mine, x, y);
					if (count == 0)
					{
						Unfold(mine, show, x, y,&win);//չ��һƬ
					}
					else
					{
						for (int i = x - 1; i <= x + 1; i++)//�ҵ����������Χ����
						{
							for (int j = y - 1; j <= y + 1; j++)
							{
								if ((i > 0 && i <= ROW && j > 0 && j <= CLO) && show[i][j] == '*'&& mine[i][j] =='0')//����Ϸ�
								{
									show[i][j] = get_mine_bomb(mine,i,j)+'0';//��ʾը����
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
				printf("��������������\a\n");
			}
		}
	}
	if (win == row * clo - BOMB)
	{
		printf("��ϲ�����׳ɹ�\a\n");
	}
}