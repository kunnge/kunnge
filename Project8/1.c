#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//初始化单链表
LinkList* InitList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return 1;
	}
	L->next = NULL;
	return L;
}
//尾插法
int InserList(LinkList L, int location,ElemType Element)
{
	//判断location是否合法
	if (location < 1)
	{
		return 1;
	}
	LNode* p = L;
	int j = 0;
	while (p->next !=NULL && j < location-1)
	{
		p = p->next;
		j++;
	}
	//排除p开始为NULL
	if (p == NULL)
	{
		return 2;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//给插入的数据分配内存空间
	s->data = Element;
	s->next = p->next;
	p->next = s;
	return 0;
}
//尾插法建立单链表
LinkList List_Taillsert(LinkList L)
{
	int input = 0;
	L = (LNode*)malloc(sizeof(LNode));
	LNode* s, * r = L;
	scanf("%d", &input);
	while (-1 != input)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = input;
		r->next = s;
		r = s;//r指向新的尾结点
		scanf("%d", &input);
	}
	r->next = NULL;//把最后的尾结点置空
	return L;
}
//头插法插入
//打印 
void PrintList(LinkList L)
{
	LinkList p = L;
	while (p->next != NULL)
	{
		p = p->next;
		if (!p)
		{
			break;
		}
		printf("%d\t", p->data);
	}
	printf("\n");
}
int main()
{
	int ret = 0;
	int location;
	ElemType Element;
	LinkList *L;
	L = InitList(L);
	if (1 == ret)
	{
		printf("初始化错误\a\n");
	}
	while (1)
	{
		printf("请输入数据的位置（-1退出）：");
		scanf("%d", &location);
		if (-1 == location)
		{
			break;
		}
		printf("请输入数据：");
		scanf("%d", &Element);
		ret = InserList(L, location, Element);
		if (1 == ret)
		{
			printf("位置不合法\a\n");
		}
		else if (2 == ret)
		{
			printf("单链表为空表\a\n");
		}
	}
	PrintList(L);
	return 0;
}