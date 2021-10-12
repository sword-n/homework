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
int Count=0;//链表长度
struct node* SearchForId(int);
//增加节点
void Add()
{
    int id;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("内存错误\n");
        getch();
        exit(1);
    }
    printf("请输入书号：");
    scanf("%d",&id);
    if(SearchForId(id)!=NULL)
    {
        printf("该书号已存在！");
        return;
    }
    newNode->num=id;
    printf("\n请输入书名:");
    scanf("%s",&newNode->name);
    printf("\n请输入价格:");
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
//查询
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
//删除
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
        printf("1：添加图书\n");
        printf("2：根据书名查找\n");
        printf("3：根据书号查找\n");
        printf("4：删除图书\n");
        printf("5：统计\n");
        printf("6：离开\n");
        printf("请选择：");
        scanf("%d",&function);
        switch(function)
        {
            case 1:
                Add();
                break;
            case 2:
                printf("请输入书名：");
                scanf("%s",&s);
                book=SearchForName(s);
                if(book==NULL)
                {
                    printf("未找到数据！");
                }
                else
                {
                    printf("\n书号：%d\n",book->num);
                    printf("书名：%s\n",book->name);
                    printf("价格：%f\n",book->price);
                }
                break;
            case 3:
                printf("请输入书号：");
                scanf("%d",&id);
                book=SearchForId(id);
                if(book==NULL)
                {
                    printf("未找到数据！");
                }
                else
                {
                    printf("\n书号：%d\n",book->num);
                    printf("书名：%s\n",book->name);
                    printf("价格：%f\n",book->price);
                }
                break;
            case 4:
                printf("请输入书号：");
                scanf("%d",&id);
                if(DeleteNode(id))
                {
                    printf("删除成功！\n");
                }
                else
                {
                    printf("删除失败~\n");
                }
                break;
            case 5:
                printf("目前已有%d本书。\n",Count);
                break;
            case 6:
                function=0;
                break;
            default:
                printf("输入错误！");
                exit(1);
                break;
        }
        printf("按任意键继续...");
        getch();
        system("cls");
    }
} 
