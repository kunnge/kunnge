#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void BubbleSort();
void SelectionSort();
void BubbleSort() //ð������
{
	int len = 0; //�������
	int* p = NULL;
	printf("���������鳤��(������СΪ2)��\n");
	scanf("%d", &len);
	if (!(len > 1))
	{
		printf("�޷�¼��\a");
		return 0;
	}
	p = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("�������%d������:", i + 1);
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p[j] > p[j + 1])//���ݽ���
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
void SelectionSort() //ѡ������
{
	int len = 0; //�������
	int* p = NULL;
	printf("���������鳤��(������СΪ2)��\n");
	scanf("%d", &len);
	if (!(len > 1))
	{
		printf("�޷�¼��\a");
		return 0;
	}
	p = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		printf("�������%d������:", i + 1);
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < len -1; i++)
	{
		int min = p[i];
		for (int j = i + 1; j < len; j++)
		{
			if (p[i] > p[j]) //���ݽ���
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
	//BubbleSort();//ð������
	//SelectionSort();//ѡ������
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