#include "workermanager.h"

workermanager::workermanager()
{

}

void workermanager::show_menu()
{
	cout << "**********************************************" << endl;
	cout << "***** welcome to staff management system *****" << endl;
	cout << "********     1. exit staff system     ********" << endl;
	cout << "********     2. add   new   staff     ********" << endl;
	cout << "********     3. delete quit staff     ********" << endl;
	cout << "********     4. modify staff info     ********" << endl;
	cout << "********     5. search staff info     ********" << endl;
	cout << "********     6. sort staffby  num     ********" << endl;
	cout << "********     7. clear all   docum     ********" << endl;
	cout << "**********************************************" << endl;
}


void workermanager::Exitsystem()
{
	cout << "welcome next time" << endl;
	system("pause");
}

workermanager::~workermanager()
{

}