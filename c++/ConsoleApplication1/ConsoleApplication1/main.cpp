#include <iostream>
using namespace std;
#include <string.h>

#define ROW 8
#define COLUMN 7+4
#define TotNumBC 4
#define NumSlot 3 //1 is for the arbitration window
#define SlotTime 1
#define NumMes 6
#define MesList 3

int c[ROW][COLUMN] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 88 } };
//int c[5][5] = { 0 };
int d[ROW][COLUMN] = { 0 };

int  mes_id[TotNumBC][NumSlot] = { { 0x001, 0x121, 0x123 },    //, 0x122
{ 0x001, 0x121, 0x123 },    //, 0x122
{ 0x001, 0x121, 0x120 },    //, 0x122
{ 0x001, 0x121, 0x123 } };   //, 0x122

float Mes_list[NumMes][MesList] = { { 0x123, 20000, 1300 },
{ 0x122, 20000, 2000 },
{ 0x120, 20000, 1500 },
{ 0x124, 30000, 3200 },
{ 0x125, 40000, 1500 },
{ 0x121, 10000, 2100 } };

float find_BC_inPSA()
{
	float minialVal = Mes_list[0][1];

	for (int i = 0; i <NumMes; i++)
	{
		if (Mes_list[i][1] < minialVal)
		{
			minialVal = Mes_list[i][1];
		}
	}
	return minialVal;
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
void  print_c(int *a, int n, int m)
{    
	//int * ret = NULL;
	//ret =  new int;
	int i, j;
	for (int i = 0; i < n*m; i++)
		*((int*)a + i) = 1;
	//for (int i = 0; i <n; i++)
	//	a[i][m - 1] = 0;
	/*for (int i = 0; i < n; i++)
		*((a + i) + m) = 0;*/
		//*(a + i*(n)) = 0;

	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < m; j++)
	//	{
	//		printf("%d ", *(a + i*m + j));
	//		d[i][j] = *(a + i*m + j);
	//	}


	//	printf("\n");
	//}

	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < m; j++)
	//		printf("%d ", *(a + i*m + j));

	//	printf("\n");
	//}
}
void last_column_is_arbitration(int a[][COLUMN], int n, int m)
{
	for (int i = 0; i <n; i++)
		c[i][m-1] = 0;
}
int main()
{
#if 1
	float temp_Tim1_Val = 0.0;
	float val_final = 0;
	for (int j = 0; j < NumSlot; j++)
	for(int i = 0; i < NumMes; i++)
	{
		if (mes_id[0][NumSlot - 1 - j] == Mes_list[i][0])
		{
			temp_Tim1_Val += Mes_list[i][2];
			printf("final value: %.3f \r\n", temp_Tim1_Val);
		}
	
	}

	val_final = find_BC_inPSA();
	printf("final value: %.3f \r\n", temp_Tim1_Val/1000.0);
	printf("val_final: %.1f \r\n", val_final/1000.0);

#endif 

#if 0


	//int a[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 8 } };
	//int b[5][5] = { { 1, 2 }, { 3, 4, 5 }, { 6 }, { 7 }, { 0, 8 } };
	//
	//printf("\n方法1:\n");
	//print_a(a, 5, 4);

	//printf("\n方法2:\n");
	//print_b(b, 5, 5);

	printf("\n方法3:\n");
	print_c(&c[0][0], ROW, COLUMN);

	printf("\n方法4:\n");
	last_column_is_arbitration(c, ROW, COLUMN);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j <COLUMN; j++)
			printf("%d ", c[i][j]);

		printf("\n");///=
	}
    
	printf("c: row: %d ", sizeof(c) / sizeof(c[0]));
	printf("c: col: %d ", sizeof(c[0]) / sizeof(c[0][0]));
#endif
	
	system("pause");
	return 0;
}
