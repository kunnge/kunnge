#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char arr[ROW][CLO], int row, int clo)//��ʼ������
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < clo; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void Displayboard(char arr[ROW][CLO], int row, int clo)//��ӡ����
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
void PlayerMove(char arr[ROW][CLO], int row, int clo)//�������
{
	int x = 0;
	int y = 0;
	printf("�������\n");
	printf("���������꣺");
	scanf("%d %d", &x, &y);
	while (1)
	{	
		if (x > 0 && x <= 3 && y > 0 && y <= 3)//�ж������Ƿ����
		{
			if (arr[x-1][y-1] == ' ')//�ж������Ƿ�ռ��
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("������ռ��\n");
				rewind(stdin);
			}
		}
		else
		{
			printf("������Ч\a\n");
			rewind(stdin);
		}
	}
}
void ComputerMove(char arr[ROW][CLO], int row, int clo)//��������
{
	printf("���ڵȴ���������\n");
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
	Sleep(2000);//������
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
//�ж���Ӯ
int IsWin(char arr[ROW][CLO], int row, int clo)
{
	//��Ӯ
	for (int i = 0; i < ROW; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return 1;
		}
	}
	//��Ӯ
	for (int j = 0; j < CLO; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != ' ')
		{
			return 2;
		}
	}
	//��Խ���Ӯ
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
	{
		return 3;
	}
	//�ҶԽ���Ӯ
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] !=' ')
	{
		return 4;
	}
	//ƽ��
	if (IsFull(arr, row, clo))
	{
		return 5;//ƽ����
	}
		return 6;//����
}