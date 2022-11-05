#include <iostream>
using namespace std;
#include "workermanager.h"
#include "worker.h"
#include "employee.h"
#include "Boss.h"
#include <string.h>
#define ROW 5
#define COLUMN 5
double getAverage(int arr[], int size);

int build_exclusive_arbitration_window(int a, int b, int **p)
{
	for (int i = 0; i < a*(b + 1); i++)
	{
		*((int*)p + i) = 1;
	}
	return **p;
}

/*********************************
* 方法1: 第一维的长度可以不指定 *
*                但必须指定第二维的长度 *
*********************************/
void print_a(int a[][COLUMN], int n, int m)
{   
	for (int i = 0; i < ROW*COLUMN; i++)
		*((int*)a + i) = 1;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}
}
/*****************************************
*方法2: 指向一个有5个元素一维数组的指针 *
*****************************************/
void print_b(int(*a)[5], int n, int m)
{  
	for (int i = 0; i < ROW*COLUMN; i++)
		*((int*)a + i) = 1;
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
/***********************************
*方法3: 利用数组是顺序存储的特性, *
*              通过降维来访问原数组!          *
***********************************/
void print_c(int *a, int n, int m)
{  

	int i, j;
	for (int i = 0; i < n*m; i++)
		*((int*)a + i) = 1;
	for (int i = 0; i < n; i++)
		*(a + i*(m)+m-1) = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", *(a + i*m + j));

		printf("\n");
	}
}
int main()
{   
    #if 0
	int temp[2][4];
	int arr[2][4] = { { 1, 2, 3, }, {5,6,7}};
	temp = build_exclusive_arbitration_window(ROW, COLUMN, (int **)arr);
	for (int i = 0; i < ROW*(COLUMN); i++)
	     cout << "temp" << temp[i] << endl;
	int arr1[ROW][COLUMN + 1] = { 0 };
    #endif

    #if 0


		int a[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 8 } };
		int b[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 8 } };
		int c[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 88 } };
		printf("\n方法1:\n");
		print_a(a, 5, 4);

		printf("\n方法2:\n");
		print_b(b, 5, 5);

		printf("\n方法3:\n");
		print_c(&c[0][0], 5, 8);

#endif
	//arr[1][2] = 67;
	//memset(arr,1, sizeof(arr)); //This will reinitialize all to ZERO
	//memset(arr[2], 1, sizeof(int)* 3); //This will reinitialize all to ZERO
	/**/

	//for (int i = 0; i < ROW*(COLUMN+1); i++) 
	//	*((int*)arr1 + i) = 1;
	//for (int i = 0; i < sizeof(arr1) / sizeof(*arr1); i++)
	//	arr1[i][COLUMN ] = 0;
	//for (int j = 0; j< sizeof(arr1[i]) / sizeof(int); j++)
	//int cb = sizeof(int)* ROW * COLUMN;
	//memcpy(arr1, arr, cb);
	/*for (int i = 0; i < ROW; i++)
		arr1[ROW][COLUMN + 1] = 0;*/

	/*for (int i = 0; i< sizeof(arr1) / sizeof(*arr1); i++)
	for (int j = 0; j< sizeof(arr1[i]) / sizeof(int); j++)
		printf("arr1[%d][%d] is %d\r\n", i, j, arr1[i][j]);
*/
	//Worker * worker = NULL;
	//worker = new Employee(1, "wang", 123);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(1, "xujiao", 321);
	//worker->showInfo();
	//delete worker;

	//worker= new Boss(2, "who knows", 32112);
	//worker->showInfo();
	workermanager wm;

	int decision = 0;

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
			wm.add_Emp();
			break;
		case 2:
			wm.show_Emp();  // show employee
			break;
		case 3: // in the braket it is the test, should be deleted after
			wm.Del_Emp();
			break;
		//{
		//		  int ret = wm.IsExist(5); // test with
		//		  if (ret != -1)
		//		  {
		//			  cout << "the employees exist" << endl;
		//		  }
		//		  else
		//		  {
		//			  cout << "it does not exist" << endl;
		//		  }
		//		break;
		//}

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
	}
	// 带有 5 个元素的整型数组
	//int balance[5] = { 1000, 2, 3, 17, 50 };
	//double avg;
	////int b[1] = { 2 };
	////int *pb = b;
	////
	////cout << &pb << endl; //0x?
	////cout << &b << endl; //0x?
	////cout << *pb << endl; //2
	////cout << b << endl; 
	////cout << &b[0] << endl; //0x?

	//// 传递一个指向数组的指针作为参数
	//avg = getAverage(balance, 5);

	//// 输出返回值
	//cout << "平均值是：" << avg << endl;

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


double getAverage(int *arr, int size)
{
	int    i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;

	return avg;
}