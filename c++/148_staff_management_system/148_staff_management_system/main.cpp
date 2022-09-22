#include <iostream>
using namespace std;
#include "workermanager.h"
#include "worker.h"
#include "employee.h"
#include "Boss.h"
int main()
{   
	Worker * worker = NULL;
	worker = new Employee(1, "wang", 123);
	worker->showInfo();
	delete worker;

	worker = new Manager(1, "xujiao", 321);
	worker->showInfo();
	delete worker;

	worker= new Boss(2, "who knows", 32112);
	worker->showInfo();
	workermanager wm;

	/*int decision = 0;

	while (true)
	{
		wm.show_menu();
		cout << "please input your selection: " << endl;
		cin >> decision;

		switch (decision)
		{
		case 0:
			wm.Exitsystem();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}*/
	system("pause");
	return 0;
}


//#include<iostream>
//using namespace std;
//int quickSort(int a[], int, int);
//int main()
//{   
//	int finalVal = 0;
//	int array[] = { 34, 65, 12, 43, 67, 5, 78, 10, 3, 70 }, k;
//	int len = sizeof(array) / sizeof(int);
//	cout << "The orginal arrayare:" << endl;
//	for (k = 0; k<len; k++)
//		cout << array[k] << ",";
//	cout << endl;
//	finalVal = quickSort(array, 0, len - 1);
//	cout << "The sorted arrayare:" << endl;
//	for (k = 0; k<len; k++)
//		cout <<array[k] << ",";
//	cout << endl;
//	cout << "gh:" <<  finalVal << ",";
//	system("pause");
//	return 0;   
//}
//
//int quickSort(int s[], int l, int r)
//{
//	int medianVal = 0;
//	medianVal = (int)(r + 1) / 2.0;
//	if (l< r)
//	{
//		int i = l, j = r, x = s[l];
//		while (i < j)
//		{
//			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
//				j--;
//			if (i < j)
//				s[i++] = s[j];
//			while (i < j && s[i]< x) // 从左向右找第一个大于等于x的数
//				i++;
//			if (i < j)
//				s[j--] = s[i];
//		}
//		s[i] = x;
//		quickSort(s, l, i - 1); // 递归调用
//		quickSort(s, i + 1, r);
//	}
//	return s[medianVal];
//}