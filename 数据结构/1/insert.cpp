#include "library.h"

void insert(book*bhead)//入库
{
	style();
	long t;
	book*temp1,*temp,*temp2;
	temp1=bhead->next;
	printf("\n                        ┏━━━━━━━━━━┓                        ");
	printf("\n█━━━━━━━━━━━┫ 欢迎使用  入库系统 ┣━━━━━━━━━━━█");
	printf("\n                        ┗━━━━━━━━━━┛                        ");
	while(1)
	{
		printf("\n请输入您给定书的编号(6位以内的正整数):");
		scanf("%d",&t);
		if(t<=0||t>999999)
		{
			printf("\n您的编号不在处理范围(1~999999)之内!");
			fflush(stdin);
			continue;
		}
		else
		{
			temp2=S_number(t,bhead);
			if(temp2==NULL)
			{
				break;
			}
			else
			{
				temp2->total++;
				temp2->exist++;
				printf("\n编号为%d的书已存在，入库成功!",t);
				return;
			}
		}
	}
	temp=(book*)malloc(sizeof(book));
	temp->number=t;
	printf("\n请输入书名:");
	scanf("%s",temp->name);
	printf("\n请输入本书作者:");
	scanf("%s",temp->author);
	printf("\n请输入本书出版社:");
	scanf("%s",temp->press);
	printf("\n请输入本书出版时间:");
	scanf("%d",&temp->presstime);
	temp->next=NULL;
	temp->total=1;
	temp->exist=1;
	if(bhead->next==NULL)
		bhead->next=temp;
	else
	{
		while(temp1->next!=NULL&&temp1->number<temp->number)//找到合适的位置,插入书籍信息
			temp1=temp1->next;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	printf("\n                        ┏━━━━━━━━━━┓                        ");
	printf("\n█━━━━━━━━━━━┫      入库成功      ┣━━━━━━━━━━━█");
	printf("\n                        ┗━━━━━━━━━━┛                        ");
}


