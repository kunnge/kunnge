#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include<string.h>
void menu()
{
	printf("**************************************\n");
	printf("**********1.add       2.del   ********\n");
	printf("**********3.search    4.modify********\n");
	printf("**********5.show      6.sort  ********\n");
	printf("**********0.exit    ******************\n");
	printf("**************************************\n");
	printf("**************************************\n");
}
int main()
{
	int input = 0;
	Contact con;//����һ��ͨѶ¼
	InitContact(&con);//��ʼͨѶ¼
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}