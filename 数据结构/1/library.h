#ifndef LIBRARY_INCLUDE//�������� ��ֹ�ظ�����
#define LIBRARY_INCLUDE

#include"stdio.h"
#include"string.h"
#include"conio.h"
#include"windows.h"
#include"time.h"

typedef struct BOOK{
	long number;
	char name[30];
	char author[30];
	char press[30];
	long presstime;
	int exist;
	int total;
	struct BOOK *next;
}book;

typedef struct KEY{
	long key;
	book *adress;
	struct KEY *next;
}keynode;


//�����Ǻ�������


void showB(book*p);//��ʾ�鼮��Ϣ����
book*S_name(book*head,char name[]);//���鼮�����Һ���
void S_author(book*head);//�����߲���
keynode*initindex(book*head);//��ʼ������������
void delkey(keynode*keyhead);
book*S_number(long num,book*bhead);//����Ų���

book* Bload();//�鼮�����ȡ

void Bsave(book*Bhead);//�鼮��Ϣ����д��

void insert(book*bhead);//���


void borrow(book*Bhead);//����

void style();//�����
void intpsd(char *psd);//���뱣������
//�˵�
void menu2(book*bhead);
long backtime();//����ʱ��
#endif



