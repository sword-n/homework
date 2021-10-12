#ifndef LIBRARY_INCLUDE//条件编译 防止重复包含
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


//以下是函数声明


void showB(book*p);//显示书籍信息函数
book*S_name(book*head,char name[]);//按书籍名查找函数
void S_author(book*head);//按作者查找
keynode*initindex(book*head);//初始化建立索引表
void delkey(keynode*keyhead);
book*S_number(long num,book*bhead);//按书号查找

book* Bload();//书籍链表读取

void Bsave(book*Bhead);//书籍信息链表写入

void insert(book*bhead);//入库


void borrow(book*Bhead);//借书

void style();//风格函数
void intpsd(char *psd);//密码保护函数
//菜单
void menu2(book*bhead);
long backtime();//结束时间
#endif



