#include "iostream"
#include "string"
using namespace std;
#include<fstream> // for reading and writing 

int arr[5] = { 10, 3, 5, 4, 1 };
int ArraySum(int *inputarray, int location)//求和函数定义
{
	int sum = 0;//累积量初始化
	for (int i = 0; i < location; i++) //当前消息的位置之前的数值相加
	{
		sum += *inputarray;
		inputarray++;
	}
	return sum;
}
int main()
{  
	int tempVal = 0;
	tempVal = ArraySum(arr, 5);
	cout << tempVal << endl;
	system("pause");
	return 0;
}















































