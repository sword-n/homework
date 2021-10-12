//main.cpp文件
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    LinkList L=NULL;      //定义一个空的书表
    int number;           //书的数目
    int pos;              // 位置
    char name[20];        //书名
    Book book;            //定义一根本书
 
    printf("\t\t1.输入图书信息\n");
    printf("\t\t2.按图书名查找\n");
    printf("\t\t3.按书位置查找\n");
    printf("\t\t4..插入图书信息\n");
    printf("\t\t5..删除图书信息\n");
    printf("\t\t6.统计图书数目\n");
    printf("\t\t0.退出\n\n");
 
    int choice;
    while(true)
    {
        printf("请选择操作: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("请输入图书数目的数目: ");
            scanf("%d",&number);
            Input(number,L);
            break;
        case 2:
            printf("请输入要查找的书名: ");
            scanf("%s",name);
            Search(L,name);
            break;
        case 3:
            printf("请输入图书的位置: ");
            scanf("%d",&pos);
            Locate(L,pos);
            break;
        case 4:
            printf("请输入图书插入的位置: ");
            scanf("%d",&pos);
            printf("请输入要插入图书的信息: \n");
            printf("请输入书号: ");
            scanf("%s",book.no);
            printf("请输入书名: ");
            scanf("%s",book.name);
            printf("请输入定价: ");
            scanf("%d",&book.price);
            Insert(L,book,pos);
            break;
        case 5:
            printf("请输入删除图书的位置: ");
            scanf("%d",&pos);
            Delete(L,pos);
            break;
        case 6:
            printf("图书的数目为%d\n",Count(L));
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入错误，请重新输入!\n");
            break;
        }
    }
    return 0;
}
