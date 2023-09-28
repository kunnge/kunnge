#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void BubbleSort();
void SelectionSort();
void BubbleSort() //冒泡排序
{
	int len = 0; //数组个数
	int* p = NULL;
	printf("请输入数组长度(长度最小为2)：\n");
	scanf("%d", &len);
	if (!(len > 1))
	{
		printf("无法录入\a");
		return 0;
	}
	p = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个数据:", i + 1);
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p[j] > p[j + 1])//数据交换
			{
				int temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
		for (int t = 0; t < len; t++)
		{
			printf("%d\t", p[t]);
		}
		printf("\n");
	}
	free(p);
}
void SelectionSort() //选择排序
{
	int len = 0; //数组个数
	int* p = NULL;
	printf("请输入数组长度(长度最小为2)：\n");
	scanf("%d", &len);
	if (!(len > 1))
	{
		printf("无法录入\a");
		return 0;
	}
	p = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("请输入第%d个数据:", i + 1);
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < len -1; i++)
	{
		int min = p[i];
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] > p[j]) //数据交换
			{
				int temp;
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		for (int t = 0; t < len; t++)
		{
			printf("%d\t", p[t]);
		}
		printf("\n");
	}
	free(p);
}
int main()
{
	//BubbleSort();//冒泡排序
	//SelectionSort();//选择排序
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}