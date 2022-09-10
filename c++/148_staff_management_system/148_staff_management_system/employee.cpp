#include "employee.h"


Employee::Employee(int id, string name, int depID)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depID = depID;

}
void Employee::showInfo()
{
	cout << "staff ID is " << this->m_id
		<< "\t staff name: " << this->m_name
		<< "\t staff position: " << this->getDepartName()
		<< "\t position duty: finish the task" << endl;
}

string  Employee:: getDepartName()
{
	return string("staff");
}