#include "iostream"
#include "string"
using namespace std;


void myprint(int a ,int b)
{
	cout << "call the common function" << endl;
}

template <class T>
void myprint(T a, T b)
{
	cout << "the template that is called" << endl;
}


template <class T>
void myprint(T a, T b, T c)
{
	cout << "the template and it is a overload function" << endl;
}
//common function
int myadd01(int a, int b)
{
	return a + b;
}

template <class T>  // template can not automatic implicit change char into int
T myadd02(T a, T b)
{
	return a + b;
}
void test01()
{   
	int a = 7, b = 5;
	char c = 'o'; // implicit change the char to int by ascii
	char d = 'k';
	/*
	the 2 functions have the same name(function overloading) while one is the template and another one is the 
	common function, if there is no declaration then it should call the common function first
	*/
	myprint(a,b);
	myprint(c, d); // call template cause common function para is integer, template is easier
	myprint<>(a, b); // forcly call template function
	myprint<>(a, b, 12); // function overloading
	cout << myadd01(a, c) << endl;
}

//test int array
void test02()
{
	int a = 7, b = 5;
	char c = 'o'; 
	//cout << myadd02(a, c) << endl; // can not change it implicitly
	cout << myadd02<int>(a, c) << endl; // can change it implicitly, cause it explicitly
	//show the data type: int
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































