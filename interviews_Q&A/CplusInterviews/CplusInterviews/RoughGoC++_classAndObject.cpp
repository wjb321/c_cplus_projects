#include <iostream>
using namespace std;

#define basicClass  0
#define classAccessModifier  0
#define inheritAndProtect    0
#define constructorAnddecon  0
#define copyconstructor      0
#define friendFunction       0
#define inlinefunction       0
#define overloading          0
#define polymorphism         0
#define Abstructofdata         0
#define encapulationofdata         0
#define interfaceofabstructclass         1
class printData
{
public:
	void print(int i) {
		cout << "整数为: " << i << endl;
	}

	void print(double  f) {
		cout << "浮点数为: " << f << endl;
	}

	void print(char c[]) {
		cout << "字符串为: " << c << endl;
	}
};
class Line
{
public:
	int getLength(void);
	Line(int len);             // 简单的构造函数
	Line(const Line& obj);      // 拷贝构造函数
	~Line();                     // 析构函数

private:
	int* ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line& obj)
{
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
	cout << "释放内存" << endl;
	delete ptr;
}
int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line 大小 : " << obj.getLength() << endl;
}


class Line1
{
public:
	void setLength(double len);
	double getLength(void);
	Line1();  // constructor
private:
	double length;
};

Line1::Line1(void)
{
	cout << "Object is being created" << endl;
}

void Line1::setLength(double len)
{
	length = len;
}

double Line1::getLength(void)
{
	return length;
}


class Box2
{
protected:
	double width2;
};

class SmallBox :Box2 // SmallBox 是派生类
{
public:
	void setSmallWidth(double wid);
	double getSmallWidth(void);
};

// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
	return width2;
}

void SmallBox::setSmallWidth(double wid)
{
	width2 = wid;
}

class Box1
{
public:
	double length2;
	void setWidth(double wid);
	double getWidth(void);

private:
	double width2;
};

// 成员函数定义
double Box1::getWidth(void)
{
	return width2;
}

void Box1::setWidth(double wid)
{
	width2 = wid;
}

class Box
{
public:
	double l;
	double b;
	double h;
	double get(void);
	void set(double len, double bre, double hei);
};

double Box::get(void)
{
	return l * b * h;
}

void Box::set(double len, double bre, double hei)
{
	l = len;
	b = bre;
	h = hei;
}


int main()
{
#if  basicClass
	Box box1;
	Box box2;
	Box box3;
	double volume = 0.0;
	box1.h = 5.0;
	box1.b = 5.0;
	box1.l = 3.2;

	box2.h = 5.0;
	box2.b = 9.0;
	box2.l = 9.2;

	volume = box1.h * box1.b * box1.l;
	cout << "the volume is" << volume << endl;

	volume = box2.h * box2.b * box2.l;
	cout << "the volume is" << volume << endl;

	box3.set(22.0, 3.0, 12.4);
	volume = box3.get();
	cout << "the box3 volume is " << volume << endl;
#elif classAccessModifier
	Box1 box;
	box.setWidth(10.3);
	box.length = 20;
	cout << "width of box " << box.getWidth() << endl;
#elif inheritAndProtect
//protected（受保护）成员变量或函数与私有成员十分相似，但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。
	SmallBox box;
	box.setSmallWidth(5.0);
	cout << "Width of box : " << box.getSmallWidth() << endl;
#elif constructorAnddecon  
	Line1 line;
	line1.setLength(6.0);
	cout << "Length of line : " << line1.getLength() << endl;
#elif copyconstructor
	Line line1(10);

	Line line2 = line1; // 这里也调用了拷贝构造函数

	display(line1);
	display(line2);
#elif  inlinefunction
//内联函数inline：引入内联函数的目的是为了解决程序中函数调用的效率问题，这么说吧，程序在编译器编译的时候，编译器将程序中出现的内联函数的调用表达式用内联函数的函数体进行替换，而对于其他的函数，都是在运行时候才被替代。这其实就是个空间代价换时间的i节省。所以内联函数一般都是1 - 5行的小函数。在使用内联函数时要留神：
//1.在内联函数内不允许使用循环语句和开关语句；
//2.内联函数的定义必须出现在内联函数第一次调用之前；
//3.类结构中所在的类说明内部定义的函数是内联函数。

#elif overloading 
	printData pd;

	// 输出整数
	pd.print(5);
	// 输出浮点数
	pd.print(500.263);
	// 输出字符串
	char c[] = "Hello C++";
	pd.print(c);
#endif
	return 0;
}