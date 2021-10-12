#include"library.h"

//按书名查找书
book*S_name(book*head,char name[])
{
	book*temp=head->next;
	if(temp==NULL)
		printf("\n书库中还没有书籍,请入库!");
	else
	{
		while(temp!=NULL)
		{
			if(strcmp(temp->name,name)==0)
			{
				printf("\n书名为<<%s>>的书存在!",name);
				break;
			}
			else
				temp=temp->next;
		}
	}
	return temp;
}

//按书作者查找
void S_author(book*head)
{
	char author[30];
	book*temp=head->next;
	if(temp==NULL)
		printf("\n书库中还没有书籍,请入库!");
	else
	{
		printf("\n请输入您要查找的作者名:");
		scanf("%s",author);
		while(temp!=NULL)
		{
			if(strcmp(author,temp->author)==0)
				showB(temp);
			temp=temp->next;
		}
	}
	getch();
}

keynode*initindex(book*head)//初始化建立索引表
{
	int i;
	book*temp=head->next;
	keynode *tempkey,*p;
	printf("\n初始化索引表开始...");
	keynode *keyhead=(keynode*)malloc(sizeof(keynode));
	keyhead->next=NULL;
	tempkey=keyhead->next;
	if(temp!=NULL)
	{
		p=(keynode*)malloc(sizeof(keynode));//给索引节点分配空间
		p->key=temp->number;
		p->adress=temp;
		p->next=NULL;//数据赋完 剩下插入
		keyhead->next=p;
		tempkey=keyhead->next;
	}
	while(temp!=NULL)
	{
		for(i=0;i<5&&temp->next!=NULL;i++)
		{
			temp=temp->next;
		}
		if(i<4)
			return keyhead;
		else
		{
			p=(keynode*)malloc(sizeof(keynode));
			p->key=temp->number;
			p->adress=temp;
			p->next=NULL;
			tempkey->next=p;
			tempkey=tempkey->next;
		}
	}
	getch();
	return keyhead;
}


void delkey(keynode*keyhead)
{
	keynode*temp;
	if(keyhead->next==NULL)
	{
		free(keyhead);
	}
	else
	{
		while(keyhead!=NULL)
		{
			temp=keyhead;
			keyhead=keyhead->next;
			free(temp);
		}
	}
	printf("\n索引表清空!");
}

//按索引表查找
book*S_number(long num,book*bhead)
{
	int i;
	book*p;
	keynode *keyhead=initindex(bhead);
	keynode*tempkey=keyhead->next;
	if(tempkey==NULL)
	{
		printf("\n书库没有记录,请输入!");
		delkey(keyhead);
		return NULL;
	}
	else
	{

		while(tempkey->next!=NULL)
		{
			if(tempkey->key<num&&tempkey->next->key<num)
				tempkey=tempkey->next;
			else break;
		}
		if(tempkey==NULL)
		{
			printf("没有找到编号为%d的书籍!",num);
			delkey(keyhead);
			return NULL;
		}
		else
		{
			p=tempkey->adress;
			for(i=0;i<5&&p!=NULL;i++)
			{
				if(p->number==num)		
				{
//					showB(p);
					delkey(keyhead);
					return p;
				}
				else
					p=p->next;
			}
			delkey(keyhead);
			return NULL;
		}
	}
}
					

