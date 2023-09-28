#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////顺序表的实现---静态分配
//#define MaxSize 10
//#define Elemtype int
//#include<assert.h>
//typedef struct
//{
//	Elemtype data[MaxSize];
//	int lenght;//顺序表的长度
//}SqList;
////初始化顺序表
//void InitList(SqList* L)
//{
//	for (int i = 0; i < MaxSize; i++)
//	{
//		L->data[i] = 0;
//	}
//	L->lenght = 0;
//}
////插入一个元素
//int InsertList(SqList* L, int location, int element)
//{
//	//特殊情况第一个元素
//	if (0 == L->lenght)
//	{
//		L->data[location - 1] = element;//将新元素放入第location的位置
//		L->lenght++;//表长加1
//		return 0;
//	}
//	//判断位置是否合法
//	if (location < 1 || location > L->lenght)
//	{
//		return 1;
//	}
//	//存储空间已满
//	if (L->lenght == MaxSize)
//	{
//		return 2;
//	}
//	for (int i = L->lenght; i > location-1; i--)
//	{
//		L->data[i] = L->data[i-1];//从最后一个元素开始往后移动，直到第location个元素后移
//	}
//	L->data[location-1] = element;//将新元素放入第location的位置
//	L->lenght++;//表长加1
//	return 0;
//}
////删除一个元素
//int DeleteList(SqList* L, int location, Elemtype* DeleteElement)
//{
//	//判断L是否为空
//	assert(L);
//	//判断location是否合法
//	if (location <= 0 || location > L->lenght)
//	{
//		return 1;
//	}
//	*DeleteElement = L->data[location - 1];
//	for (int i = location; i < L->lenght; i++)
//	{
//		L->data[location - 1] = L->data[location];//将location后面的元素往前移动
//	}
//	L->lenght--;
//	return 0;
//}
////按位查找
//Elemtype GetElem(SqList L, int location)
//{
//	//判断location是否合法
//	if (location > 0 && location <= L.lenght)
//	{
//		return L.data[location - 1];
//	}
//}
////按值查找
//int LocateElement(SqList L, int element)
//{
//	for (int i = 0; i < L.lenght; i++)
//	{
//		if (element == L.data[i])
//		{
//			return i + 1;//返回值的位置
//		}
//	}
//	return 0;
//}
////打印
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
//	SqList L;//创建一个顺序表
//	InitList(&L);//初始化顺序表
//	while (1)
//	{
//		printf("请输入插入的位置(-1退出)：");
//		scanf("%d", &location);
//		if (-1 == location)
//		{
//			break;
//		}
//		printf("请输入添加的数据：");
//		scanf("%d", &element);
//		judge = InsertList(&L, location, element);
//		if (1 == judge)
//		{
//			printf("位置错误\a\n");
//		}
//		else if (2 == judge)
//		{
//			printf("顺序表已经满了\a\n");
//		}
//		else
//		{
//			printf("添加成功\n");
//		}
//
//	}
//	PrintList(&L);
//
//	////按位查找
//	//while (1)
//	//{
//	//	printf("请输入需要按位查找的位置(-1退出)：\n");
//	//	scanf("%d", &location);
//	//	if (-1 == location)
//	//	{
//	//		break;
//	//	}
//	//	printf("按位查找的位置：%d\n", GetElem(L, location));
//	//}
//
//	////按值查找
//	//while (1)
//	//{
//	//	printf("请输入需要查找的值(-1退出)：");
//	//	scanf("%d", &element);
//	//	if (-1 == element)
//	//	{
//	//		break;
//	//	}
//	//	if (LocateElement(L, element))
//	//	{
//	//		printf("在顺序表的第%d个元素\n", element);
//	//	}
//	//	else
//	//	{
//	//		printf("顺序表中没有该元素\a\n");
//	//	}
//	//}
//	
//	//按位删除
//	//while (1)
//	//{
//	//	printf("请输入要删除的位置（-1退出）：");
//	//	scanf("%d", &location);
//	//	if (-1 == location)
//	//	{
//	//		break;
//	//	}
//	//	judge = DeleteList(&L, location, &delete_element);
//	//	if (1 == judge)
//	//	{
//	//		printf("无法删除\a\n");
//	//	}
//	//	else
//	//	{
//	//		printf("删除成功\n");
//	//		printf("被删除的元素是：%d\n", delete_element);
//	//	}
//	//}
//	//PrintList(&L);
//	return 0;
//}

//#include<stdlib.h>
//#define Elemtype int
//#define InitSize 10
////顺序表的实现---动态分配
//typedef struct
//{
//	Elemtype* data;//动态分配数组的指针
//	int MaxSize;//最大容量
//	int length;//长度
//}SqeList;
////初始化
//void InitList(SqeList* L)
//{
//	L->data = (Elemtype*)malloc(InitSize * sizeof(Elemtype));
//	L->length = 0;
//	L->MaxSize = InitSize;
//}
////动态增加数组的长度
//void IncreaseSize(SqeList* L, int length)
//{
//	////第一种
//	//int* p = L->data;
//	//L->data = (Elemtype*)malloc((L->MaxSize + length) * sizeof(Elemtype));
//	//for (int i = 0; i < L->length; i++)
//	//{
//	//	L->data[i] = p[i];
//	//}
//	//L->length += length;
//	//free(p);
//	////第二种
//	//L->data = (Elemtype*)realloc(L, length);
//	//L->length += length;
//}
//int main()
//{
//	int length;
//	SqeList L;//创建
//	InitList(&L);//初始化
//	printf("请输入需要增加的长度:");
//	scanf("%d", &length);
//	IncreaseSize(&L, length);
//	return 0;
//}

