#include "library.h"

void style()//�����
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
		printf("\n                        ��������������������                        ");
		printf("\n�������������������������� ��ͼ��ݲ˵��� �ǩ�����������������������");
		printf("\n��                      ��������������������                      ��");
		printf("\n��                      ��������������������                      ��");
		printf("\n��                      ����ѡ�����Ĳ���: ��                      ��");
		printf("\n��                      ��                ��                      ��");
		printf("\n��                      �� �� 1�p����     ��                      ��");
		printf("\n��                      �� �� 2�p����     ��                      ��");
		printf("\n��                      �� �� 3�p������Ϣ ��                      ��");
		printf("\n��                      �� �� 4�p�����ϼ� ��                      ��");
		printf("\n��                      �� �� 5�p�˳�ϵͳ ��                      ��");
        printf("\n��                      �� �� 6�p���     ��                      ��");
		printf("\n��                      ��������������������                      ��");
		printf("\n��������������������������������������������������������������������\n");
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
