#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////˳����ʵ��---��̬����
//#define MaxSize 10
//#define Elemtype int
//#include<assert.h>
//typedef struct
//{
//	Elemtype data[MaxSize];
//	int lenght;//˳���ĳ���
//}SqList;
////��ʼ��˳���
//void InitList(SqList* L)
//{
//	for (int i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;
//	}
//	L->lenght = 0;
//}
////����һ��Ԫ��
//int InsertList(SqList* L, int location, int element)
//{
//	//���������һ��Ԫ��
//	if (0 == L->lenght)
//	{
//		L->data[location - 1] = element;//����Ԫ�ط����location��λ��
//		L->lenght++;//����1
//		return 0;
//	}
//	//�ж�λ���Ƿ�Ϸ�
//	if (location < 1 || location > L->lenght)
//	{
//		return 1;
//	}
//	//�洢�ռ�����
//	if (L->lenght == MaxSize)
//	{
//		return 2;
//	}
//	for (int i = L->lenght; i > location-1; i--)
//	{
//		L->data[i] = L->data[i-1];//�����һ��Ԫ�ؿ�ʼ�����ƶ���ֱ����location��Ԫ�غ���
//	}
//	L->data[location-1] = element;//����Ԫ�ط����location��λ��
//	L->lenght++;//����1
//	return 0;
//}
////ɾ��һ��Ԫ��
//int DeleteList(SqList* L, int location, Elemtype* DeleteElement)
//{
//	//�ж�L�Ƿ�Ϊ��
//	assert(L);
//	//�ж�location�Ƿ�Ϸ�
//	if (location <= 0 || location > L->lenght)
//	{
//		return 1;
//	}
//	*DeleteElement = L->data[location - 1];
//	for (int i = location; i < L->lenght; i++)
//	{
//		L->data[location - 1] = L->data[location];//��location�����Ԫ����ǰ�ƶ�
//	}
//	L->lenght--;
//	return 0;
//}
////��λ����
//Elemtype GetElem(SqList L, int location)
//{
//	//�ж�location�Ƿ�Ϸ�
//	if (location > 0 && location <= L.lenght)
//	{
//		return L.data[location - 1];
//	}
//}
////��ֵ����
//int LocateElement(SqList L, int element)
//{
//	for (int i = 0; i < L.lenght; i++)
//	{
//		if (element == L.data[i])
//		{
//			return i + 1;//����ֵ��λ��
//		}
//	}
//	return 0;
//}
////��ӡ
//void PrintList(SqList* L)
//{
//	for (int i = 0; i < L->lenght; i++)
//	{
//		printf("%d\t", L->data[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	Elemtype element, location, judge,delete_element;
//	SqList L;//����һ��˳���
//	InitList(&L);//��ʼ��˳���
//	while (1)
//	{
//		printf("����������λ��(-1�˳�)��");
//		scanf("%d", &location);
//		if (-1 == location)
//		{
//			break;
//		}
//		printf("��������ӵ����ݣ�");
//		scanf("%d", &element);
//		judge = InsertList(&L, location, element);
//		if (1 == judge)
//		{
//			printf("λ�ô���\a\n");
//		}
//		else if (2 == judge)
//		{
//			printf("˳����Ѿ�����\a\n");
//		}
//		else
//		{
//			printf("��ӳɹ�\n");
//		}
//
//	}
//	PrintList(&L);
//
//	////��λ����
//	//while (1)
//	//{
//	//	printf("��������Ҫ��λ���ҵ�λ��(-1�˳�)��\n");
//	//	scanf("%d", &location);
//	//	if (-1 == location)
//	//	{
//	//		break;
//	//	}
//	//	printf("��λ���ҵ�λ�ã�%d\n", GetElem(L, location));
//	//}
//
//	////��ֵ����
//	//while (1)
//	//{
//	//	printf("��������Ҫ���ҵ�ֵ(-1�˳�)��");
//	//	scanf("%d", &element);
//	//	if (-1 == element)
//	//	{
//	//		break;
//	//	}
//	//	if (LocateElement(L, element))
//	//	{
//	//		printf("��˳���ĵ�%d��Ԫ��\n", element);
//	//	}
//	//	else
//	//	{
//	//		printf("˳�����û�и�Ԫ��\a\n");
//	//	}
//	//}
//	
//	//��λɾ��
//	//while (1)
//	//{
//	//	printf("������Ҫɾ����λ�ã�-1�˳�����");
//	//	scanf("%d", &location);
//	//	if (-1 == location)
//	//	{
//	//		break;
//	//	}
//	//	judge = DeleteList(&L, location, &delete_element);
//	//	if (1 == judge)
//	//	{
//	//		printf("�޷�ɾ��\a\n");
//	//	}
//	//	else
//	//	{
//	//		printf("ɾ���ɹ�\n");
//	//		printf("��ɾ����Ԫ���ǣ�%d\n", delete_element);
//	//	}
//	//}
//	//PrintList(&L);
//	return 0;
//}

