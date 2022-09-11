#include <iostream>
using namespace std;
#include "workermanager.h"
#include "worker.h"
#include "employee.h"
#include "Boss.h"
int main()
{   
	Worker * worker = NULL;
	worker = new Employee(1, "wang", 123);
	worker->showInfo();
	delete worker;

	worker = new Manager(1, "xujiao", 321);
	worker->showInfo();
	delete worker;

	worker= new Boss(2, "who knows", 32112);
	worker->showInfo();
	workermanager wm;

	/*int decision = 0;

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
	}*/
	system("pause");
	return 0;
}