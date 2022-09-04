#include "iostream"
using namespace std;
#include "string"


class Phone {

public:
	Phone(string brand)
	{
		cout << "this is phone constructor " << endl;
		m_brand = brand;
	}
	string m_brand;
};


class Person{

public:

	//1. 初始化列表比较死板
	Person(string name, string pname) : m_Name(name), m_phone(pname)
	{
		cout << "this is person constructor" << endl;
	}

	string m_Name;
	Phone m_phone; // 这个类作为person 类的对象成员
};

void test01()
{   

	//Person p
	Person p1(" zhang ", " iphone12") ;
	cout << p1.m_Name << " holds " << p1.m_phone.m_brand << endl;
	//cout << "constructor function age is : " << p1.M_A << " the height is: " << p1.M_B << " the height is: " << p1.M_C<< endl;  // pointer should have *
	//拷贝构造函数只是简单的将相应的对象进行赋值拷贝
	//Person p2(p1);  // compiler supplies shallow copy in copy constructor function

	//cout << "copy constructor function age is: " << p2.M_age << " the height is:" << *p2.M_height << endl;

}

//void test02()
//{
//	Person p(0);
//	//Person p2(p);
//	cout << "p2 age is: " << p.M_age << endl;
//}

int main()
{
	test01();
	//test02();
	/*test03();*/
	/*Person p;*/
	system("pause");
	return 0;
}















































