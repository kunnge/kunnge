#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//��ʼ��������
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
//β�巨
int InserList(LinkList L, int location,ElemType Element)
{
	//�ж�location�Ƿ�Ϸ�
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
	//�ų�p��ʼΪNULL
	if (p == NULL)
	{
		return 2;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//����������ݷ����ڴ�ռ�
	s->data = Element;
	s->next = p->next;
	p->next = s;
	return 0;
}
//β�巨����������
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
		r = s;//rָ���µ�β���
		scanf("%d", &input);
	}
	r->next = NULL;//������β����ÿ�
	return L;
}
//ͷ�巨����
//��ӡ 
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
		printf("��ʼ������\a\n");
	}
	while (1)
	{
		printf("���������ݵ�λ�ã�-1�˳�����");
		scanf("%d", &location);
		if (-1 == location)
		{
			break;
		}
		printf("���������ݣ�");
		scanf("%d", &Element);
		ret = InserList(L, location, Element);
		if (1 == ret)
		{
			printf("λ�ò��Ϸ�\a\n");
		}
		else if (2 == ret)
		{
			printf("������Ϊ�ձ�\a\n");
		}
	}
	PrintList(L);
	return 0;
}