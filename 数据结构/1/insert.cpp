#include "library.h"

void insert(book*bhead)//���
{
	style();
	long t;
	book*temp1,*temp,*temp2;
	temp1=bhead->next;
	printf("\n                        ������������������������                        ");
	printf("\n�������������������������� ��ӭʹ��  ���ϵͳ �ǩ�����������������������");
	printf("\n                        ������������������������                        ");
	while(1)
	{
		printf("\n��������������ı��(6λ���ڵ�������):");
		scanf("%d",&t);
		if(t<=0||t>999999)
		{
			printf("\n���ı�Ų��ڴ���Χ(1~999999)֮��!");
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
				printf("\n���Ϊ%d�����Ѵ��ڣ����ɹ�!",t);
				return;
			}
		}
	}
	temp=(book*)malloc(sizeof(book));
	temp->number=t;
	printf("\n����������:");
	scanf("%s",temp->name);
	printf("\n�����뱾������:");
	scanf("%s",temp->author);
	printf("\n�����뱾�������:");
	scanf("%s",temp->press);
	printf("\n�����뱾�����ʱ��:");
	scanf("%d",&temp->presstime);
	temp->next=NULL;
	temp->total=1;
	temp->exist=1;
	if(bhead->next==NULL)
		bhead->next=temp;
	else
	{
		while(temp1->next!=NULL&&temp1->number<temp->number)//�ҵ����ʵ�λ��,�����鼮��Ϣ
			temp1=temp1->next;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	printf("\n                        ������������������������                        ");
	printf("\n��������������������������      ���ɹ�      �ǩ�����������������������");
	printf("\n                        ������������������������                        ");
}


