#include "modifyPersons.h"
#include "structs.h"
#include "iostream"
using namespace std;
#include "string"
#include "isExist.h"


void modifyPerson(adressbooks * adbs)  // pointer as a input, then any function inside wont use
// pointer anymore., otherwise it will be ptr **
{
	cout << "please input the one you want modify: " << endl;
	string name;
	cin >> name;
	int ret = isExist(adbs, name); // as a function call internally by a function taht uses the parameters of an external function
	//the arguments of external functions are of the pointer type, so internal functions are called with their function name 
	if (ret != -1)
	{
		string name;
		cout << "please input name: " << endl;
		cin >> name;
		adbs->MaxPerson[ret].P_Name = name;

		// sex
		cout << "please input the sex: " << endl;
		cout << "1 <===> male || female <===> 2" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				adbs->MaxPerson[ret].P_sex = sex;
				break;
			}
			cout << "input error, please input again!" << endl;
		}

		// age
		cout << "please input the age" << endl;
		int age = 0;
		cin >> age;
		adbs->MaxPerson[ret].P_age = age;

		// number
		cout << "please input contact number" << endl;
		string number;
		cin >> number;
		adbs->MaxPerson[ret].P_number = number;

		// adress
		cout << "please input adress" << endl;
		string adress;
		cin >> adress;
		adbs->MaxPerson[ret].P_address = adress;

		cout << "modify successfully" << endl;
	}
	else
	{
		cout << "no this person" << endl;
	}
	system("pause");
	system("cls");

}