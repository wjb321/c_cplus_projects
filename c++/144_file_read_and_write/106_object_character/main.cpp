#include "iostream"
#include "string"
using namespace std;
#include<fstream> // for reading and writing 
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
	ifstream ifs;

	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "file opens fail" << endl;
		return;
	}

	// read file
	char buf[1024] = { 0 };
	
	//1. method 1
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	
	
	//2. method 2
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//3.method 3
	//string buf1;
	//while (getline(ifs, buf1))
	//{
	//	cout << buf << endl;
	//}

   // 4. method 4 
	char c;
	while ((c = ifs.get()) != EOF)  // if there is no end of the file, it will keep reading till it finishes
	{
		cout << c;
	}


	// close file
	ifs.close();
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}















































