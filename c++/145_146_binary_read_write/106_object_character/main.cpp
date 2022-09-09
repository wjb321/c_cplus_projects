#include "iostream"
#include "string"
using namespace std;
#include<fstream> // for reading and writing 
//steps: 
//1, include the headfile
//2, create fream object
//3, open file
//4, write file

class Person
{
public:
	char m_name[64];
	int m_Age;
	string sex ;
	string name;

};

// write file
void test01()
{   
	//ofstream ofs;

	// create ostream object
	ofstream ofs("person.txt", ios::out | ios::binary);

	//open the file
	//ofs.open("person.txt", ios::out | ios::binary);

	//write file
	Person p = {"zhang san", 18, "man", "json"};

	ofs.write((const char *)&p, sizeof(Person)); //write file has to use "const *" so this has to be forced converted

	ofs.close();


}

//read file
void test02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "file opening failure";
		return;
	}

	Person p;
	ifs.read((char *)&p, sizeof(Person)); // use read method
	cout << "name: " << p.m_name << " age: " << p.m_Age << endl;

	ifs.close();
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}















































