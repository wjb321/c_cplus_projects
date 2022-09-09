#include <iostream>
using namespace std;
#include "workermanager.h"
int main()
{   
	//
	workermanager wm;

	int decision = 0;

	while (true)
	{
		wm.show_menu();
		cout << "please input your selection: " << endl;
		cin >> decision;

		switch (decision)
		{
		case 0:
			wm.Exitsystem();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}