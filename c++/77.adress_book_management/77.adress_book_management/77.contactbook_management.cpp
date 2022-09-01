#include "iostream"
using namespace std;
#include "string"
#define MAX 1000
struct Person{

	string P_Name;
	int P_sex = 0;
	int P_age;
	string P_number;
	string P_address;
};

struct adressbooks
{
	struct Person MaxPerson[MAX];
	int P_Size =0 ;  // this should be initialized
};

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

int isExist(adressbooks *adbs, string name)
{
	for (int i = 0; i < adbs->P_Size; i++)
	{
		if (adbs->MaxPerson[i].P_Name == name)
		{
			return i; // get the location of the name
		}
	}
	return -1;
}

void deletePerson(adressbooks *adbs)
{
	cout << "please input the person you want to delete" << endl;
	string name;
	cin >> name;
	int state = isExist(adbs, name);
	if(state != -1)
	{

	}
	else
	{
		cout << "no this person" << endl;
	}
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
			}
		   }
        break;
		case 4:
			break;
		case 5:
			break;
		case 6:
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