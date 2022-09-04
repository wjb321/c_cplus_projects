#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person(){}
	static void func()
	{
		cout << "static void function" << endl;
		/*
		非静态成员函数因为没有办法区分这个m_C 属于谁，所以会报错
		*/
		//m_C = 233;  // 非静态成员，静态成员函数无法访问
		m_A = 170; // 静态函数更改静态成员变量
	}

	static int m_A;
	int m_C;
	//int m_B;
private:
	static int m_B;
	static void func2()
	{
		cout << "static void func2 calling" << endl;
	}


};

int Person::m_A = 0; //必须在类外对静态成员函数进行初始化
int Person::m_B = 0; //必须在类外对静态成员函数进行初始化


void test01()
{   
	Person p;
	cout << p.m_A << endl;
    p.func();

	Person p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;

	Person::func(); // double colons calling function with class name
	//Person::func2();  // class person can not call private func2()
}


void test02()
{
	//通过对象进行访问
	Person p;
	cout << p.m_A << endl;
	// 通过类名进行访问
	cout << Person::m_A << endl; // 静态成员变量可以通过类名进行访问
	//cout << Person::m_B << endl; // 静态成员变量可以通过类名进行访问

}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































