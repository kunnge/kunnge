#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3
#define CLO 3
//��ʼ������
void InitBoard(char arr[ROW][CLO], int row, int clo);
//��ӡ����
void Displayboard(char arr[ROW][CLO], int row, int clo);
//�������
void PlayerMove(char arr[ROW][CLO], int row, int clo);
//��������(�ҿ�λ�����)
void ComputerMove(char arr[ROW][CLO], int row, int clo);
//�ж���Ӯ ���� 1��Ӯ 2��Ӯ 3��Խ���Ӯ 4�ҶԽ���Ӯ 5ƽ��(1)���� 6ƽ��(2)����
int IsWin(char arr[ROW][CLO], int row, int clo);
//ƽ��
int IsFull(char arr[ROW][CLO], int row, int clo);