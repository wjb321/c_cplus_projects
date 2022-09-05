#include "iostream"
using namespace std;
#include "string"
#include "structs.h"
#include "string"
#include "isExist.h"
#include "modifyPersons.h"
#include "deletePersons.h"
#include "findPersons.h"
#include "addPersons.h"
#include "showInterface.h"
#include "showPersonsList.h"
#include "clearPersonslist.h"

int main()
{   
	adressbooks adbs;

	int MenuSelect = 0;

	while (1)
	{   
		showinterface();
		cin >> MenuSelect;
		switch (MenuSelect)
		{
		case 1:
			addPerson(&adbs);
			break;
		case 2:
			showPersonList(&adbs);
			break;
		case 3:
		   {
		    cout << "please input delete person: " << endl;
			string name;
			cin >> name;
		    if (isExist(&adbs, name) == -1)
		     {
				cout << "sorry, no this person" << endl;
			  }
			else
			{
				cout << "find this person" << endl;
				deletePerson(&adbs);
			}
		   }
        break;
		case 4:
			findPerson(&adbs);
	        break;
		case 5:
			modifyPerson(&adbs);
			break;
		case 6:
			clearPersonlist(&adbs);
			break;
		case 0:
			cout << "system exit" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}