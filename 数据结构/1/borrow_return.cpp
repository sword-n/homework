#include"library.h"

//����
void borrow(book*Bhead)
{
	style();
	long num;
	int i;
	char t,k,name[30];
	book*Bbook;
	while(1)
	{
		printf("\n                        ������������������������                        ");
		printf("\n�������������������������� ��ӭʹ��  ����ϵͳ �ǩ�����������������������");
		printf("\n                        ������������������������                        ");
		printf("\n��������Ҫ���ҽ����鼮�ķ�ʽ:");
		printf("\n                           1������Ų���\n");
		printf("\n                           2�������߲���\n");
		printf("\n                           3������������\n");
		printf("\n                           4���������˵�\n");
		t=getch();
		switch(t)
		{
		case '1':
		{
			printf("\n��������Ҫ���ҵ��鼮���:");
			scanf("%d",&num);
			if((Bbook=S_number(num,Bhead))!=NULL)
			{
				showB(Bbook);
				printf("\n�������Ƿ�Ҫ���ĸ��鼮?Y/N");
				k=getch();
				if(k=='Y'||k=='y')
					goto borrow;
				else
					break;
			}
			else
				break;
		}
		case '2':
		{
			S_author(Bhead);
			break;
		}
		case '3':
		{
			printf("\n��������Ҫ���ҵ��鼮��:");
			scanf("%s",name);
			if((Bbook=S_name(Bhead,name))!=NULL)
			{
				showB(Bbook);
				printf("\n�������Ƿ�Ҫ���ĸ��鼮?Y/N");
				k=getch();
				if(k=='Y'||k=='y')
					goto borrow;
				else
					break;
			}
			else
				continue;
			break;
		}
		default:
			return;

borrow:	if(Bbook!=NULL&&Bbook->exist>0)
		{
			Bbook->exist--;
			printf("\n                       ���ĳɹ�!");
		}
		else
		   printf("\n����û�п��,����������鼮!");

		printf("\n��Ҫ���������鼮��?Y/N");
		t=getch();
		if(t=='y'||t=='Y')
			continue;
		else
		break;
		}
	}
}



