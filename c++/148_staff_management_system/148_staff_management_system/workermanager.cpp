#include "workermanager.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"
#include "worker.h"

workermanager::workermanager()
{
	//initialize the attribution
	this->m_EmpNum = 0;

	this->m_EmpArray = NULL;

	ifstream ifs;
	//1. file does not exist
	ifs.open(EMPLOYEEBOOK, ios::in);
	if (!ifs.is_open())
	{
		cout << "file does not exist" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_fileEmpty = true;
		ifs.close();
		return;

	}

	//2. file exist, but it is empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "file is empty" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_fileEmpty = true;
		ifs.close();
		return;
	}

	//3. when file exist, and has some staff input
	int num = this->get_EmpNum();

	//here is the test code
	/*cout << "the employee num is:" << num << endl;
	this->m_EmpNum = num;*/
	// allocate spaces
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	//store the data into array
	this->init_Emp();
	
	//here are the test code
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "employee number: " << this->m_EmpArray[i]->m_id 
	//		<< " name: " << this->m_EmpArray[i]->m_name 
	//		<< " department ID " << this->m_EmpArray[i]->m_depID  << endl;;

	//}

}

int workermanager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(EMPLOYEEBOOK, ios::in);
	int id;
	string name;
	int dID;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		num++;
	}
	return num;
}

void workermanager::show_menu()
{
	cout << "**********************************************" << endl;
	cout << "***** welcome to staff management system *****" << endl;
	cout << "********     0. exit staff system     ********" << endl;
	cout << "********     1. add   new   staff     ********" << endl;
	cout << "********     2. show  new   staff     ********" << endl;
	cout << "********     3. delete quit staff     ********" << endl;
	cout << "********     4. modify staff info     ********" << endl;
	cout << "********     5. search staff info     ********" << endl;
	cout << "********     6. sort staffby  num     ********" << endl;
	cout << "********     7. clear all   docum     ********" << endl;
	cout << "**********************************************" << endl;
}

void workermanager::add_Emp()
{
	cout << "input the num of employees" << endl;
	int addNum = 0;
	cin >> addNum;
	
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		// new some spce
		Worker ** newSpace = new Worker *[newSize];

		//copy the old data to the new space
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//add new data
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelete;
			cout << "please input " << i + 1 << " th " << "new employee number" << endl;
			cin >> id;
			cout << "please input " << i + 1 << " th " << "new employee name" << endl;
			cin >> name;
			cout << "please selete the position " << endl;
			cout << "1. common worker" << endl;
			cout << "2. manager" << endl;
			cout << "3. boss" << endl;
			cin >> dSelete;

			Worker * worker = NULL;
			switch (dSelete)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//create worker duty, store in the array
			newSpace[this->m_EmpNum + i] = worker;
		}
		//release origin space
		delete[] this->m_EmpArray;
		
		//change new space point address
		this->m_EmpArray = newSpace;

		//update worker numbers
		this->m_EmpNum = newSize;

		//when the file is not empty, then the flag should be changed
		this->m_fileEmpty = false;
		//successfully added, then should be stored in the files, because if do not do so then 
		//when the system restarts, there is going to be nothing inside.

		cout << "successfully add the " << addNum << "employees" << endl;
		this->infoSave();
	}
	else
	{
		cout << "sorry, please input again" << endl;
	}
	system("pause");
	system("cls");
}

void workermanager::Exitsystem()
{
	cout << "welcome next time" << endl;
	system("pause");
}

void workermanager::infoSave()
{
	ofstream ofs;
	ofs.open(EMPLOYEEBOOK, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_depID << endl;
	}
	ofs.close();
}

void workermanager::init_Emp()
{
	ifstream ifs;
	ifs.open(EMPLOYEEBOOK, ios::in);
	int id;
	string name;
	int dID;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker * worker = NULL;
		if (dID == 1)
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else
		{
			worker = new Boss(id, name, dID);
		}
		this->m_EmpArray[index] = worker;
		index++;
		
	}
	ifs.close(); // close the file after  
}
void workermanager::show_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "the file is not exist or empty " << endl;

	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{   // use phorinorsm call function terminal
			this->m_EmpArray[i]->showInfo();
		}
	}
	//clear the screen
	system("pause");
	system("cls");
}

void workermanager::Del_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "file is empty or the records are empty" << endl;
	}
	else
	{
		cout << "delete the employees ID: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (id != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->infoSave();
			cout << "delete success! " << endl;
		}
		else
		{
			cout << "sorry, can not find this staff" << endl;
		}
	}
	system("pause");
	system("cls");
}

int workermanager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

workermanager::~workermanager()
{  
	// release the data in the stack
	// manually open and manually release
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}