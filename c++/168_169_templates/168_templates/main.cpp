#include <iostream>
using namespace std;
//question:
//there are lots of different data types, not good to 
//write different function when the difference is only
//the data type
void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void swapDouble(double &a, double &b)
{
	double temp = a;

	a = b;
	b = temp;
}

//template<typename T>// typename can be replaced with class
template<class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	cout << "here is template method " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
template<class T>
void func()
{
	cout << "execuate func()" << endl;
}

void test01()
{
	int a = 100;
	int b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c); // wrong, the type is not same
}

void test02()
{
	//func(); // error, cause func has no any info to define T in template func(), func() is a template
	func<int>(); // correct, define the func type then the template can be used.
}

int main()
{
	int a = 10;
	int b = 20;
	double e = 10.5;
	double f = 20.8;
	swapInt(a, b);
	int c = 10;
	int d = 20;
	//1. automatic type derivation
	mySwap(c, d);

	//2. show the specific types
	mySwap<double>(e, f);

	test01();
	test02();
}