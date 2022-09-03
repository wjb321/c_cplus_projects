#include "clearPersonslist.h"
#include "string"
#include "isExist.h"
#include "iostream"


void clearPersonlist(adressbooks * adbs)
{
	adbs->P_Size = 0;
	cout << "now the adress book is empty" << endl;
	system("pause");
	system("cls");
}