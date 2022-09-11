#include "Boss.h"

Boss::Boss(int id, string name, int mID)
{
	this->m_id = id;
	this->m_depID = mID;
	this->m_name = name;
}

void Boss::showInfo()
{
	cout << "Boss ID is " << this->m_id
		<< "\tBoss name: " << this->m_name
		<< "\tBoss position: " << this->getDepartName()
		<< "\tBoss duty: manage the whole company" << endl;
}


string Boss::getDepartName()
{
	return string("Boss");
}