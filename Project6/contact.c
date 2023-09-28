#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(Contact* con)
{
	assert(con);
	con->count = 0;
	memset(con->data, 0, sizeof(con->data));
}
void ShowContact(const Contact *con)
{
	assert(con);
	for (int i = 0; i < con->count; i++)
	{
		printf("��%dλ������%-10s ���䣺%-d�� �Ա�%-5s �绰��%-12s ��ַ��%-30s\n",i+1
																	, con->data[i].name
																	, con->data[i].age
																	, con->data[i].sex
																	, con->data[i].tele
																	, con->data[i].addr);
	}
}
void AddContact(Contact* con)
{
	assert(con);
	if (con->count == MAX)
	{
		printf("ͨѶ¼����\a\n");
		return;
	}
	printf("������¼�����Ϣ->\n");
	printf("���������֣�");
	scanf("%s",con->data[con->count].name);
	printf("���������䣺");
	scanf("%d", &(con->data[con->count].age));
	printf("�������Ա�");
	scanf("%s", con->data[con->count].sex);
	printf("������绰��");
	scanf("%s", con->data[con->count].tele);
	printf("�������ַ��");
	scanf("%s", con->data[con->count].addr);
	con->count++;
	printf("¼��ɹ�\n");
}
int Find_name(Contact *con, char name[])
{
	assert(con);
	//int ret;
	//printf("%d\n", con->count);
	for (int i = 0; i < con->count; i++)
	{
		//ret = strcmp(con->data[i].name, name);
		//printf("%d", ret);
		if (0 == strcmp(con->data[i].name,name)) 
		{
			return i;
		}
	}
 	return -1;
}
void DelContact(Contact* con)
{
	char name[NAME_MAX] = {0};
	assert(con);//�ж�ͨѶ¼�Ƿ�Ϊ��ָ��
	if (0 == con->count)//�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n\a");
		return;
	} 
	printf("��������Ҫɾ�������֣�");
	scanf("%s", name);
	//1.����
	int ret = Find_name(&con,name);
	if (ret == -1)
	{
		printf("ͨѶ¼û�ø�����\a\n");
		return;
	}
	//2.ɾ��
	for (int i = ret; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("ɾ���ɹ�\n");
	con->count--;
}