#include<stdlib.h>
#include<stdio.h>
struct node
{
    int num;
    char name[256];
    float price;
    struct node *next;
};
struct node *head=NULL,*point,*newNode;
int Count=0;//������
struct node* SearchForId(int);
//���ӽڵ�
void Add()
{
    int id;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("�ڴ����\n");
        getch();
        exit(1);
    }
    printf("��������ţ�");
    scanf("%d",&id);
    if(SearchForId(id)!=NULL)
    {
        printf("������Ѵ��ڣ�");
        return;
    }
    newNode->num=id;
    printf("\n����������:");
    scanf("%s",&newNode->name);
    printf("\n������۸�:");
    scanf("%f",&newNode->price);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        point=head;
        while(point->next!=NULL)
        {
            point=point->next;
        }
        point->next=newNode;
    }
    point=newNode;
    point->next=NULL;
    Count++;
}
//��ѯ
struct node* SearchForId(int id)
{
    int n;
    struct node *temp;
    point=head;
    for(n=0;n<Count;n++)
    {
        if(point->num==id)
        {
            return point;
        }
        else
        {
            point=point->next;
        }
    }
    if(n>=Count)
        return NULL;
}
struct node* SearchForName(char *s)
{
    int n;
    struct node *temp;
    point=head;
    for(n=0;n<Count;n++)
    {
        if(!strcmp(point->name,s))
        {
            return point;
        }
        else
        {
            point=point->next;
        }
    }
    if(n>=Count)
        return NULL;
}
//ɾ��
int DeleteNode(int i)
{
    int n=0;
    struct node *temp;
    if(head->num==i)
    {
        head=head->next;
        Count--;
        return 1;
    }
    point=head;
    for(n=0;n<Count;n++)
    {
        temp=point;
        point=point->next;
        if(point->num==i)
        {
            temp->next=point->next;
            Count--;
            return 1;
        }
    }
    return 0;
}
main()
{    
    int function=1;
    int id;
    char s[256];
    struct node *book;
    while(function)
    {
        printf("1�����ͼ��\n");
        printf("2��������������\n");
        printf("3��������Ų���\n");
        printf("4��ɾ��ͼ��\n");
        printf("5��ͳ��\n");
        printf("6���뿪\n");
        printf("��ѡ��");
        scanf("%d",&function);
        switch(function)
        {
            case 1:
                Add();
                break;
            case 2:
                printf("������������");
                scanf("%s",&s);
                book=SearchForName(s);
                if(book==NULL)
                {
                    printf("δ�ҵ����ݣ�");
                }
                else
                {
                    printf("\n��ţ�%d\n",book->num);
                    printf("������%s\n",book->name);
                    printf("�۸�%f\n",book->price);
                }
                break;
            case 3:
                printf("��������ţ�");
                scanf("%d",&id);
                book=SearchForId(id);
                if(book==NULL)
                {
                    printf("δ�ҵ����ݣ�");
                }
                else
                {
                    printf("\n��ţ�%d\n",book->num);
                    printf("������%s\n",book->name);
                    printf("�۸�%f\n",book->price);
                }
                break;
            case 4:
                printf("��������ţ�");
                scanf("%d",&id);
                if(DeleteNode(id))
                {
                    printf("ɾ���ɹ���\n");
                }
                else
                {
                    printf("ɾ��ʧ��~\n");
                }
                break;
            case 5:
                printf("Ŀǰ����%d���顣\n",Count);
                break;
            case 6:
                function=0;
                break;
            default:
                printf("�������");
                exit(1);
                break;
        }
        printf("�����������...");
        getch();
        system("cls");
    }
} 
