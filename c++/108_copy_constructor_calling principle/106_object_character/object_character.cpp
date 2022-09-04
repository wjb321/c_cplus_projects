#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{
		cout << "default constructor calling " << endl;

	}

	Person(int age )  //referenced Constuctor. 
	{  
		M_age = age;
		cout << "reference constructor " << endl;

	}

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

void test01()
{   
	//1. bracket
	//Person p;  // 默认构造函数调用
	Person P2(20); // reference constructor calling
	Person P3(P2); // copy constructor calling 

	cout << "p2 age is: " << P2.M_age << endl;
	//Person p1(); // test, default constructor with brackets around


	//2. explicit
	//Person p1;
	//Person p2 = Person(10); // reference constructor
	//Person p3 = Person(p2);
	//Person(10); //anonymous object, after this executation, system will recycle the anonymous object immediately when finish execuation
	//Person(p3); // Person(p3) === Person p3; this is an error: redefine error, complier will regard this as a object statement(对象声明)

	//3. implicit
	//Person p4 = 10;  // Person p4  = Person(10);
	//Person p5 = p4;  // copy constructor Person p5 = Person(p4)
}

//2. 值传递的方式给函数参数传值: 拷贝出临时的副本，不会拷贝出下一个数据
void doWork(Person p) // this p is not same as the p in doWork(p)
{

}
void test02()
{
	Person p;
	doWork(p);
}

//3. 值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;
	return p1;
}

void test03()
{
	Person  p = doWork2();
}
int main()
{
	//test01();
	//test02();
	test03();
	/*Person p;*/
	system("pause");
	return 0;
}















































