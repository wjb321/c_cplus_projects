#include "employee.h"


Employee::Employee(int id, string name, int depID)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depID = depID;

}
void Employee::showInfo()
{
	cout << "staff        ID:" << this->m_id
		<< "\tstaff     name: " << this->m_name
		<< "\tstaff position: " << this->getDepartName()
		<< "\tposition  duty: finish the task" << endl;
}

string  Employee:: getDepartName()
{
	return string("staff");
}