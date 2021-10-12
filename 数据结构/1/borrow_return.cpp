#include"library.h"

//借阅
void borrow(book*Bhead)
{
	style();
	long num;
	int i;
	char t,k,name[30];
	book*Bbook;
	while(1)
	{
		printf("\n                        ┏━━━━━━━━━━┓                        ");
		printf("\n█━━━━━━━━━━━┫ 欢迎使用  借阅系统 ┣━━━━━━━━━━━█");
		printf("\n                        ┗━━━━━━━━━━┛                        ");
		printf("\n请输入您要查找借阅书籍的方式:");
		printf("\n                           1、按书号查找\n");
		printf("\n                           2、按作者查找\n");
		printf("\n                           3、按书名查找\n");
		printf("\n                           4、返回主菜单\n");
		t=getch();
		switch(t)
		{
		case '1':
		{
			printf("\n请输入您要查找的书籍编号:");
			scanf("%d",&num);
			if((Bbook=S_number(num,Bhead))!=NULL)
			{
				showB(Bbook);
				printf("\n请问你是否要借阅该书籍?Y/N");
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
			printf("\n请输如您要查找的书籍名:");
			scanf("%s",name);
			if((Bbook=S_name(Bhead,name))!=NULL)
			{
				showB(Bbook);
				printf("\n请问你是否要借阅该书籍?Y/N");
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
			printf("\n                       借阅成功!");
		}
		else
		   printf("\n该书没有库存,请借阅其他书籍!");

		printf("\n您要继续借阅书籍吗?Y/N");
		t=getch();
		if(t=='y'||t=='Y')
			continue;
		else
		break;
		}
	}
}