//#include<stdlib.h>
//#define Elemtype int
//#define InitSize 10
////˳����ʵ��---��̬����
//typedef struct
//{
//	Elemtype* data;//��̬���������ָ��
//	int MaxSize;//�������
//	int length;//����
//}SqeList;
////��ʼ��
//void InitList(SqeList* L)
//{
//	L->data = (Elemtype*)malloc(InitSize * sizeof(Elemtype));
//	L->length = 0;
//	L->MaxSize = InitSize;
//}
////��̬��������ĳ���
//void IncreaseSize(SqeList* L, int length)
//{
//	////��һ��
//	//int* p = L->data;
//	//L->data = (Elemtype*)malloc((L->MaxSize + length) * sizeof(Elemtype));
//	//for (int i = 0; i < L->length; i++)
//	//{
//	//	L->data[i] = p[i];
//	//}
//	//L->length += length;
//	//free(p);
//	////�ڶ���
//	//L->data = (Elemtype*)realloc(L, length);
//	//L->length += length;
//}
//int main()
//{
//	int length;
//	SqeList L;//����
//	InitList(&L);//��ʼ��
//	printf("��������Ҫ���ӵĳ���:");
//	scanf("%d", &length);
//	IncreaseSize(&L, length);
//	return 0;
//}

//������
#define ElemType int
#include<stdlib.h>
typedef struct LNode{
	ElemType data;//������
	struct LNode* next;//ָ����
}LNode,*LinkList;
//��ʼ��
int InitList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	if (!L)
	{
		return 1;
	}
	L->next = NULL;
	return 0;
}
//ǰ�������
int InsertPriorNode(LNode* p, LNode* s)
{
	//�ж��Ƿ�Ϊ��ָ��
	if (p == NULL || s == NULL)
	{
		return 1;
	}
	s->next = p->next;
	p->next = s;
	ElemType tmp = p->data;
	p->data = s->data;
	s->data = tmp;
	return 0;
}
//��������p���֮�����Ԫ��E
int InsertNextNode(LNode* p, ElemType e)
{
	if (p == NULL)
	{
		return 1;
	}
	LNode* tmp = (LNode*)malloc(sizeof(LNode));
	if (tmp == NULL)
	{
		return 2;
	}
	tmp->data = e;
	tmp->next = p->next;
	p->next = tmp;
	return 0;
}
//��λ�����
int InserList(LinkList L, int location, ElemType Element)
{
	//�ж�location�Ƿ�Ϸ�
	if (location < 1 )
	{
		return 1;
	}
	LNode* p;
	p = L;//Lָ��ͷ��㣬ͷ����ǵ�0��㣨�������ݣ�
	int j = 0;//��¼tmpָ����ǵڼ������
	//�ҵ�j-1�Ľ��
	while (p != NULL && j < location-1)
	{
		p = p->next;
		j++;
	}
	//��������p���֮�����Ԫ��E
	InsertNextNode(&p, Element);
}
//ɾ��Ԫ��
int DeleteList(LinkList* L, int location, ElemType element)
{
	//�ж�location�Ƿ�Ϸ�
	if (location < 1)
	{
		return 1;
	}
	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < location-1)
	{
		p = p->next;
		j++;
	}
	//pֵ���Ϸ��͵�location-1�����֮��û���������
	if (p == NULL|| p->next ==NULL)
	{
		return 2;
	}
	LNode* q = p->next;
	element = q->data;
	p->next = q->next;
	free(q);
	return 0;
}
//��λ����
LNode* GetElem(LinkList L, ElemType location)
{
	//�ж�location�Ƿ�Ϸ�
	if (location < 0)
	{
		return 1;
	}
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < location)
	{
		p = p->next;
		j++;
	}
	return p;
}
//��ֵ����
LNode* LocateElem(LinkList L, ElemType Element)
{
	//�ж������Ƿ�Ϊ��
	if (!L)
	{
		return 1;
	}
	LNode* p = L->next;
	while (p != NULL && Element != p->data)//�����NULLָ��ͣ��
	{
		p = p->next;
	}
	return p;
}
//���ĳ���
int GetLength(LinkList L)
{
	LNode* p = L;
	int length = 0;
	while (p->next !=NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}
//��ӡ
void PrintLinkList(LinkList L)
{
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d\t", p->data);
	}
}
int main()
{
	int location;
	ElemType DeleteElement;
	ElemType Element;
	LinkList L;
	InitList(&L);
	//while (1)
	//{
	//	printf("��������Ҫ����������(-1�˳�)��\n");
	//	scanf("%d", &Element);
	//	if (-1 == Element)
	//	{
	//		break;
	//	}
	//	InsertNextNode(&L, Element);
	//}
	//PrintLinkList(&L);
	//while (1)
	//{
	//	printf("�����밴λ�����λ��(-1�˳�)��");
	//	scanf("%d", &location);
	//	if (-1 == location)
	//	{
	//		break;
	//	}
	//	printf("�����밴λ�����Ԫ�أ�");
	//	scanf("%d", &Element);
	//	InserList(&L, location, Element);
	//}
	//PrintLinkList(&L);
	//while (1)
	//{
	//	printf("��������Ҫɾ����λ��(-1�˳�)��");
	//	scanf("%d", &location);
	//	if (-1 == location)
	//	{
	//		break;
	//	}
	//	DeleteList(&L, location, &DeleteElement);
	//	printf("Ԫ��%d�ѱ�ɾ��\n", DeleteElement);
	//}
	//PrintLinkList(L);
	free(L);
	return 0;
}

