#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 100//通讯录的个数
#define NAME_MAX 20//名字大小
#define SEX_MAX 5//性别大小
#define TELE_MAX 12//电话号码
#define ADDR_MAX 30//地址大小
//类型的声明
//个人信息
typedef struct People
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}People;
//通讯录
typedef struct Contact
{
	People data[MAX];
	int count;//记录人数
} Contact;
void InitContact(Contact* con);//初始化通讯录
void AddContact(Contact* con);//添加一个人的信息
void ShowContact(const Contact* con);//打印通讯录
int Find_name(Contact* con, char name[]);//通过名字查找一个人的信息
void DelContact(Contact* con);//删除一个人的信息
