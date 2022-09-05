#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person(int age)
	{
		this->m_age = age; // 加上this 指针之后，会发现如果形参和成员变量是相同的表达的时候，this指针下的变量
		                   //会和成员变量同时高亮
	}

	Person& personAddperson(Person &p)  // return void， 用类引用方式接收返回值
	{
		this->m_age += p.m_age;
		return *this; // 返回*this
	}
	//正常的对于成员变量的编码规范是，对于成员变量应该用：m_a, m_b... 用m_来进行区分它和形参（比如构造函数中的形参）
	int m_age;

	
	
};


void test01()
{   
	Person p(18);
	cout << "the age is" <<p.m_age<< endl;
}


void test02()
{
	Person p1(1);
	Person p2(3);
	/*
	如果我想不停的调用函数来实现不停的加加，根据我的需求来进行，那么这时候就要求成员函数进行一定的调整。
	1， 如果成员函数是void类型，那么其不存在返回值，那么自然不能进行持续的 . 访问进行不断的加加
	2.  返回改成*this，这个时候将返回类型从void改成 Person &(值的引用)，那么它就可以不断的加加通过 . 的形式,而且
	    对象一直都是p2
	3， 这种无限++ 的方式就是叫做链式方法，无限追加类似于 <<
	4.  如果将返回类型改成值类型: 将void 改成 Person： 它每次会创建新的对象p2-> p1 ->....，在调用 . 的时候
	*/
	p2.personAddperson(p1).personAddperson(p1);
	cout << "p2 age is:" << p2.m_age << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}















































