//book.cpp�ļ�
 
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "book.h"
 
#define NULL 0
 
void Input(int n,LinkList&L)     //����ָ������Ϊn��ͼ����Ϣ
{
    int i=0;
    do
    {
        LNode *p=(LNode*)malloc(sizeof(LNode));     //������ڵ�
        printf("�������%d�������Ϣ:\n",i+1);        //��ʼ��������Ϣ
         printf("���������: ");
        scanf("%s",p->data.no);
        printf("����������: ");
        scanf("%s",p->data.name);
        printf("�����붨��: ");
        scanf("%d",&p->data.price);
        p->next=NULL;                                   //�ýڵ����һ���ڵ�Ϊ��
        if(!L)                                          //��ʼʱ��Ϊ��
            L=p; 
        else 
        {   
            LNode *t=(LNode*)malloc(sizeof(LNode));
            for(LNode *q=L;q->next;q=q->next){
            	
			
			}             //�ҵ����β��
            q->next=p;
        }
        ++i;
    }while(i<n);
}
 
 
void Search(LinkList L,char *na)           //��������Ϊna��ͼ����Ϣ
{
    bool flag=false;
    LNode *p=L;
    while(p)
    {
        if(strcmp(p->data.name,na)==0)
        {
            flag=true;        //�ҵ�����
            break;
        }
        p=p->next;
    }
    if(flag)
    {
        printf("�ҵ�����,�������ϢΪ: \n");
        printf("���: %s\n",p->data.no);
        printf("����: %d\n",p->data.price);
    }
    else
        printf("û�и���!\n");
}
     
 
void Locate(LinkList L,int pos)                  //����λ��Ϊpos��ͼ����Ϣ
{
    LNode *p=L;
    int i=1;
    while(p && i<pos)
    {
        p=p->next;
        i++;
    }
    if(!p || i>pos)
        printf("��λ�ò�����!\n");
    else
    {
        printf("��λ�������ϢΪ: \n");
        printf("���: %s\n",p->data.no);
        printf("����: %s\n",p->data.name);
        printf("����: %d\n",p->data.price);
    }
}
         
void Insert(LinkList&L,Book b,int pos)          //��posλ�ò���һ��ͼ����Ϣ
{
    LNode *p=(LNode*)malloc(sizeof(LNode));
    strcpy(p->data.name,b.name);
    strcpy(p->data.no,b.no);
    p->data.price=b.price;
    p->next=NULL;
    int i=1;
    LNode *q=L;
    while(q && i<pos-1)  //�ҵ�posǰһ��λ��
    {
        q=q->next;
        ++i;
    }
    if(!q || i>=pos)
        printf("��λ�ò�����!����ʧ��!\n");
    else
    {
        p->next=q->next;
        q->next=p;
    }
}
 
void Delete(LinkList&L,int pos)                 //ɾ��ָ��λ��Ϊpos��ͼ���¼
{
    int i=1;
    LNode *q=L;
    while(q && i<pos-1)  //�ҵ�posǰһ��λ��
    {
        q=q->next;
        ++i;
    }
    if(!q || i>pos)
        printf("��λ�ò�����!ɾ��ʧ��!\n");
    else
    {
        LNode *p=q->next;
        q->next=p->next;
        delete p;
    }
}
 
int Count(LinkList L)             //ͳ�Ʊ���ͼ��ĸ���
{
    int count=0;
    LNode *p=L;
    while(p)
    {
        p=p->next;
        ++count;
    }
    return count;
}
