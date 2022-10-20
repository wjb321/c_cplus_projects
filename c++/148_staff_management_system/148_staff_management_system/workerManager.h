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
	//note number of workers
	int m_EmpNum;
	Worker ** m_EmpArray;
	int m_fileEmpty;

	~workermanager();
};