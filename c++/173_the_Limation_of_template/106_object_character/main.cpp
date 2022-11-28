#include "iostream"
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string  m_name;
	int m_age;
};
template<class T>
bool myCompare(T &a, T &b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// use the materilized verion to implement the code, specifically for the calling
template<> bool myCompare(Person &p1, Person &p2)
{   
	cout << "this is the function below" << endl;
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10, b = 1;
	myCompare(a, b);
}


void test02()
{
	Person p1("tom", 10);
	Person p2("jack", 1);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 = p2" << endl;
	}
	else
	{
		cout << "p1 != p2 << endl";
	}
}


//the member function create time
//create when calling
class  Person1
{
public:
	void showPerson1()
	{
		cout << "show person 1" << endl;
	}
};

class  Person2
{
public:
	void showPerson2()
	{
		cout << "show person 1" << endl;
	}
};

template <class T>
class Myclass
{
public:
	T obj;
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};

void test03()
{   
	// the member function is created when calling
	Myclass<Person1> m; // this is the member function of person1
	m.func1();
	//m.func2(); // so func2 can not call this 
}

  
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}















































