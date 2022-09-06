#include "iostream"
#include "string"
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << " animal constructor " << endl;
	}
	virtual void speak() = 0;

	// 1. virtual destructor
	//virtual ~Animal()
	//{
	//	cout << " animal virtual destructor " << endl;
	//}
	
	//2. pure virtual deconstructor
	//it needs declaraion and impletement, impletement happend
	//cause it is a pure virtual decontructor, so it can not instantiate
	//destructor or pure virtual:解决在子类中的析构代码调用不到的问题，当在子类开辟了堆区。
	virtual ~Animal() = 0;
};

Animal::~Animal() 
{
	cout << " animal pure destructor " << endl;
}

class cat :public Animal
{
public:
	cat(string name)
	{   
		cout << " cat constructor " << endl;
		m_name = new string(name);  // heap new a attribute, how to free that 
	}
	virtual void speak()
	{
		cout << *m_name << " is miao miao miao" << endl;
	}
	~cat()
	{
		if (m_name != NULL)
		{  
			cout << " cat destructor " << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	string *m_name; 
};

void React()
{
	Animal * ani = new cat("tom"); 
	ani->speak();
   // 父类指针在西沟时候不会调用子类中的析构函数，导致了子类如果有堆区属性，就会导致内存泄露
	// 解决办法就是在父类析构函数添加virtual 关键字
	delete ani;
}
void test01()
{   
	React();
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















































