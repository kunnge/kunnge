#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//初始化单链表
void InitList(LinkList L)
{

	L->data = 0;
	L->next = NULL;
}
//尾插法
int InserList(LinkList L, int location, ElemType Element)
{
	//判断location是否合法
	if (location < 1)
	{
		return 1;
	}
	LNode* p = L;
	int j = 0;
	while (p->next != NULL && j < location - 1)
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
int InserPriorNode(LNode* p, ElemType e)
{
	if (!p)
	{
		return 1;
	}
	LNode* tmp = (LNode*)malloc(sizeof(LNode));
	if (!tmp)
	{
		return 2;
	}
	tmp->next = p->next;
	p->next = tmp;
	tmp->data = p->data;
	p->data = e;
	return 0;
}
//按位序删除
void DeleteList(LinkList L, int location, ElemType* e)
{
	//坐标合法
	if (location < 1)
	{
		return 1;
	}
	//非空表
	LNode* p = L;
	int j = 0;
	while (p!=NULL && j < location -1)
	{
		p = p->next;
		j++;
	}
	if (NULL == p)
	{
		return 2;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
}
//删除指定节点
void DeletNode(LNode* p)
{
	if (NULL == p)
	{
		return 1;
	}
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
}
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
	int location;
	ElemType Element;
	LinkList L;
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
	{
		return 1;
	}
	InitList(&L);
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
		InserList(&L, location, Element);
	}
	PrintList(&L);
	printf("dfd\n");
	DeleteList(&L, 1, Element);
	printf("%dpp", Element);
	return 0;
}