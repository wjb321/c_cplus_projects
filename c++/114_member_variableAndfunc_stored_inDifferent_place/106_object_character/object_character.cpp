#include "iostream"
using namespace std;
#include "string"

class Person{

	int m_a;
	static int m_b; // 不属于类的对象上，因为添加这个静态变量后，整个类的大小
	//是不变的，但是当添加别的整型变量比如 int m_c, 这个类的大小就会再加4
	void func(){}//非静态成员函数，不属于类的对象上
	static void func1(){} // 静态成员函数，不属于类的对象上
};


void test01()
{   
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
}


void test02()
{
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































