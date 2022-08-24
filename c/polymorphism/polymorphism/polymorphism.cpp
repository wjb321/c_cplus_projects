#include <iostream>
using namespace std;

#if 0  // example 1
class Shape {
protected:
	int width, height;
public:
	Shape(int a, int b)
	{

		width = a;
		height = b;
	}
	virtual int area() //virtual： 此处可以定义为虚函数，从而在派生类中能够进行动态链接，或者后绑定。换言之，
		               //          由于此类是基类，当派生类调用时候，因为其已经定义相关函数，所以会自动静态链接到
					   //          这个基类函数，从而打印错误。但是当进行 virtual 关键字之后，就可以使用了。
	{
		cout << "This is parent class area: " << endl;
		return 0;
	}
};

class Rectangle : public Shape{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
	int area()
	{
		cout << "rectangle area is:" << endl;
		return (width * height);
	}

};

class Triangle : public Shape{
public:
	Triangle(int a = 0, int b = 0) : Shape(a, b){}
	int area()
	{
		cout << "circle area is:" << endl;
		return (width * height / 2);
	}
};

int main()
{
	Shape *shape;  //定义指针类
	Rectangle rec(10, 7);  // 类中的函数有rectangle
	Triangle tri(4, 7);  //triangle 初始化

	shape = &rec; //保存rec的地址到指针中，然后指针指向所存地址的值
	shape->area(); //访问对应类中的函数用->

	shape = &tri;
	shape->area();

	return 0;
}

#endif
/*
基类有函数 shape() 和 area()函数，但是当进行继承的时候，
对派生类进行访问，由于公用的函数 int area() 是公用的函数
即它没有在基类进行虚函数声明即： virtual int area() 在函数进行声明后其编译结果会不一样。
此处
1. virtual function: 在派生类中重新定义基类中定义的虚函数时候，会告诉编译器不要静态链接到该函数，
                     即会考虑是不是在派生类中是否会有相同函数，即多态性，应该访问派生类的函数。
2. pure virtual function: 有时候需要在基类中定义虚函数，然后方便在派生类中重新定义该函数从而更好的适应对象，但是
                          在该基类又不能对虚函数给出有意义的实现，这个时候就需要使用纯虚函数.
						  virtual int area() = 0; 纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。
						  包含纯虚函数的类是抽象类，抽象类不能定义是你，但可以声明指向实现该抽象类的具体类的指针或引用。
*/

# if 0 // example 2
class B {
public:
	void b1() // b1 calls b2 function 
	{
		b2();
	}
	virtual void b2()   // virtual function
		{
		cout << "this is b2 in B" << endl;
	}
};

class A : public B
{
public:
	virtual void b2()  // rewrite virtual function again
	{
		cout << "this is b2 from the derived class" << endl;
	}
};

int main()
{
	A *pA = new A;  // here new a class A 
	pA->b1();   // then call this function which derives from class B 
	return 0;
}

# endif 
/*
虚函数可以不实现。不实现的函数叫做纯虚函数。
在一个类中如果存在未定义的虚函数，那么不能直接使用该类的实例，可以认为是
因为它是未定义的virtual函数，其是抽象的，无法实例化。

父类的虚函数或者纯虚函数如果不想被继承时候重写，在c++11之后，可以用关键字
final 来避免该函数再次被重写。
如果一个类不希望被继承，那么也可以声明为 final 

*/

#if 1
class Base{
public:
	virtual void func()
	{
		cout << "base function" << endl;
	}

};

class _base : public Base{
public:
	virtual void func() final
	{
		cout << "this is the first time derived class" << endl;
	}
};

class __base : public _base
{
//public:    // 不能进行重写，因为在父类中已经定义了这个类是 final 定义的不可以被继承、或者重写。
//	virtual void func()  
//	{
//		cout << "this the 2nd derived class" << endl;
//	}
};

int main()
{
	_base a;
	__base b;
	Base* ptr = &a;
	ptr->func();
	ptr = &b;

	_base * ptr2 = &b;
	ptr->func();
	ptr2->func();
}
#endif