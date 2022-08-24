#include <iostream>
using namespace std;

class Shape {
protected:
	int width, height;
public:
	Shape(int a, int b)
	{

		width = a;
		height = b;
	}
	int area()
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
		return (width * height/ 2);
	}
};

int main()
{
	Shape * shape;
	Rectangle rec(10, 7);
	Triangle tri(4, 7);
 
	shape = &rec;
	shape->area();

	shape = &tri;
	shape->area();

	return 0;
}