
#include "library.h"

book* Bload()//书籍链表读取
{
	FILE *p;
	book*Bhead=(book*)malloc(sizeof(book));
	book*temp,*temp1;
	Bhead->next=NULL;
	if((p=fopen("book.txt","r"))==NULL)
	{
		printf("\n打开文件book.txt失败,请检查...");
		return NULL;
	}
	else
	{
		fgetc(p);
		if(!feof(p))//未到文件尾
		{
			printf("\n非空");
			rewind(p);//返回文件头
			temp=(book*)malloc(sizeof(book));
			fscanf(p,"%14d%12s%18s%8d%14s%4d%4d\n",&temp->number,temp->name,temp->press,&temp->presstime,temp->author,&temp->total,&temp->exist);
			temp->next=NULL;
			Bhead->next=temp;
		}
		while(!feof(p))
		{
			temp1=(book*)malloc(sizeof(book));
			fscanf(p,"%14d%12s%14s%8d%18s%4d%4d\n",&temp1->number,temp1->name,temp1->press,&temp1->presstime,temp1->author,&temp1->total,&temp1->exist);
			temp1->next=NULL;
			temp->next=temp1;
			temp=temp->next;
		}
		printf("\n书籍信息读取成功...");
		return Bhead;
	}
}



void Bsave(book*Bhead)//书籍信息链表写入
{
	FILE *p;
	book*temp=Bhead->next;
	if(temp==NULL)
		return;
	else
	{
		if((p=fopen("book.txt","w"))==NULL)
			printf("\n打开book.txt失败...");
		while(temp!=NULL)
		{
//			showB(temp);
			fprintf(p,"%14d%12s%14s%8d%14s%4d%4d\n",temp->number,temp->name,temp->press,temp->presstime,temp->author,temp->total,temp->exist);
			temp=temp->next;
		}
		printf("\n存储书籍成功...");
	}
}







