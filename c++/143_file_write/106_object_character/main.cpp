#include "iostream"
#include "string"
using namespace std;
#include<fstream>
void test01()
{   
	//create ios object
	ofstream ofs;

	// set open methods
	ofs.open("test.txt", ios::out);

	//write contents
	ofs << "name: wang" << endl;
	ofs << "sex: man" << endl;
	ofs << "age: 18" << endl;

	ofs.close();

}

//test int array
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















































