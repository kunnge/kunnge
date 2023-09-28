#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define CLO 9
#define ROWS ROW+2
#define CLOS CLO+2
#define BOMB 10
void Initialize(char arr[ROWS][CLOS],int rows,int clos,char set);
void DisplayBoard(char arr[ROWS][CLOS], int row, int clo);
void SetMine(char arr[ROWS][CLOS], int row, int clo);
void FindMine(char mine[ROWS][CLOS], char show[ROWS][CLOS] ,int row,int clo);
int get_mine_bomb(char mine[ROWS][CLOS],int x,int y);
void Unfold(char mine[ROWS][CLOS], char show[ROWS][CLOS],int x, int y,int* win);