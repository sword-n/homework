#include"library.h"

//������������
book*S_name(book*head,char name[])
{
	book*temp=head->next;
	if(temp==NULL)
		printf("\n����л�û���鼮,�����!");
	else
	{
		while(temp!=NULL)
		{
			if(strcmp(temp->name,name)==0)
			{
				printf("\n����Ϊ<<%s>>�������!",name);
				break;
			}
			else
				temp=temp->next;
		}
	}
	return temp;
}

//�������߲���
void S_author(book*head)
{
	char author[30];
	book*temp=head->next;
	if(temp==NULL)
		printf("\n����л�û���鼮,�����!");
	else
	{
		printf("\n��������Ҫ���ҵ�������:");
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

keynode*initindex(book*head)//��ʼ������������
{
	int i;
	book*temp=head->next;
	keynode *tempkey,*p;
	printf("\n��ʼ��������ʼ...");
	keynode *keyhead=(keynode*)malloc(sizeof(keynode));
	keyhead->next=NULL;
	tempkey=keyhead->next;
	if(temp!=NULL)
	{
		p=(keynode*)malloc(sizeof(keynode));//�������ڵ����ռ�
		p->key=temp->number;
		p->adress=temp;
		p->next=NULL;//���ݸ��� ʣ�²���
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
	printf("\n���������!");
}

//�����������
book*S_number(long num,book*bhead)
{
	int i;
	book*p;
	keynode *keyhead=initindex(bhead);
	keynode*tempkey=keyhead->next;
	if(tempkey==NULL)
	{
		printf("\n���û�м�¼,������!");
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
			printf("û���ҵ����Ϊ%d���鼮!",num);
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
					

