#define _CRT_SECURE_NO_WARNINGS 1//Ctrl+k�ٰ�Ctrl+f���Կ��ٶ������
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
//������ṹ
typedef struct Node {
	struct Library data;//������
	struct Node* next;//ָ����
};
//�������ʼ��
struct Node* CreatLinkList()
{
	struct Node* ListNode = (struct Node*)malloc(sizeof(struct Node));//malloc�õ���<stdlib.h>ͷ�ļ�
	if (ListNode == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\a\n");
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
//ͷ�巨(������Ϊ����)
void Insert_HeadNode(struct Node* LinkList)
{
	struct Node* NewNode;
	struct Library data;
	printf("�������%d���������(����-1ֹͣ¼��)��", LinkList->data.length + 1);
	scanf("%s", &data.title);
	if (!strcmp(data.title, "-1"))
	{
		printf("û��¼���鼮��\a\n");
		return 0;
	}
	printf("����������(����-1ֹͣ¼��)��");
	scanf("%s", &data.author);
	if (!strcmp(data.author, "-1"))
	{
		printf("û��¼���鼮��\a\n");
		return 0;
	}
	printf("������۸�(����-1ֹͣ¼��)��");
	scanf("%f", &data.price);
	if (data.price <= 0)
	{
		printf("û��¼���鼮��\a\n");
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
		printf("\n\n�������%d���������(����-1ֹͣ¼��)��", LinkList->data.length + 1);
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}
		printf("����������(����-1ֹͣ¼��)��");
		scanf("%s", &data.author);
		if (!strcmp(data.author, "-1"))
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}
		printf("������۸�(����-1ֹͣ¼��)��");
		scanf("%f", &data.price);
		if (data.price <= 0)
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}
	}
}
//β�巨(������Ϊ˳��)
void TailInsertLinkList(struct Node* LinkList)
{
	struct Node* NewNode;
	struct Node* TailNode = LinkList;//ָ������һ�����
	struct Library data;
	while (TailNode->next != NULL)//��λ�����һ�����
	{
		TailNode = TailNode->next;
	}
	printf("�������%d���������(����-1ֹͣ¼��)��",LinkList->data.length+1);
	scanf("%s", &data.title);
	if (!strcmp(data.title, "-1"))
	{
		printf("û��¼���鼮��\a\n");
		return 0;
	}
	printf("����������(����-1ֹͣ¼��)��");
	scanf("%s", &data.author);
	if (!strcmp(data.author, "-1"))
	{
		printf("û��¼���鼮��\a\n");
		return 0;
	}
	printf("������۸�(����-1ֹͣ¼��)��");
	scanf("%f", &data.price);
	if (data.price <= 0)
	{
		printf("û��¼���鼮��\a\n");
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
		printf("\n\n�������%d���������(����-1ֹͣ¼��)��", LinkList->data.length + 1);
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}
		printf("����������(����-1ֹͣ¼��)��");
		scanf("%s", &data.author);
		if (!strcmp(data.author, "-1"))
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}
		printf("������۸�(����-1ֹͣ¼��)��");
		scanf("%f", &data.price);
		if (data.price <= 0)
		{
			printf("��¼��%d����\n", LinkList->data.length);
			return LinkList;
		}

	}
}
//��λɾ��
void DeleteNode(struct Node* LinkList, struct Library DeletedData)
{
	struct Node* DeleteNode_Front = LinkList;
	struct Node* DeleteNode = LinkList->next;
	while (strcmp(DeleteNode->data.title, DeletedData.title))//Ѱ��ɾ�����ݵ�λ��
	{
		DeleteNode_Front = DeleteNode;
		DeleteNode = DeleteNode->next;
		if (DeleteNode == NULL)
		{
			printf("ͼ���Ϊ�գ��޷�ɾ�����鼮!\a\n");
			return;
		}
	}
	printf("��ɾ��:%s\n", DeletedData.title);
	DeleteNode_Front->next = DeleteNode->next;
	free(DeleteNode);
	LinkList->data.length--;
}
//��λ����ɾ��
void ContinueDeleteNode(struct Node* LinkList)
{
	struct Library DeletedData;
	while (1)
	{
		printf("��������Ҫɾ��������(����-1ֹͣɾ��)��");
		scanf("%s", &DeletedData.title);
		if (!strcmp(DeletedData.title, "-1"))
		{
			printf("ɾ������\n");
			return;
		}
		DeleteNode(LinkList, DeletedData);
	}
}
//���ٵ�����
void DestroyLinkList(struct Node* LinkList)
{
	while (LinkList->next != NULL)
	{
		DeleteNode(LinkList, LinkList->next->data);
	}
	free(LinkList);
	printf("ͼ��ݵ������Ѿ�����\n");
	return 0;
}
//��λ����
void GetData(struct Node* LinkList)
{
	while (1)
	{
		int Location;
		printf("��������ҵĵڼ�����(����-1ֹͣ����)��");
		scanf("%d", &Location);
		if (Location == -1)
		{
			printf("���ҽ���\n");
			return 0;
		}
		if (Location < 1 || Location >LinkList->data.length)
		{
			printf("��λ����ͼ������޷��ҵ���\a\n");
		}
		else
		{
			struct Node* GetNode = LinkList;
			for (int i = 0; i < Location; i++)
			{
				GetNode = GetNode->next;
			}
			printf("������%s\t���ߣ�%s\t�۸�%.2fԪ\t\n", GetNode->data.title, GetNode->data.author, GetNode->data.price);
		}
	}
}
//��λ���ң�2�����������
struct Node* GetData2(struct Node* LinkList, int Location)
{
	if (Location == 0)
	{
		return LinkList;
	}
	if (Location < 1 || Location >LinkList->data.length)
	{
		printf("��λ���ڵ��������޷��ҵ���\n");
		return NULL;
	}
	struct Node* GetNode = LinkList;
	for (int i = 0; i < Location; i++)
	{
		GetNode = GetNode->next;
	}
	return GetNode;
}
//��ӡͼ��ݵ�ÿһ����
void PrintList(struct Node* LinkList)
{
	struct Node* pmove = LinkList;
	int count = 0;
	if (pmove->next == NULL)
	{
		printf("ͼ�����û���κ��鼮\a\n");
		return 0;
	}
	while (pmove->next != NULL)
	{
		count++;
		pmove = pmove->next;
		printf("��%d��������%s\t���ߣ�%s\t�۸�%.2fԪ\t\n", count, pmove->data.title, pmove->data.author, pmove->data.price);
	}
	printf("\n");
}

