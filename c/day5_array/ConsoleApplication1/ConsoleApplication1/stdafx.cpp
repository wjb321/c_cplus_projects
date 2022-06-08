// stdafx.cpp : 只包括标准包含文件的源文件
// ConsoleApplication1.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
#include <stdio.h>
int main()
{
	int arr[5];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 5;
	arr[4] = 6;

	for (int i = 0; i < 5; i++)
	{
		printf("arr values are: %d /r/n", arr[i]);
	}

	return 0;
}
// TODO:  在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用
