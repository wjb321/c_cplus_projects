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
			cout << "please input " << i + 1 << "th" << "new employee number" << endl;
			cin >> id;
			cout << "please input " << i + 1 << "th" << "new employee name" << endl;
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

		cout << "successfully add the " << addNum << "employees" << endl;
	}
	else
	{
		cout << "sorry, please input again" << endl;
	}
}

void workermanager::Exitsystem()
{
	cout << "welcome next time" << endl;
	system("pause");
}

workermanager::~workermanager()
{

}