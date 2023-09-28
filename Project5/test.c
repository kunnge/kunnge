#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	//输出行数
	scanf("%d", &num);
	//创建动态二维数组
	//有num行
	int **nump = (int**)malloc(num*sizeof(int*));
	for (int i = 0; i < num; i++)
	{
		//有num列
		nump[i] = (int*)malloc(num * sizeof(int));
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			nump[i][j] = 0;
		}
	}
	//处理数据
	for (int i = 0; i < num; i++)
	{
		//处理每行的数据
		for (int j = 0; j <= i; j++)
		{
			//数据
			if ((j == 0)||(i == j))
			{
				nump[i][j] = 1;
			}
			if (j < i && j > 0)
			{
				nump[i][j] = nump[i - 1][j - 1] + nump[i-1][j];
			}
		}

	}
	//输出数据
	for (int i = 0; i < num; i++)
	{
		//打印左边空格
		for (int k = 0; k < (num - (i + 1)); k++)
		{
			printf(" ");
		}
		//打印中间数据
		for (int j = 0; j < num; j++)
		{
			if (nump[i][j]!=0)
			{
				printf("% 3d", nump[i][j]);
			}
		}
		printf("\n");
	}
	//释放内存空间
	for (int i = 0; i < num; i++)
	{
		free(nump[i]);
	}
	free(nump);
	return 0;
}