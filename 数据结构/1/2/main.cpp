//main.cpp�ļ�
#include "book.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    LinkList L=NULL;      //����һ���յ����
    int number;           //�����Ŀ
    int pos;              // λ��
    char name[20];        //����
    Book book;            //����һ������
 
    printf("\t\t1.����ͼ����Ϣ\n");
    printf("\t\t2.��ͼ��������\n");
    printf("\t\t3.����λ�ò���\n");
    printf("\t\t4..����ͼ����Ϣ\n");
    printf("\t\t5..ɾ��ͼ����Ϣ\n");
    printf("\t\t6.ͳ��ͼ����Ŀ\n");
    printf("\t\t0.�˳�\n\n");
 
    int choice;
    while(true)
    {
        printf("��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("������ͼ����Ŀ����Ŀ: ");
            scanf("%d",&number);
            Input(number,L);
            break;
        case 2:
            printf("������Ҫ���ҵ�����: ");
            scanf("%s",name);
            Search(L,name);
            break;
        case 3:
            printf("������ͼ���λ��: ");
            scanf("%d",&pos);
            Locate(L,pos);
            break;
        case 4:
            printf("������ͼ������λ��: ");
            scanf("%d",&pos);
            printf("������Ҫ����ͼ�����Ϣ: \n");
            printf("���������: ");
            scanf("%s",book.no);
            printf("����������: ");
            scanf("%s",book.name);
            printf("�����붨��: ");
            scanf("%d",&book.price);
            Insert(L,book,pos);
            break;
        case 5:
            printf("������ɾ��ͼ���λ��: ");
            scanf("%d",&pos);
            Delete(L,pos);
            break;
        case 6:
            printf("ͼ�����ĿΪ%d\n",Count(L));
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("�����������������!\n");
            break;
        }
    }
    return 0;
}
