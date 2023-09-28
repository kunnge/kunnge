#define _CRT_SECURE_NO_WARNINGS 1//Ctrl+k再按Ctrl+f可以快速对齐代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Library
{
	char title[128];
	char author[40];
	float price;
	int length;
};
//单链表结构
typedef struct Node {
	struct Library data;//数据域
	struct Node* next;//指针域
};
//单链表初始化
struct Node* CreatLinkList()
{
	struct Node* ListNode = (struct Node*)malloc(sizeof(struct Node));//malloc用到了<stdlib.h>头文件
	if (ListNode == NULL)
	{
		printf("内存分配失败！\a\n");
		return;
	}
	else
	{
		ListNode->data.price = 0;
		ListNode->data.length = 0;
		ListNode->next = NULL;
		return ListNode;
	}
}
//头插法(单链表为倒序)
void Insert_HeadNode(struct Node* LinkList)
{
	struct Node* NewNode;
	struct Library data;
	printf("请输入第%d本书的书名(输入-1停止录入)：", LinkList->data.length + 1);
	scanf("%s", &data.title);
	if (!strcmp(data.title, "-1"))
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}
	printf("请输入作者(输入-1停止录入)：");
	scanf("%s", &data.author);
	if (!strcmp(data.author, "-1"))
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}
	printf("请输入价格(输入-1停止录入)：");
	scanf("%f", &data.price);
	if (data.price <= 0)
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}

	while (data.title != -1 || data.author != -1 || data.price != -1)
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		//strcpy(NewNode->data.title, data.title);
		//strcpy(NewNode->data.author, data.author);
		//NewNode->data.price = data.price;
		NewNode->data = data;
		NewNode->next = LinkList->next;
		LinkList->next = NewNode;
		LinkList->data.length++;
		printf("\n\n请输入第%d本书的书名(输入-1停止录入)：", LinkList->data.length + 1);
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}
		printf("请输入作者(输入-1停止录入)：");
		scanf("%s", &data.author);
		if (!strcmp(data.author, "-1"))
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}
		printf("请输入价格(输入-1停止录入)：");
		scanf("%f", &data.price);
		if (data.price <= 0)
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}
	}
}
//尾插法(单链表为顺序)
void TailInsertLinkList(struct Node* LinkList)
{
	struct Node* NewNode;
	struct Node* TailNode = LinkList;//指向最后的一个结点
	struct Library data;
	while (TailNode->next != NULL)//定位到最后一个结点
	{
		TailNode = TailNode->next;
	}
	printf("请输入第%d本书的书名(输入-1停止录入)：",LinkList->data.length+1);
	scanf("%s", &data.title);
	if (!strcmp(data.title, "-1"))
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}
	printf("请输入作者(输入-1停止录入)：");
	scanf("%s", &data.author);
	if (!strcmp(data.author, "-1"))
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}
	printf("请输入价格(输入-1停止录入)：");
	scanf("%f", &data.price);
	if (data.price <= 0)
	{
		printf("没有录入书籍！\a\n");
		return 0;
	}
	while (data.title != -1 || data.author != -1 || data.price != -1)
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		NewNode->next = NULL;
		TailNode->next = NewNode;
		NewNode->data = data;
		TailNode = NewNode;
		LinkList->data.length++;
		printf("\n\n请输入第%d本书的书名(输入-1停止录入)：", LinkList->data.length + 1);
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}
		printf("请输入作者(输入-1停止录入)：");
		scanf("%s", &data.author);
		if (!strcmp(data.author, "-1"))
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}
		printf("请输入价格(输入-1停止录入)：");
		scanf("%f", &data.price);
		if (data.price <= 0)
		{
			printf("已录入%d本书\n", LinkList->data.length);
			return LinkList;
		}

	}
}
//按位删除
void DeleteNode(struct Node* LinkList, struct Library DeletedData)
{
	struct Node* DeleteNode_Front = LinkList;
	struct Node* DeleteNode = LinkList->next;
	while (strcmp(DeleteNode->data.title, DeletedData.title))//寻找删除数据的位置
	{
		DeleteNode_Front = DeleteNode;
		DeleteNode = DeleteNode->next;
		if (DeleteNode == NULL)
		{
			printf("图书馆为空，无法删除的书籍!\a\n");
			return;
		}
	}
	printf("已删除:%s\n", DeletedData.title);
	DeleteNode_Front->next = DeleteNode->next;
	free(DeleteNode);
	LinkList->data.length--;
}
//按位连续删除
void ContinueDeleteNode(struct Node* LinkList)
{
	struct Library DeletedData;
	while (1)
	{
		printf("请输入需要删除的书名(输入-1停止删除)：");
		scanf("%s", &DeletedData.title);
		if (!strcmp(DeletedData.title, "-1"))
		{
			printf("删除结束\n");
			return;
		}
		DeleteNode(LinkList, DeletedData);
	}
}
//销毁单链表
void DestroyLinkList(struct Node* LinkList)
{
	while (LinkList->next != NULL)
	{
		DeleteNode(LinkList, LinkList->next->data);
	}
	free(LinkList);
	printf("图书馆的数据已经销毁\n");
	return 0;
}
//按位查找
void GetData(struct Node* LinkList)
{
	while (1)
	{
		int Location;
		printf("请输入查找的第几本书(输入-1停止查找)：");
		scanf("%d", &Location);
		if (Location == -1)
		{
			printf("查找结束\n");
			return 0;
		}
		if (Location < 1 || Location >LinkList->data.length)
		{
			printf("该位置在图书馆里无法找到！\a\n");
		}
		else
		{
			struct Node* GetNode = LinkList;
			for (int i = 0; i < Location; i++)
			{
				GetNode = GetNode->next;
			}
			printf("书名：%s\t作者：%s\t价格：%.2f元\t\n", GetNode->data.title, GetNode->data.author, GetNode->data.price);
		}
	}
}
//按位查找（2）无输出内容
struct Node* GetData2(struct Node* LinkList, int Location)
{
	if (Location == 0)
	{
		return LinkList;
	}
	if (Location < 1 || Location >LinkList->data.length)
	{
		printf("该位置在单链表里无法找到！\n");
		return NULL;
	}
	struct Node* GetNode = LinkList;
	for (int i = 0; i < Location; i++)
	{
		GetNode = GetNode->next;
	}
	return GetNode;
}
//打印图书馆的每一本书
void PrintList(struct Node* LinkList)
{
	struct Node* pmove = LinkList;
	int count = 0;
	if (pmove->next == NULL)
	{
		printf("图书馆中没有任何书籍\a\n");
		return 0;
	}
	while (pmove->next != NULL)
	{
		count++;
		pmove = pmove->next;
		printf("第%d本书名：%s\t作者：%s\t价格：%.2f元\t\n", count, pmove->data.title, pmove->data.author, pmove->data.price);
	}
	printf("\n");
}

