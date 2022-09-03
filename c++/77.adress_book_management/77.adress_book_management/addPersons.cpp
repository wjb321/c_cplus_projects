#include "addPersons.h"
#include "string"
#include "isExist.h"
#include "iostream"

void addPerson(adressbooks * adbs)
{
	if (adbs->P_Size == MAX) // pointer uses
	{
		cout << "boucher is full" << endl;
		return;
	}
	else
	{
		string name;
		cout << "please input your name: " << endl;
		cin >> name;
		adbs->MaxPerson[adbs->P_Size].P_Name = name;
		cout << "please input your sex: " << endl;
		cout << "1 => men || women <=2 => " << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				adbs->MaxPerson[adbs->P_Size].P_sex = sex;  // video 77

			}
			else cout << "error! please input number --- 1 or 2." << endl;
			cout << "please input the ages" << endl;
			int age = 0;
			cin >> age;
			adbs->MaxPerson[adbs->P_Size].P_age = age;


			cout << "update the phone number: " << endl;
			string number;
			cin >> number;
			adbs->MaxPerson[adbs->P_Size].P_number = number;


			cout << "update the living adress: " << endl;
			string adress;
			cin >> adress;
			adbs->MaxPerson[adbs->P_Size].P_address = adress;

			adbs->P_Size++;
			cout << "successfully add!" << endl;
			system("pause");
			system("cls");
			break;
		}




	}
}