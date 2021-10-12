//book.cpp文件
 
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "book.h"
 
#define NULL 0
 
void Input(int n,LinkList&L)     //输入指定个数为n的图书信息
{
    int i=0;
    do
    {
        LNode *p=(LNode*)malloc(sizeof(LNode));     //定义个节点
        printf("请输入第%d本书的信息:\n",i+1);        //开始输入书信息
         printf("请输入书号: ");
        scanf("%s",p->data.no);
        printf("请输入书名: ");
        scanf("%s",p->data.name);
        printf("请输入定价: ");
        scanf("%d",&p->data.price);
        p->next=NULL;                                   //该节点的下一个节点为空
        if(!L)                                          //开始时表为空
            L=p; 
        else 
        {   
            LNode *t=(LNode*)malloc(sizeof(LNode));
            for(LNode *q=L;q->next;q=q->next){
            	
			
			}             //找到表的尾部
            q->next=p;
        }
        ++i;
    }while(i<n);
}
 
 
void Search(LinkList L,char *na)           //查找书名为na的图书信息
{
    bool flag=false;
    LNode *p=L;
    while(p)
    {
        if(strcmp(p->data.name,na)==0)
        {
            flag=true;        //找到该书
            break;
        }
        p=p->next;
    }
    if(flag)
    {
        printf("找到该书,该书的信息为: \n");
        printf("书号: %s\n",p->data.no);
        printf("定价: %d\n",p->data.price);
    }
    else
        printf("没有该书!\n");
}
     
 
void Locate(LinkList L,int pos)                  //返回位置为pos的图书信息
{
    LNode *p=L;
    int i=1;
    while(p && i<pos)
    {
        p=p->next;
        i++;
    }
    if(!p || i>pos)
        printf("该位置不存在!\n");
    else
    {
        printf("该位置书的信息为: \n");
        printf("书号: %s\n",p->data.no);
        printf("书名: %s\n",p->data.name);
        printf("定价: %d\n",p->data.price);
    }
}
         
void Insert(LinkList&L,Book b,int pos)          //在pos位置插入一个图书信息
{
    LNode *p=(LNode*)malloc(sizeof(LNode));
    strcpy(p->data.name,b.name);
    strcpy(p->data.no,b.no);
    p->data.price=b.price;
    p->next=NULL;
    int i=1;
    LNode *q=L;
    while(q && i<pos-1)  //找到pos前一个位置
    {
        q=q->next;
        ++i;
    }
    if(!q || i>=pos)
        printf("该位置不存在!插入失败!\n");
    else
    {
        p->next=q->next;
        q->next=p;
    }
}
 
void Delete(LinkList&L,int pos)                 //删除指定位置为pos的图书记录
{
    int i=1;
    LNode *q=L;
    while(q && i<pos-1)  //找到pos前一个位置
    {
        q=q->next;
        ++i;
    }
    if(!q || i>pos)
        printf("该位置不存在!删除失败!\n");
    else
    {
        LNode *p=q->next;
        q->next=p->next;
        delete p;
    }
}
 
int Count(LinkList L)             //统计表中图书的个数
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
