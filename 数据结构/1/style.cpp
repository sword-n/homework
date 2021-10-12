#include "library.h"

void style()//风格函数
{
//	system("mode con cols=80 lines=300");
	system("color 0f");
	system("cls");
}





void menu2()
{
	style();
	char i;
	while(1)
	{
		printf("\n                        ┏━━━━━━━━┓                        ");
		printf("\n◢━━━━━━━━━━━┫ →图书馆菜单← ┣━━━━━━━━━━━◣");
		printf("\n┃                      ┗━━━━━━━━┛                      ┃");
		printf("\n┃                      ┏━━━━━━━━┓                      ┃");
		printf("\n┃                      ┃请选择您的操作: ┃                      ┃");
		printf("\n┃                      ┃                ┃                      ┃");
		printf("\n┃                      ┃ → 1﹑借书     ┃                      ┃");
		printf("\n┃                      ┃ → 2﹑还书     ┃                      ┃");
		printf("\n┃                      ┃ → 3﹑个人信息 ┃                      ┃");
		printf("\n┃                      ┃ → 4﹑返回上级 ┃                      ┃");
		printf("\n┃                      ┃ → 5﹑退出系统 ┃                      ┃");
        printf("\n┃                      ┃ → 6﹑入库     ┃                      ┃");
		printf("\n┃                      ┗━━━━━━━━┛                      ┃");
		printf("\n◥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◤\n");
		i=getch();
		switch(i)
		{
		case '1':borrow();break;
		case '2':;break;
		case '3':;break;
		case '4':menu2(bhead);break;
		case '5':Bsave(bhead);exit(0);
		case '6':insert(bhead);break;
		default:break;
		}
	}
}

long backtime()
{
	long t;
	time_t timep;
	struct tm *p;
	time(&timep); 
    p=localtime(&timep);
	t=(1900+p->tm_year)*10000+(1+p->tm_mon)*100+p->tm_mday;
	return t;
}
