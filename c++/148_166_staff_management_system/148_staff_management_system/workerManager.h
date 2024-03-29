#pragma once  // prevent the head file inclusion
#include <iostream>
#include "worker.h"
using namespace std;
#include <fstream>

#define EMPLOYEEBOOK "employBooks.txt"
class workermanager
{
public:
	workermanager();

	void show_menu();
	void Exitsystem();
	void add_Emp();
	void infoSave();
	
	// get the num of people in file
	int get_EmpNum();

	void init_Emp();
	
	// show staff function
	void show_Emp();

	// delete the employee
	void Del_Emp();

	void Mod_Emp();
	int IsExist(int id); // if the employees are not exist, then no need for deleting 

	void Find_Emp();

	void Sort_Emp();

	void Clean_File();
	//note number of workers
	int m_EmpNum;
	Worker ** m_EmpArray;
	int m_fileEmpty;

	~workermanager();
};