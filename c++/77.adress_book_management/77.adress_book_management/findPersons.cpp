#include "findPersons.h"


#include <string>
#include "isExist.h"


//struct Person{
//
//	string P_Name;
//	int P_sex = 0;
//	int P_age;
//	string P_number;
//	string P_address;
//};
//
//struct adressbooks
//{
//	struct Person MaxPerson[MAX];
//	int P_Size = 0;  // this should be initialized
//};

void findPerson(adressbooks *adbs)
{
	cout << "please input the people that you looking for" << endl;
	string name;
	cin >> name;
	int ret = isExist(adbs, name);
	if (ret != 1)
	{
		cout << "name : " << adbs->MaxPerson[ret].P_Name << "\t";
		cout << "sex : " << (adbs->MaxPerson[ret].P_sex == 1 ? "male" : "female") << "\t";
		cout << "age : " << adbs->MaxPerson[ret].P_age << "\t";
		cout << "phone : " << adbs->MaxPerson[ret].P_number << "\t";
		cout << "adress : " << adbs->MaxPerson[ret].P_address << endl;
	}
	else
	{
		cout << "no this person" << endl;
	}

	system("pause");
	system("cls");

}