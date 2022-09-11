#pragma once
#include "manager.h"
#include <iostream>
using namespace std;
#include "worker.h"

class Boss : public Worker
{

public:
	Boss(int id, string name, int mID);
	virtual void showInfo();


	virtual string getDepartName();

};