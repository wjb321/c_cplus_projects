#pragma once
#include "manager.h"
#include <iostream>
using namespace std;
#include "worker.h"

class Manager : public Worker
{

public:
	Manager(int id, string name, int mID);
	virtual void showInfo();


	virtual string getDepartName();

};