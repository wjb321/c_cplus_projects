#include<iostream>
using namespace std;
#include<string>
#include<ctime>

struct Student{
	string sName;
	int score;
	 
};
struct Teacher{
	string Tname;
	struct Student sArray[5];
};
void allocateSpace(struct Teacher tArray[], int len)
{   
	//int randscore = rand()%61 + 40; // 0~59 + 40 = 40 ~ 99, should not in this place
	string nameSeed = "abcde";
	for (int i = 0; i < len; i++)
	{
		tArray[i].Tname = "Teacher_";
		tArray[i].Tname += nameSeed[i];

		for (int j = 0; j < 5; j++)
		{   
			// should be here, everytime when for loop goes, the randscore will be different
			int randscore = rand() % 61 + 40; // %60: 0~59 + 40 = 40 ~ 99,  %61: 40~100
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[i];
			tArray[i].sArray[j].score = randscore;
		}
	}
}
void printinfo(struct Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << " teacher name: " << tArray[i].Tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tstudent name: " << tArray[i].sArray[j].sName << " score: " << tArray[i].sArray[j].score << endl;

		}
	}
}
int main()
{   
	//for (int i = 0; i < 10; i++)
	//{
	//	int number0 = rand();
	//	cout << "number0:" << number0 << endl;
	//}
	//
	//int number1 = rand() % 50;
	//int number2 = rand() % 25;
	//int number = rand() %100;
	//cout << "number:" << number << endl;
	//cout << "number1:" << number1 << endl;
	//cout << "number2:" << number2 << endl;
	// random number seed
	srand((unsigned int)time(NULL));
	struct Teacher tArray[3];// stuct array
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);
	printinfo(tArray, len);
}