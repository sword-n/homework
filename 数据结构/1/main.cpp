#include"library.h"
int main()
{
	book*Bhead;

	Bhead=Bload();


	Bsave(Bhead);
	getch();
	return 0;
}
