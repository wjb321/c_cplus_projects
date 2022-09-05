#include "iostream"
using namespace std;
#include "string"

class Person{

public:

	void showClassName()
	{
		cout << "this is a person class" << endl;
	}

	void showPersonage()
	{  
		if (this == NULL)
		{
			return; 
		}
		cout << "age = " << this->m_age << endl;
	}
 int m_age;
};


void test01()
{   
	Person * p  = NULL;
	//p->showClassName();
	p->showPersonage();
	
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































