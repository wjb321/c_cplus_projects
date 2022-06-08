// stdafx.cpp : 只包括标准包含文件的源文件
// ConsoleApplication1.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
#if 0
	int arr[5];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 5;
	arr[4] = 6;
  for (int i = 0; i < 5; i++)
	{
		printf("arr values are: %d \r\n", arr[i]);
	}

#endif 
#if 0  // 基本数组操作
  //scanf 通常输入格式在double下是lf， 当打印的时候其格式可以换成或者1f或者f都可以。
 double arr[5];

 //输入变量时候往往比较费时，此处采用别的方案来进行比较合适， 换言之就是进行相应的初始化
  for (int i = 0; i < 5; i++){
	  printf("please input the score:", i + 1);
	  //getchar();
	  scanf("%lf", &arr[i]);
	  //getchar();
  }
  float score = 0.0;
  double max, min;
  max = min = arr[0];
  for (int i = 0; i < 5; i++)
  {
	  printf("%.3f", arr[i]);
	  printf("\n");
	  score += arr[i];
	  if (max < arr[i])
	  {
		  max = arr[i];
	  }
	  min = ((min > arr[i]) ? arr[i] : min); // a b ? a : n 
	  //if (min > arr[i])
	  //{
		 // min = arr[i];
	  //}
  }
  //for (int i = 0; i < 5; i++)
  //{
	 // score += arr[i];
  //}
  printf("the score and avarage is %.3f, %.3f, %g, %g \r\n", score, score/(sizeof(arr)/sizeof(arr[0])), max, min);

  while (1);
#endif

#if 0  // 数组越界导致别的变量被更改值, 此处对数组的操作引起了前面变量的改变,因为越界的不可检测，所以自己在写程序的时候防止越界发生
  int n = 666, arr[5] = { 1, 2, 3, 4, 5 };
  printf("%d, %d", &n, &arr);
  arr[7] = 999;
  printf("the n value is :%d", n); // n的值会被更改
#endif

  //vs 编译器允许标志符使用中文， 字符集
  //通常ascii 就可以表达完相应的操作，但是中文的操作符比较多，所以要进行相应的扩展，所以对于
  //256个ascii就是不够的，所以需要两个字符来代替一个字符，所以此处有unicode,称之为宽字节字符集
#if 1 

  wchar_t t = '中';
  char c = '中';
  printf("%d%c\n", c, c);
  printf("%d%c\n", t, t); //54992 -> bin 1101 0110(214) 1101 0000(208) 
  printf("%c%c\n", 214, 208);//'中'

  //unsigned char str1[2] = "中";  // 此部分的编译器在老师的地方没问题，但是我的地方是有问题的
  //printf("%d,%d\n", str1[0], str1[1]);
#endif
 return 0;
}



