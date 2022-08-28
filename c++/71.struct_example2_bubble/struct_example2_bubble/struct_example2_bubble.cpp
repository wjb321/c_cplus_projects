#include <iostream>
using namespace std;
#include <string>


struct Hero
{
	string name;
	int age;
	string sex;
};

void bubblesort(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len -1 ; i ++)  // len -1
	 for (int j = 0; j < len -i-1; j++)  // len -i -1
	{
		
		if (HeroArray[j].age > HeroArray[j+1].age) // compare should be j and j+1
		{
			//int temp; // here should be a struct
			struct Hero temp = HeroArray[j];
			HeroArray[j] = HeroArray[j + 1];
			HeroArray[j+1] = temp;
         }

	}
	 for (int i = 0; i < len; i++)  // len -1
	 {
		 cout << "age :" << HeroArray[i].age << endl;
	 }
}

void printHero(struct Hero her[], int len)
{  
	for (int i = 0; i < len; i++)  // len -1
	{
		cout << " name is: " << her[i].name << "\t" << her[i].age << "\t" << her[i].sex << endl;
	}
}
int main()
{
	struct Hero HeroArray[5] = 
	{
		{ "liu", 28, "male" },
		{ "guan", 23, "male" },
		{ "zhang", 20, "male" },
		{ "zhao", 21, "male" },
		{ "diao", 19, "female" },

	};
	int len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	//test code
	//
	//for (int i = 0; i < len; i++)
	//{
	//	cout << " name is: " << HeroArray[i].name <<"\t"<< HeroArray[i].age <<"\t"<< HeroArray[i].sex << endl;
	//}
	bubblesort(HeroArray, len);
	printHero(HeroArray, len);
	
}