//按位插入(在两个结点中间插入)
void LocalInsertLinkList(struct Node* LinkList)
{
	while (1)
	{
		int Location;
		struct Library data;
		printf("请输入插入第几本的位置(输入-1停止插入)：\n");
		scanf("%d", &Location);
		if (Location == -1)
		{
			printf("插入结束\n");
			return 0;
		}
		if ((Location - 1) == 0)
		{
			printf("该位置在图书馆里不存在!\a自动插入在第1本书的前面\n");
		}
		if (Location < 1 || Location >(LinkList->data.length + 1))
		{
			printf("错误，在图书馆中无法插入！\a\n");
			return 0;
		}
		else
		{
			printf("请输入插入书籍的书名(输入-1停止录入)：");
			scanf("%s", &data.title);
			if (!strcmp(data.title, "-1"))
			{
				printf("插入结束\n");
				return 0;
			}
			printf("请输入作者(输入-1停止录入)：");
			scanf("%s", &data.author);
			if (!strcmp(data.author, "-1"))
			{
				printf("插入结束\n");
				return 0;
			}
			printf("请输入价格(输入-1停止录入)：");
			scanf("%f", &data.price);
			if (data.price <= 0)
			{
				printf("插入结束\n");
				return 0;
			}
			struct Node* pNode = GetData2(LinkList, Location - 1);
			struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
			NewNode->data = data;
			NewNode->next = pNode->next;
			pNode->next = NewNode;
			LinkList->data.length++;
		}
	}
}
//按值查找
void LocateData(struct Node* LinkList)
{
	while (1)
	{
		struct Node* Locatedata = LinkList;
		struct Library data;
		printf("请输入需要查找的书名(输入-1停止查找):");
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("查找结束\n");
			return 0;
		}
		while (Locatedata->next != NULL)
		{
			Locatedata = Locatedata->next;
			if (!strcmp(Locatedata->data.title, data.title))
			{
				printf("书籍的书名：%s\t作者：%s\t价格：%.2f元\t\n", Locatedata->data.title, Locatedata->data.author, Locatedata->data.price);
				goto tiaodian;
			}
		}
		printf("图书馆找不到该数据\a\n");
		return 0;
	tiaodian:;
	}
}
int main(void)
{
	struct Node* LinkList = CreatLinkList();
	while (1)
	{
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		printf("欢迎来到坤坤图书馆^_^\n");
		printf("请选择以下操作:\n1\t(插入图书)\n2\t(查找图书)\n3\t(删除图书)\n4\t(打印所有图书)\n5\t(销毁图书馆所有数据并退出程序)\n");
		scanf("%d", &num1);
		switch (num1)
		{
		case 1: //插入图书
			printf("请选择插入图书的方法：\n1\t(最前面插入)\n2\t(最后面插入)\n3\t(在中间插入)\n");
			scanf("%d", &num2);
			switch (num2)
			{
			case 1: Insert_HeadNode(LinkList);
				break;
			case 2: TailInsertLinkList(LinkList);
				break;
			case 3: LocalInsertLinkList(LinkList);
				break;
			default: printf("输入错误！请输入正确的数字！\n");
				break;
			}
			break;
		case 2: //查找图书
			printf("请选择查找图书的方法：\n1\t(书名)\n2\t(次序(第几本书))\n");
			scanf("%d", &num3);
			switch (num3)
			{
			case 1: LocateData(LinkList);
				break;
			case 2: GetData(LinkList);
				break;
			default: printf("输入错误！请输入正确的数字！\n");
				break;
			}
			break;
		case 3: //删除图书
			ContinueDeleteNode(LinkList);
			break;
		case 4://打印所有图书
			PrintList(LinkList);
			break;
		case 5: //删除图书馆所有数据并退出程序
			DestroyLinkList(LinkList);
			printf("拜拜，欢迎下次光临坤坤图书馆^_^\n");
			return 0;
		default: printf("输入错误！请输入正确的数字！\a\n\n");
			rewind(stdin);
			break;
		}
	}
}