//��λ����(����������м����)
void LocalInsertLinkList(struct Node* LinkList)
{
	while (1)
	{
		int Location;
		struct Library data;
		printf("���������ڼ�����λ��(����-1ֹͣ����)��\n");
		scanf("%d", &Location);
		if (Location == -1)
		{
			printf("�������\n");
			return 0;
		}
		if ((Location - 1) == 0)
		{
			printf("��λ����ͼ����ﲻ����!\a�Զ������ڵ�1�����ǰ��\n");
		}
		if (Location < 1 || Location >(LinkList->data.length + 1))
		{
			printf("������ͼ������޷����룡\a\n");
			return 0;
		}
		else
		{
			printf("����������鼮������(����-1ֹͣ¼��)��");
			scanf("%s", &data.title);
			if (!strcmp(data.title, "-1"))
			{
				printf("�������\n");
				return 0;
			}
			printf("����������(����-1ֹͣ¼��)��");
			scanf("%s", &data.author);
			if (!strcmp(data.author, "-1"))
			{
				printf("�������\n");
				return 0;
			}
			printf("������۸�(����-1ֹͣ¼��)��");
			scanf("%f", &data.price);
			if (data.price <= 0)
			{
				printf("�������\n");
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
//��ֵ����
void LocateData(struct Node* LinkList)
{
	while (1)
	{
		struct Node* Locatedata = LinkList;
		struct Library data;
		printf("��������Ҫ���ҵ�����(����-1ֹͣ����):");
		scanf("%s", &data.title);
		if (!strcmp(data.title, "-1"))
		{
			printf("���ҽ���\n");
			return 0;
		}
		while (Locatedata->next != NULL)
		{
			Locatedata = Locatedata->next;
			if (!strcmp(Locatedata->data.title, data.title))
			{
				printf("�鼮��������%s\t���ߣ�%s\t�۸�%.2fԪ\t\n", Locatedata->data.title, Locatedata->data.author, Locatedata->data.price);
				goto tiaodian;
			}
		}
		printf("ͼ����Ҳ���������\a\n");
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
		printf("��ӭ��������ͼ���^_^\n");
		printf("��ѡ�����²���:\n1\t(����ͼ��)\n2\t(����ͼ��)\n3\t(ɾ��ͼ��)\n4\t(��ӡ����ͼ��)\n5\t(����ͼ����������ݲ��˳�����)\n");
		scanf("%d", &num1);
		switch (num1)
		{
		case 1: //����ͼ��
			printf("��ѡ�����ͼ��ķ�����\n1\t(��ǰ�����)\n2\t(��������)\n3\t(���м����)\n");
			scanf("%d", &num2);
			switch (num2)
			{
			case 1: Insert_HeadNode(LinkList);
				break;
			case 2: TailInsertLinkList(LinkList);
				break;
			case 3: LocalInsertLinkList(LinkList);
				break;
			default: printf("���������������ȷ�����֣�\n");
				break;
			}
			break;
		case 2: //����ͼ��
			printf("��ѡ�����ͼ��ķ�����\n1\t(����)\n2\t(����(�ڼ�����))\n");
			scanf("%d", &num3);
			switch (num3)
			{
			case 1: LocateData(LinkList);
				break;
			case 2: GetData(LinkList);
				break;
			default: printf("���������������ȷ�����֣�\n");
				break;
			}
			break;
		case 3: //ɾ��ͼ��
			ContinueDeleteNode(LinkList);
			break;
		case 4://��ӡ����ͼ��
			PrintList(LinkList);
			break;
		case 5: //ɾ��ͼ����������ݲ��˳�����
			DestroyLinkList(LinkList);
			printf("�ݰݣ���ӭ�´ι�������ͼ���^_^\n");
			return 0;
		default: printf("���������������ȷ�����֣�\a\n\n");
			rewind(stdin);
			break;
		}
	}
}
