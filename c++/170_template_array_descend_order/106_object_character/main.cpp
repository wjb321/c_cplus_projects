#include "iostream"
#include "string"
using namespace std;
//Exchange
template <class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//sort algorithm
template <class T>
void mysort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
   			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//
template<class T>
void pringArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//test char array
void test01()
{   
	char charArr[] = "abdcdfh";
	int num = sizeof(charArr) / sizeof(char);
	mysort(charArr, num);
	pringArray(charArr, num);

}

//test int array
void test02()
{
	int intArr[] = { 2, 4, 5, 3, 7, 8, 1, 2, 8, 9 };
	int num = sizeof(intArr) / sizeof(int);
	mysort(intArr, num);
	pringArray(intArr, num);

}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}















































