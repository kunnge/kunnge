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
	Contact con;//创建一个通讯录
	InitContact(&con);//初始通讯录
	do
	{
		menu();
		printf("请选择->");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}