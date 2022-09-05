#include "iostream"
#include "string"
using namespace std;

class luckgay;
class Building
{
public:
  friend void goodfriend(Building *building);  // 将这个成员函数变成friend类，那么就可以访问其私有属性了
  friend class Goodgay;  // friend class
  friend void luckgay::visit1();
  friend void luckgay::visit2();
   Building();
	  string m_livingroom; 
  private:
      string m_bedroom;

};

class luckgay
{
public:
	luckgay();
	void visit1();
	void visit2();
	Building * building_1;
};

//another class
class Goodgay
{
public:
	Goodgay();
	void visit();
	Building * building;
};


Building::Building()
{
	m_livingroom = "for talking";
	m_bedroom = "for sleeping";
}

Goodgay::Goodgay()
{
	building = new Building; 
}

luckgay::luckgay()
{
	building_1 = new Building;
}

void Goodgay::visit()
{
	cout << "class func: goodgay class visits: " << building->m_livingroom << endl;
	cout << "class func: goodgay class visits: " << building->m_bedroom << endl;
}

void luckgay::visit1()
{
	cout << "member func: luckgay class visits: " << building_1->m_livingroom << endl;
	cout << "member func: luckgay class visits: " << building_1->m_bedroom << endl;
}


void luckgay::visit2()
{
	cout << "member func: luckgay class visits: " << building_1->m_livingroom << endl;
	cout << "member func: luckgay class visits: " << building_1->m_bedroom << endl;
}


//global function
void goodfriend(Building *building)  // pointer type
{
	cout << "global func: good friend visits: " << building->m_livingroom << endl;
	cout << "global func: good friend visits: " << building->m_bedroom << endl;  // private 不能访问
}


//void test01()
//{  
//	Building bui;
//	goodfriend(&bui);  // the input is the adress
//}

void test02()
{
    //Building 
	Goodgay gay;
	luckgay lg;
	gay.visit();
	lg.visit1();
	lg.visit2();
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}















































