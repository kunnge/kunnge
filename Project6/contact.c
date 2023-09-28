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
		printf("第%d位姓名：%-10s 年龄：%-d岁 性别：%-5s 电话：%-12s 地址：%-30s\n",i+1
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
		printf("通讯录已满\a\n");
		return;
	}
	printf("请输入录入的信息->\n");
	printf("请输入名字：");
	scanf("%s",con->data[con->count].name);
	printf("请输入年龄：");
	scanf("%d", &(con->data[con->count].age));
	printf("请输入性别：");
	scanf("%s", con->data[con->count].sex);
	printf("请输入电话：");
	scanf("%s", con->data[con->count].tele);
	printf("请输入地址：");
	scanf("%s", con->data[con->count].addr);
	con->count++;
	printf("录入成功\n");
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
	assert(con);//判断通讯录是否为空指针
	if (0 == con->count)//判断通讯录是否为空
	{
		printf("通讯录为空，无法删除\n\a");
		return;
	} 
	printf("请输入需要删除的名字：");
	scanf("%s", name);
	//1.查找
	int ret = Find_name(&con,name);
	if (ret == -1)
	{
		printf("通讯录没用该数据\a\n");
		return;
	}
	//2.删除
	for (int i = ret; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("删除成功\n");
	con->count--;
}