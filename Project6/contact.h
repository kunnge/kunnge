#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 100//ͨѶ¼�ĸ���
#define NAME_MAX 20//���ִ�С
#define SEX_MAX 5//�Ա��С
#define TELE_MAX 12//�绰����
#define ADDR_MAX 30//��ַ��С
//���͵�����
//������Ϣ
typedef struct People
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}People;
//ͨѶ¼
typedef struct Contact
{
	People data[MAX];
	int count;//��¼����
} Contact;
void InitContact(Contact* con);//��ʼ��ͨѶ¼
void AddContact(Contact* con);//���һ���˵���Ϣ
void ShowContact(const Contact* con);//��ӡͨѶ¼
int Find_name(Contact* con, char name[]);//ͨ�����ֲ���һ���˵���Ϣ
void DelContact(Contact* con);//ɾ��һ���˵���Ϣ
