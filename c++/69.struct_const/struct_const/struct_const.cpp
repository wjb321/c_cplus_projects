#include "iostream" //no .h
using namespace std;
#include "string"

struct student{  // define struct
	string name;
	int age;
	int score;
};  // can also intial a name here

// pointer, if change the local value of age, it will change the global variable
// const protect error operation
// pointer only has 4 bytes, saves spaces.
void pointprint(const student *s) 
{   
	//s->age = 200; // if the input parameter has const then this can not support, which means age can not chaged
	cout << " name is:  " << s->name << " age is  " << s->age << " score is  " << s->score << endl;
}
void printStudent(student s) // using student reference
{   
	s.age = 180;  // value transfer, can change local value, but there are lots value need to change, it will copy a new data
	cout << " name is:  " << s.name << " age is  " << s.age << " score is  " << s.score << endl;
}
int main()
{
	student s = { "jiabin", 22, 88 };
	printStudent(s);  // call function
	cout << s.age << endl;  // this wont change even the function change the local value
	pointprint(&s); // input the adress of this struct
	cout << s.age << endl;  // this wont change even the function change the local value

	return 0;
}