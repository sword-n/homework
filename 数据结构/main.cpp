#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;
 
//3.���ݵ���ƣ�
	//3.1 ������ʲô������������---->����--->����
	//3.2 ���ݵĽṹ  ---->ͼ�����Ϣ
struct bookInfo 
{
	char name[20];   //����
	float price;	 //�鼮�ļ۸�
	int num;		 //�������
};
struct Node 
{
	struct bookInfo data;
	struct Node* next;
};
struct Node* listBook = NULL;
//������ͷ�� ��ͷ����һ���ṹ�����
 
//��һ�����֣��û���Ϣ
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
	//��̬�ڴ�����
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//�����Ļ�������>? ʹ��ǰ�����ʼ��
	headNode->next = NULL;
	return headNode;
}
 
//�����ڵ�: Ϊ������׼��
//���û������ݱ�Ϊ�ṹ�����
struct Node* createNode(struct bookInfo  data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//���룺ֻ��Ҫһ�ֲ��뷽ʽ
void insertNodeByHead(struct Node* headNode, struct bookInfo  data)
{
	struct Node* newNode = createNode(data);
	//���������Ӻ�Ͽ�
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//ָ��ɾ��
//posLeftNode->next=posNode->next;
//free(posNode);
void deleteNodeByName(struct Node* headNode, char *bookName) 
{
	struct Node* posLeftNode = headNode;
	struct Node* posNode = headNode->next;
	//�鼮�������ַ������ַ����ȽϺ���
	while (posNode != NULL && strcmp(posNode->data.name,bookName)) 
	{
		posLeftNode = posNode;
		posNode = posLeftNode->next;
	}
	//���۲��ҵĽ��
	if (posNode == NULL)
		return;
	else
	{
		printf("ɾ���ɹ�!\n");
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
	printf("����\t�۸�\t����\n");
	while (pMove!=NULL)
	{
		//�����
		printf("%s\t%.1f\t%d\n", pMove->data.name, pMove->data.price, pMove->data.num);
		pMove = pMove->next;
	}
}
 
 
 
//1.д����--->�˵�--->ģ��
void makeMenu() 
{
	printf("---------------------------------------\n");
	printf("   xxooͼ�����ϵͳ\n");
	printf("\t0.�˳�ϵͳ\n");
	printf("\t1.�Ǽ��鼮\n");
	printf("\t2.����鼮\n");
	printf("\t3.�����鼮\n");
	printf("\t4.�黹�鼮\n");
	printf("\t5.�鼮����\n");
	printf("\t6.ɾ���鼮\n");
	printf("\t7.�����鼮\n");
	printf("---------------------------------------\n");
	printf("������(0~7):");
}
//ֱ���ļ�����?
//д����
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
//�ļ�������
void readInfoFromFile(const char* fileName, struct Node* headNode) 
{
	FILE* fp = fopen(fileName, "r");  //��һ�δ��ļ��϶�������
	if (fp == NULL) 
	{	//�����ھʹ�����������ļ�
		fp = fopen(fileName, "w+");
	}
	struct bookInfo tempData;
	while (fscanf(fp, "%s\t%f\t%d\n", tempData.name, &tempData.price, &tempData.num) != EOF) 
	{
		insertNodeByHead(listBook, tempData);
	}
	fclose(fp);
}
//�㷨��һ��˼�� 
void bubbleSortlistBook(struct Node* headNode) 
{
	for (struct Node* p = headNode->next; p != NULL; p = p->next) 
	{
		for (struct Node* q = headNode->next; q->next != NULL; q = q->next) 
		{
			if (q->data.price > q->next->data.price) 
			{
				//����ֵ
				struct bookInfo tempData = q->data;
				q->data = q->next->data;
				q->next->data = tempData;
			}
		}
	}
	printlistBook(headNode);
}
 
 
//2.������
void keyDown() 
{
	int userKey = 0;
	struct bookInfo tempBook;  //����һ����ʱ�ı����洢�鼮��Ϣ
	struct Node* result = NULL;
	scanf("%d", &userKey);
	switch (userKey) 
	{
	case 0:
		printf("�� �˳� ��\n");
		printf("�˳��ɹ�\n");
		system("pause");
		exit(0);				//�رյ���������
		break;
	case 1:
		printf("�� �Ǽ� ��\n");
		printf("�����鼮����Ϣ(name,price,num):");
		scanf("%s%f%d", tempBook.name, &tempBook.price, &tempBook.num);
		insertNodeByHead(listBook, tempBook);
		saveInfoToFile("bookinfo.txt", listBook);
		break;
	case 2:
		printf("�� ��� ��\n");
		printlistBook(listBook);
		break;
	case 3:
		printf("�� ���� ��\n");		//�鼮���ڿ��Խ��� ���鼮��������-1 �����ڽ���ʧ��
		printf("��������ĵ�������");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result==NULL) 
		{
			printf("û������鼮�޷�����!\n");
		}
		else 
		{
			if (result->data.num > 0) 
			{
				result->data.num--;
				printf("���ĳɹ�!\n");
			}
			else 
			{
				printf("��ǰ�鼮�޿���ڣ�����ʧ��!\n");
			}
		}
		break;
	case 4:
		printf("�� �黹 ��\n");		//��ǰ�鼮������+1
		printf("������黹��������");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result == NULL)
		{
			printf("������Դ�Ƿ�!\n");
		}
		else
		{
			result->data.num++;
			printf("�鼮�黹�ɹ�!\n");
		}
		break;
	case 5:
		printf("�� ���� ��\n");
		bubbleSortlistBook(listBook);
		break;
	case 6:
		printf("�� ɾ�� ��\n");
		printf("������ɾ������:");
		scanf("%s", tempBook.name);
		deleteNodeByName(listBook, tempBook.name);
		saveInfoToFile("bookinfo.txt", listBook);
		break;
	case 7:
		printf("�� ���� ��\n");
		printf("������Ҫ��ѯ������:");
		scanf("%s", tempBook.name);
		result = searchByName(listBook, tempBook.name);
		if (result == NULL) 
		{
			printf("δ�ҵ������Ϣ!\n");
		}
		else
		{
			printf("����\t�۸�\t����\n");
			printf("%s\t%.1f\t%d\n", result->data.name, result->data.price, result->data.num);
		}
		break;
	default:
		printf("�� error ��\n");
		break;
	}
}
//easyx  inputBox
//�Լ���װһ��Edit
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

