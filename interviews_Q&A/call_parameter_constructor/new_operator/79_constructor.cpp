#include <iostream>
#include <cstring>
using namespace std; 
class Name
{
	char name[20];
public:
	Name()
	{
		strcpy_s(name, "");
		cout << "1"<<endl;
	}
	Name(const char* fname)
	{
		strcpy_s(name, fname);
			cout << "2"<<endl;
	}
};

int main()
{
	Name name[3] = { Name("hello"), Name("you") };
	//those are same like:
	//Name Name name[0] = Name("hello");
	//Name Name name[1] = Name("you");
	//Name Name name[2]
	//so it is like call the constructor functions with parameter 2 times and without parameter 1 time

	return 0;
}
//the final output is: 2 2 1