#include "iostream"
using namespace std;
#include "string"

class Person{

public:

	//1. 初始化列表比较死板
	Person() :M_A(10), M_B(20), M_C(30)  
	{

	}

	//1. 灵活初始化列表
	Person(int a, int b, int c) :M_A(a), M_B(b), M_C(c){}
	//Person(const Person & p)
	//{
	//	cout << "copy constructor function is here " << endl;
	//	M_age = p.M_age;
	//	//M_height = p.M_height; 这个是系统提供的浅拷贝方法， 等号赋值操作
	//	M_height = new int(*p.M_height); // 自己构建的深拷贝函数
	//}
    
	~Person()  //dedestructor
	{  
		// 将堆区分配的数据进行释放,规范化
		if (M_height != NULL)
		{
			delete M_height;
			M_height = NULL;
		}
		cout << "destructor calling " << endl;
	}

	int M_A;
	int M_B;
	int M_C;

	int * M_height;
};

void test01()
{   

	//Person p
	Person p1(2,3,1) ;
	cout << "constructor function age is : " << p1.M_A << " the height is: " << p1.M_B << " the height is: " << p1.M_C<< endl;  // pointer should have *
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















































