#include "iostream"
#include <string>
using namespace std;

// class template as the paramete of func
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	T1 m_name;
	T2 m_age;
	void showPerson()
	{
		cout << "name: " << this->m_name << " age " << this->m_age << endl;
	}
};

 
// 1. specify the function type(most frequently used)
void printPerson1(Person<string, int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("jack", 100);
	printPerson1(p);
}


//2. Parametric templating
template <class T1, class T2>
void printPerson2(Person<T1, T2>&p)  // make the parameters into template
{
	p.showPerson();
	cout << "t1 type is: " << typeid(T1).name()<< endl;
	cout << "t2 type is: " << typeid(T2).name() << endl;

} 

void test02()
{
	Person<string, int>p("liu", 20);
	printPerson2(p);
}


//3. templating all the class
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	cout << "t type is: " << typeid(T).name() << endl;
	//cout << "t2 type is: " << typeid(T2).name() << endl;
}

void test03()
{
	Person<string, int>p("wamg", 4);
	printPerson3(p);
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}















































