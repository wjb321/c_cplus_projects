#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{cout << "default constructor calling " << endl;}

	Person(int age )  //parameter Constuctor. 
	{  
		M_age = age;
		cout << "reference constructor " << endl;
    }
    
	// 拷贝构造函数
    Person(const Person &p) // const 保证被拷贝的变量不被改变， &代表进行引用拷贝
	{   
		cout << "copy constructor " << endl;
		M_age = p.M_age;  // 将传入的属性全部复制到此对应的类身上
	}

	~Person()  //dedestructor
	{
		cout << "destructor calling " << endl;
	}

	int M_age;
};

//void test01()
//{   
//	//1. bracket
//	Person p;  // 默认构造函数调用
//	p.M_age = 18;
//	Person P2(p); // reference constructor calling
//	cout << "p2 age is: " << P2.M_age << endl;
//
//}

void test02()
{
	Person p(0);
	//Person p2(p);
	cout << "p2 age is: " << p.M_age << endl;
}

int main()
{
	//test01();
	test02();
	/*test03();*/
	/*Person p;*/
	system("pause");
	return 0;
}















































