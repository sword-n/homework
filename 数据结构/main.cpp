#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;
 
//3.数据的设计？
	//3.1 程序用什么东西处理数据---->容器--->链表
	//3.2 数据的结构  ---->图书的信息
struct bookInfo 
{
	char name[20];   //书名
	float price;	 //书籍的价格
	int num;		 //书的数量
};
struct Node 
{
	struct bookInfo data;
	struct Node* next;
};
struct Node* listBook = NULL;
//创建表头： 表头就是一个结构体变量
 
//另一个部分：用户信息
struct student 
{
	char name[20];
	char tel[20];
	int curNum;
	struct bookInfo userBook[3];
};
list<student> myList;
 
 
 
struct Node* createHead() 
{
	//动态内存申请
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//变量的基本规则>? 使用前必须初始化
	headNode->next = NULL;
	return headNode;
}
 
//创建节点: 为插入做准备
//把用户的数据变为结构体变量
struct Node* createNode(struct bookInfo  data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//插入：只需要一种插入方式
void insertNodeByHead(struct Node* headNode, struct bookInfo  data)
{
	struct Node* newNode = createNode(data);
	//必须先连接后断开
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//指定删除
//posLeftNode->next=posNode->next;
//free(posNode);
void deleteNodeByName(struct Node* headNode, char *bookName) 
{
	struct Node* posLeftNode = headNode;
	struct Node* posNode = headNode->next;
	//书籍名字是字符串，字符串比较函数
	while (posNode != NULL && strcmp(posNode->data.name,bookName)) 
	{
		posLeftNode = posNode;
		posNode = posLeftNode->next;
	}
	//讨论查找的结果
	if (posNode == NULL)
		return;
	else
	{
		printf("删除成功!\n");
		posLeftNode->next = posNode->next;
		free(posNode);
		posNode = NULL;
	}
}
struct Node* searchByName(struct Node* headNode, char* bookName) 
{
	struct Node* posNode = headNode->next;
	while (posNode != NULL && strcmp(posNode->data.name, bookName)) 
	{
		posNode = posNode->next;
	}
	return posNode;
}
 
 
 
 
void printlistBook(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	printf("书名\t价格\t数量\n");
	while (pMove!=NULL)
	{
		//剥洋葱
		printf("%s\t%.1f\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
		pMove = pMove->next;
	}
}
 
 
 
//1.写界面--->菜单--->模块
void makeMenu() 
{
	printf("---------------------------------------\n");
	printf("   xxoo图书管理系统\n");
	printf("\t0.退出系统\n");
	printf("\t1.登记书籍\n");
	printf("\t2.浏览书籍\n");
	printf("\t3.借阅书籍\n");
	printf("\t4.归还书籍\n");
	printf("\t5.书籍排序\n");
	printf("\t6.删除书籍\n");
	printf("\t7.查找书籍\n");
	printf("---------------------------------------\n");
	printf("请输入(0~7):");
}
//直接文件操作?
//写操作
void saveInfoToFile(const char* fileName, struct Node* headNode) 
{
	FILE* fp = fopen(fileName, "w");
	struct Node* pMove = headNode->next;
	while (pMove != NULL) 
	{
		fprintf(fp, "%s\t%.1f\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
		pMove = pMove->next;
	}
	fclose(fp);
}
//文件读操作
void readInfoFromFile(const char* fileName, struct Node* headNode) 
{
	FILE* fp = fopen(fileName, "r");  //第一次打开文件肯定不存在
	if (fp == NULL) 
	{	//不存在就创建出来这个文件
		fp = fopen(fileName, "w+");
	}
	struct bookInfo tempData;
	while (fscanf(fp, "%s\t%f\t%d\n", tempData.name, &tempData.price, &tempData.num) != EOF) 
	{
		insertNodeByHead(listBook, tempData);
	}
	fclose(fp);
}
//算法是一种思想 
void bubbleSortlistBook(struct Node* headNode) 
{
	for (struct Node* p = headNode->next; p != NULL; p = p->next) 
	{
		for (struct Node* q = headNode->next; q->next != NULL; q = q->next) 
		{
			if (q->data.price > q->next->data.price) 
			{
				//交换值
				struct bookInfo tempData = q->data;
				q->data = q->next->data;
				q->next->data = tempData;
			}
		}
	}
	printlistBook(headNode);
}
 
 
//2.做交互
void keyDown() 
{
	int userKey = 0;
	struct bookInfo tempBook;  //产生一个临时的变量存储书籍信息
	struct Node* result = NULL;
	scanf("%d", &userKey);
	switch (userKey) 
	{
	case 0:
		printf("【 退出 】\n");
		printf("退出成功\n");
		system("pause");
		exit(0);				//关闭掉整个程序
		break;
	case 1:
		printf("【 登记 】\n");
		printf("输入书籍的信息(name,price,num):");
		scanf("%s%f%d", tempBook.name, &tempBook.price, &tempBook.num);
		insertNodeByHead(listBook, tempBook);
		saveInfoToFile("bookinfo.txt", listBook);
		break;
	case 2:
		printf("【 浏览 】\n");
		printlistBook(listBook);
		break;
	case 3:
		printf("【 借阅 】\n");		//书籍存在可以借阅 ，书籍的总数量-1 不存在借阅失败
		printf("请输入借阅的书名：");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result==NULL) 
		{
			printf("没有相关书籍无法借阅!\n");
		}
		else 
		{
			if (result->data.num > 0) 
			{
				result->data.num--;
				printf("借阅成功!\n");
			}
			else 
			{
				printf("当前书籍无库存在，借阅失败!\n");
			}
		}
		break;
	case 4:
		printf("【 归还 】\n");		//当前书籍的数量+1
		printf("请输入归还的书名：");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result == NULL)
		{
			printf("该书来源非法!\n");
		}
		else
		{
			result->data.num++;
			printf("书籍归还成功!\n");
		}
		break;
	case 5:
		printf("【 排序 】\n");
		bubbleSortlistBook(listBook);
		break;
	case 6:
		printf("【 删除 】\n");
		printf("请输入删除书名:");
		scanf("%s", tempBook.name);
		deleteNodeByName(listBook, tempBook.name);
		saveInfoToFile("bookinfo.txt", listBook);
		break;
	case 7:
		printf("【 查找 】\n");
		printf("请输入要查询的书名:");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result == NULL) 
		{
			printf("未找到相关信息!\n");
		}
		else
		{
			printf("书名\t价格\t数量\n");
			printf("%s\t%.1f\t%d\n", result->data.name, result->data.price, result->data.num);
		}
		break;
	default:
		printf("【 error 】\n");
		break;
	}
}
//easyx  inputBox
//自己封装一个Edit
int main() 
{
	listBook= createHead();
	readInfoFromFile("bookinfo.txt", listBook);
	while (1) 
	{
		makeMenu();
		keyDown();
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

