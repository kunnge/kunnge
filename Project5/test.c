#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	//�������
	scanf("%d", &num);
	//������̬��ά����
	//��num��
	int **nump = (int**)malloc(num*sizeof(int*));
	for (int i = 0; i < num; i++)
	{
		//��num��
		nump[i] = (int*)malloc(num * sizeof(int));
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			nump[i][j] = 0;
		}
	}
	//��������
	for (int i = 0; i < num; i++)
	{
		//����ÿ�е�����
		for (int j = 0; j <= i; j++)
		{
			//����
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
	//�������
	for (int i = 0; i < num; i++)
	{
		//��ӡ��߿ո�
		for (int k = 0; k < (num - (i + 1)); k++)
		{
			printf(" ");
		}
		//��ӡ�м�����
		for (int j = 0; j < num; j++)
		{
			if (nump[i][j]!=0)
			{
				printf("% 3d", nump[i][j]);
			}
		}
		printf("\n");
	}
	//�ͷ��ڴ�ռ�
	for (int i = 0; i < num; i++)
	{
		free(nump[i]);
	}
	free(nump);
	return 0;
}