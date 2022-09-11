#include "manager.h"

Manager::Manager(int id, string name, int mID)
{
	this->m_id = id;
	this->m_depID = mID;
	this->m_name = name;
}

void Manager::showInfo()
{
	cout << "manager ID is " << this->m_id
		<< "\tmanager name: " << this->m_name
		<< "\tmanager position: " << this->getDepartName()
		<< "\tmanager duty: finish the job from manager" << endl;
}


string Manager::getDepartName()
{
	return string("Manager");
}