//˳��ջ
//#define ElemType int
//#define MaxSize 10//����˳��ջ�е�Ԫ�ظ���
//typedef struct
//{
//    ElemType data[MaxSize];//��̬������ջ��Ԫ��
//    int top;//ջ��Ԫ��
//}SqStack;
////��ʼ��ջ
//void InitStack(SqStack* Stack1)
//{
//    Stack1->top = -1;//��ʼ��ջ��ָ��
//}
////�ж�ջ��
//int StackEmpty(SqStack* Stack1)
//{
//    if (-1 == Stack1->top)
//    {
//        return 1;//ջ��
//    }
//    else
//    {
//        return 0;//ջ����
//    }
//}
////��˳��ջ�в���һ����Ԫ��
//int Push_on(SqStack* Stack1,ElemType element)
//{
//    if (Stack1->top == MaxSize-1)
//    {
//        return 1;
//    }
//    Stack1->data[++Stack1->top] = element;
//    return 0;
//}
////��ջ(��һ��Ԫ�ش�ջ���ó�)
//int Pop(SqStack* Stack1, ElemType* element)
//{
//    //�п�
//    if (-1 == Stack1->top)
//    {
//        printf("˳��ջ�Ѿ�Ϊ��ջ\a\n");
//    }
//    element = Stack1->data[Stack1->top--];
//}
////��ջ
//int GetTop(SqStack* Stack1, int* element)
//{
//    //�п�
//    if (-1 == Stack1->top)
//    {
//        return 1;
//    }
//    element = &Stack1->data[Stack1->top];
//    return 0;
//}
//int main()
//{
//    int element;
//    int ret;
//    SqStack Stack1;//����һ��˳��ջ
//    InitStack(&Stack1);//��ʼ��˳��ջ
//    //���Ԫ�ؽ�ջ
//    printf("���������ݣ�");
//    scanf("%d", &element);
//    ret = Push_on(&Stack1,element);
//    if (1 == ret)
//    {
//        printf("˳Ѷջ�Ѿ�����\a\n");
//    }
//    ret = GetTop(&Stack1, &element);
//    if (1 == ret)
//    {
//        printf("˳��ջΪ��ջ,�޷���ջ\a\n");
//    }
//    return(0);
//}

//��ջ
//#define MaxSize 10
//#define ElemType int
//typedef struct
//{
//	ElemType data[MaxSize];
//	int top1;//1��ջ��ָ��
//	int top0;//0��ջ��ָ��
//}ShareStack;
////��ʼ��ջ
//void InitStack(ShareStack* Stack)
//{
//	Stack->top1 = MaxSize;
//	Stack->top0 = -1;
//}
//int main()
//{
//
//	return 0;
//}
