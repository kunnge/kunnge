#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("************************\n");
	printf("************************\n");
	printf("*******1��ʼ��Ϸ********\n");
	printf("*******2�˳���Ϸ********\n");
	printf("************************\n");
	printf("************************\n");
}
//ɨ����Ϸ
void game()
{
	char mine[ROWS][CLOS] = {0};//��Ų����׵���Ϣ
	char show[ROWS][CLOS] = {0};//����ų��׵���Ϣ
	//��ʼ��
	//mine��ʼ��ȫΪ'0'
	Initialize(mine, ROWS, CLOS, '0');
	//show��ʼ��ȫΪ'*'
	Initialize(show, ROWS, CLOS, '*');
	//��ӡ
	//DisplayBoard(mine, ROW, CLO);
	//DisplayBoard(show,ROW,CLO);
	//������
	SetMine(mine, ROW, CLO);
	//DisplayBoard(mine, ROW, CLO);
	DisplayBoard(show, ROW, CLO);
	//�ж���
	FindMine(mine, show, ROW, CLO);
}
int main()
{
	do
	{
		int input = 0;
		//�������ֵ���������
		srand((unsigned int)time(NULL));
		menu();
		printf("��ѡ��->");
		scanf("%d",&input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 2 :
			return 0;
		default:
			printf("�������,����������\a\n");
			break;
		}
	} while (1);
	return 0;
}