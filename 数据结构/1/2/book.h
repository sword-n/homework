typedef struct 
{
    char no[8]; //8位书号
    char name[20]; //书名
    int price; //定价
}Book;
 
typedef struct LNode
{
    Book data; //数据域
    struct LNode *next; //指针域
}LNode,*LinkList; 
 
void Input(int n,LinkList &L);      //输入指定个数为n的图书信息
 
void Search(LinkList L,char *na);              //查找书名为na的图书信息
 
void Locate(LinkList L,int pos);                  //返回位置为pos的图书信息
 
void Insert(LinkList &L,Book b,int pos);          //在pos位置插入一个图书信息
 
void Delete(LinkList &L,int pos);                 //删除指定位置为pos的图书记录
 
int Count(LinkList L);              //统计表中图书的个数
