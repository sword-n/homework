#include"library.h"



void showB(book*p)
{
	printf("\n┌────┬──────┬───────┬────┬───────┬──┬──┐");
	printf("\n│书本编号│  书籍名称  │  出版社名称  │出版时间│   作者       │共计│可借│");
	printf("\n├────┼──────┼───────┼────┼───────┼──┼──┤");
	printf("\n│%8d│%12s│%14s│%8d│%14s│%4d│%4d│",p->number,p->name,p->press,p->presstime,p->author,p->total,p->exist);
	printf("\n└────┴──────┴───────┴────┴───────┴──┴──┘\n");
}


