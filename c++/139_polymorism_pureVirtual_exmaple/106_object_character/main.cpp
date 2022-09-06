#include "iostream"
#include "string"
using namespace std;
class AbstructDrink
{
public:
	virtual void boil() = 0;  // pure virtual function
	virtual void brew() = 0;  // pure virtual function
	virtual void pour() = 0;  // pure virtual function
	virtual void putIngredient() = 0;  // pure virtual function
     
	void makeDrink()
	{
		boil();
		brew();
		pour();
		putIngredient();
	}
};

class coffee :public AbstructDrink
{
public:
	virtual void boil()
	{
		cout << "boil mineral water" << endl;
	}
	virtual void brew()
	{
		cout << "brew the coffee" << endl;
	}
	virtual void pour()
	{
		cout << "pour into glass?" << endl;
	}
	virtual void putIngredient()
	{
		cout << "put sugar" << endl;
	}
};


class tee :public AbstructDrink
{
public:
	virtual void boil()
	{
		cout << "boil purified water" << endl;
	}
	virtual void brew()
	{
		cout << "brew the tee" << endl;
	}
	virtual void pour()
	{
		cout << "pour into glass?" << endl;
	}
	virtual void putIngredient()
	{
		cout << "put good things" << endl;
	}
};

void doWork(AbstructDrink * abs)
{
	abs->makeDrink();
	delete abs;  // release the memeory
}
void test01()
{   
	doWork(new coffee);
	cout << "=======" << endl;
	doWork(new tee);
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















































