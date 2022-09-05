#include "showPersonsList.h"
#include "string"
#include "isExist.h"
#include "iostream"

void showPersonList(adressbooks * adbs)
{
	if (adbs->P_Size == 0)
	{
		cout << "the list is still empty" << endl;
	}
	else
	{
		for (int i = 0; i < adbs->P_Size; i++)
		{
			cout << "name : " << adbs->MaxPerson[i].P_Name << "\t";
			cout << "sex : " << (adbs->MaxPerson[i].P_sex == 1 ? "male" : "female") << "\t";
			cout << "age : " << adbs->MaxPerson[i].P_age << "\t";
			cout << "phone : " << adbs->MaxPerson[i].P_number << "\t";
			cout << "adress : " << adbs->MaxPerson[i].P_address << endl;
		}
	}
	system("pause");
	system("cls");
}