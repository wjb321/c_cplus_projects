#include "iostream"
using namespace std;
#include "string"
#include "structs.h"
#include "string"
#include "isExist.h"
#include "modifyPersons.h"
#include "deletePersons.h"
#include "findPersons.h"
#define MAX 1000
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
//	int P_Size =0 ;  // this should be initialized
//};

void addPerson(adressbooks * adbs )
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
void showinterface()
{   
	cout << "**********************" << endl;
	cout << "***** 1. add     *****" << endl;
	cout << "***** 2. show    *****" << endl;
	cout << "***** 3. delete  *****" << endl;
	cout << "***** 4. search  *****" << endl;
	cout << "***** 5. modify  *****" << endl;
	cout << "***** 6. empty   *****" << endl;
	cout << "***** 0. exit    *****" << endl;
	cout << "**********************" << endl;

}

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
			cout << "adress : "  << adbs->MaxPerson[i].P_address << endl;
		}
	}
	system("pause");
	system("cls");
}


//void deletePerson(adressbooks *adbs)
//{
//	cout << "please input the person you want to delete" << endl;
//	string name;
//	cin >> name;
//	int state = isExist(adbs, name);
//	if(state != -1)
//	{
//		for (int i = state; i < adbs->P_Size; i++)
//		{
//			adbs->MaxPerson[i] = adbs->MaxPerson[i + 1];
//		}
//		adbs->P_Size--;
//		cout << "successfully deleted" << endl;
//	}
//	else
//	{   
//
//		cout << "no this person" << endl;
//	}
//	system("pause");
//	system("cls");
//
//}



//void modifyPerson(adressbooks * adbs)  // pointer as a input, then any function inside wont use
//                                        // pointer anymore., otherwise it will be ptr **
//{
//	cout << "please input the one you want modify: " << endl;
//	string name;
//	cin >> name;
//	int ret = isExist(adbs, name); // as a function call internally by a function taht uses the parameters of an external function
//	                               //the arguments of external functions are of the pointer type, so internal functions are called with their function name 
//	if (ret != -1)
//	{
//		string name;
//		cout << "please input name: " << endl;
//		cin >> name;
//		adbs->MaxPerson[ret].P_Name = name;
//
//		// sex
//		cout << "please input the sex: " << endl;
//		cout << "1 <===> male || female <===> 2" << endl;
//		int sex = 0;
//		while (true)
//		{
//			cin >> sex;
//			if (sex == 1 || sex == 2)
//			{
//				adbs->MaxPerson[ret].P_sex = sex;
//				break;
//			}
//			cout << "input error, please input again!" << endl;
//		}
//		
//		// age
//		cout << "please input the age" << endl;
//		int age = 0;
//		cin >> age;
//		adbs->MaxPerson[ret].P_age = age;
//
//		// number
//		cout << "please input contact number" << endl;
//		string number;
//		cin >> number;
//		adbs->MaxPerson[ret].P_number = number;
//
//		// adress
//		cout << "please input adress" << endl;
//		string adress;
//		cin >> adress;
//		adbs->MaxPerson[ret].P_address = adress;
//
//		cout << "modify successfully" << endl;
//	}
//	else
//	{
//		cout << "no this person" << endl;
//	}
//	system("pause");
//	system("cls");
//
//}
void clearPersonlist(adressbooks * adbs)
{
	adbs->P_Size = 0;
	cout << "now the adress book is empty" << endl;
	system("pause");
	system("cls");
}
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