//单链表
#define ElemType int
#include<stdlib.h>
typedef struct LNode{
	ElemType data;//数据域
	struct LNode* next;//指针域
}LNode,*LinkList;
//初始化
int InitList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));//创建一个头结点
	if (!L)
	{
		return 1;
	}
	L->next = NULL;
	return 0;
}
//前插入操作
int InsertPriorNode(LNode* p, LNode* s)
{
	//判断是否为空指针
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
//后插操作在p结点之后插入元素E
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
//按位序插入
int InserList(LinkList L, int location, ElemType Element)
{
	//判断location是否合法
	if (location < 1 )
	{
		return 1;
	}
	LNode* p;
	p = L;//L指向头结点，头结点是第0结点（不存数据）
	int j = 0;//记录tmp指向的是第几个结点
	//找到j-1的结点
	while (p != NULL && j < location-1)
	{
		p = p->next;
		j++;
	}
	//后插操作在p结点之后插入元素E
	InsertNextNode(&p, Element);
}
//删除元素
int DeleteList(LinkList* L, int location, ElemType element)
{
	//判断location是否合法
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
	//p值不合法和第location-1个结点之后没有其他结点
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
//按位查找
LNode* GetElem(LinkList L, ElemType location)
{
	//判断location是否合法
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
//按值查找
LNode* LocateElem(LinkList L, ElemType Element)
{
	//判断链表是否为空
	if (!L)
	{
		return 1;
	}
	LNode* p = L->next;
	while (p != NULL && Element != p->data)//在最后NULL指针停下
	{
		p = p->next;
	}
	return p;
}
//求表的长度
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
//打印
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
	//	printf("请输入需要后插入的数据(-1退出)：\n");
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
	//	printf("请输入按位插入的位置(-1退出)：");
	//	scanf("%d", &location);
	//	if (-1 == location)
	//	{
	//		break;
	//	}
	//	printf("请输入按位插入的元素：");
	//	scanf("%d", &Element);
	//	InserList(&L, location, Element);
	//}
	//PrintLinkList(&L);
	//while (1)
	//{
	//	printf("请输入需要删除的位置(-1退出)：");
	//	scanf("%d", &location);
	//	if (-1 == location)
	//	{
	//		break;
	//	}
	//	DeleteList(&L, location, &DeleteElement);
	//	printf("元素%d已被删除\n", DeleteElement);
	//}
	//PrintLinkList(L);
	free(L);
	return 0;
}

//顺序栈
//#define ElemType int
//#define MaxSize 10//定义顺序栈中的元素个数
//typedef struct
//{
//    ElemType data[MaxSize];//静态数组存放栈中元素
//    int top;//栈顶元素
//}SqStack;
////初始化栈
//void InitStack(SqStack* Stack1)
//{
//    Stack1->top = -1;//初始化栈顶指针
//}
////判断栈空
//int StackEmpty(SqStack* Stack1)
//{
//    if (-1 == Stack1->top)
//    {
//        return 1;//栈空
//    }
//    else
//    {
//        return 0;//栈不空
//    }
//}
////在顺序栈中插入一个新元素
//int Push_on(SqStack* Stack1,ElemType element)
//{
//    if (Stack1->top == MaxSize-1)
//    {
//        return 1;
//    }
//    Stack1->data[++Stack1->top] = element;
//    return 0;
//}
////出栈(把一个元素从栈中拿出)
//int Pop(SqStack* Stack1, ElemType* element)
//{
//    //判空
//    if (-1 == Stack1->top)
//    {
//        printf("顺序栈已经为空栈\a\n");
//    }
//    element = Stack1->data[Stack1->top--];
//}
////读栈
//int GetTop(SqStack* Stack1, int* element)
//{
//    //判空
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
//    SqStack Stack1;//创建一个顺序栈
//    InitStack(&Stack1);//初始化顺序栈
//    //添加元素进栈
//    printf("请输入数据：");
//    scanf("%d", &element);
//    ret = Push_on(&Stack1,element);
//    if (1 == ret)
//    {
//        printf("顺讯栈已经满了\a\n");
//    }
//    ret = GetTop(&Stack1, &element);
//    if (1 == ret)
//    {
//        printf("顺序栈为空栈,无法读栈\a\n");
//    }
//    return(0);
//}

//链栈
//#define MaxSize 10
//#define ElemType int
//typedef struct
//{
//	ElemType data[MaxSize];
//	int top1;//1号栈顶指针
//	int top0;//0号栈顶指针
//}ShareStack;
////初始化栈
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
