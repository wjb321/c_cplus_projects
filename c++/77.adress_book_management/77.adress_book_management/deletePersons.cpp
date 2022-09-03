#include "deletePersons.h"
#include "structs.h"
#include "iostream"
using namespace std;
#include "string"
#include "isExist.h"

void deletePerson(adressbooks *adbs)
{
	cout << "please input the person you want to delete" << endl;
	string name;
	cin >> name;
	int state = isExist(adbs, name);
	if (state != -1)
	{
		for (int i = state; i < adbs->P_Size; i++)
		{
			adbs->MaxPerson[i] = adbs->MaxPerson[i + 1];
		}
		adbs->P_Size--;
		cout << "successfully deleted" << endl;
	}
	else
	{

		cout << "no this person" << endl;
	}
	system("pause");
	system("cls");

}