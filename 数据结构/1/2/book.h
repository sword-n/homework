typedef struct 
{
    char no[8]; //8λ���
    char name[20]; //����
    int price; //����
}Book;
 
typedef struct LNode
{
    Book data; //������
    struct LNode *next; //ָ����
}LNode,*LinkList; 
 
void Input(int n,LinkList &L);      //����ָ������Ϊn��ͼ����Ϣ
 
void Search(LinkList L,char *na);              //��������Ϊna��ͼ����Ϣ
 
void Locate(LinkList L,int pos);                  //����λ��Ϊpos��ͼ����Ϣ
 
void Insert(LinkList &L,Book b,int pos);          //��posλ�ò���һ��ͼ����Ϣ
 
void Delete(LinkList &L,int pos);                 //ɾ��ָ��λ��Ϊpos��ͼ���¼
 
int Count(LinkList L);              //ͳ�Ʊ���ͼ��ĸ���
