#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//��ʼ��������
void InitList(LinkList L)
{

	L->data = 0;
	L->next = NULL;
}
//β�巨
int InserList(LinkList L, int location, ElemType Element)
{
	//�ж�location�Ƿ�Ϸ�
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
//��λ��ɾ��
void DeleteList(LinkList L, int location, ElemType* e)
{
	//����Ϸ�
	if (location < 1)
	{
		return 1;
	}
	//�ǿձ�
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
//ɾ��ָ���ڵ�
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
		printf("���������ݵ�λ�ã�-1�˳�����");
		scanf("%d", &location);
		if (-1 == location)
		{
			break;
		}
		printf("���������ݣ�");
		scanf("%d", &Element);
		InserList(&L, location, Element);
	}
	PrintList(&L);
	printf("dfd\n");
	DeleteList(&L, 1, Element);
	printf("%dpp", Element);
	return 0;
}