
#include "library.h"

book* Bload()//�鼮�����ȡ
{
	FILE *p;
	book*Bhead=(book*)malloc(sizeof(book));
	book*temp,*temp1;
	Bhead->next=NULL;
	if((p=fopen("book.txt","r"))==NULL)
	{
		printf("\n���ļ�book.txtʧ��,����...");
		return NULL;
	}
	else
	{
		fgetc(p);
		if(!feof(p))//δ���ļ�β
		{
			printf("\n�ǿ�");
			rewind(p);//�����ļ�ͷ
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
		printf("\n�鼮��Ϣ��ȡ�ɹ�...");
		return Bhead;
	}
}



void Bsave(book*Bhead)//�鼮��Ϣ����д��
{
	FILE *p;
	book*temp=Bhead->next;
	if(temp==NULL)
		return;
	else
	{
		if((p=fopen("book.txt","w"))==NULL)
			printf("\n��book.txtʧ��...");
		while(temp!=NULL)
		{
//			showB(temp);
			fprintf(p,"%14d%12s%14s%8d%14s%4d%4d\n",temp->number,temp->name,temp->press,temp->presstime,temp->author,temp->total,temp->exist);
			temp=temp->next;
		}
		printf("\n�洢�鼮�ɹ�...");
	}
}







