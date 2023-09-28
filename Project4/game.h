#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3
#define CLO 3
//初始化棋盘
void InitBoard(char arr[ROW][CLO], int row, int clo);
//打印棋盘
void Displayboard(char arr[ROW][CLO], int row, int clo);
//玩家下棋
void PlayerMove(char arr[ROW][CLO], int row, int clo);
//电脑下棋(找空位随机下)
void ComputerMove(char arr[ROW][CLO], int row, int clo);
//判断输赢 返回 1行赢 2列赢 3左对角线赢 4右对角线赢 5平局(1)结束 6平局(2)继续
int IsWin(char arr[ROW][CLO], int row, int clo);
//平局
int IsFull(char arr[ROW][CLO], int row, int clo);