#include "iostream"
#include "string"
using namespace std;
class Base
{
public:
	virtual void func() = 0;  // pure virtual function
	//只要有一个纯虚函数，那么这个类就是抽象类
	//抽象类的特点：
	//1. 无法实例化对象 Base b;
	//2. 必须要重写父类中的纯虚函数，否则也属于抽象类

	float m_Num1;
	float m_Num2;
};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func is called" << endl;
	}
};

void test01()
{   
	//子类继承
	Son s;
	s.func();

	//多态表达
	//通过不同的父类指针调用多种不同的接口，这个接口是通过过new一个对应的继承类，然后
	//访问对应继承条件下的函数
	Base * base = new Son;
	base->func();
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















































