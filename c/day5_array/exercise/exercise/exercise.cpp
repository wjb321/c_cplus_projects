
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main()
{   
	int str[5] = { 0 };
	int str3[5] = { 0 };
	int a = 0, b=0,c=0,d = 0, e = 0, f = 0, t ;
	int g = 0, h= 0, j=0, k=0, l=0, z=0, x=0, w=0, q=0, y=0;
	char str1[] = "abcd";
	printf("please input a constant value:"); //45678
	scanf("%d",&a); // 输入函数没有换行符
	//printf("\n");
	b = a/10000;//12345
	c = (a / 1000) % 10;  //2
	d = (a %1000) / 100; // 
	e= (a % 100) / 10; //4
	f = (a % 10) ; //4
	str1[0] = (char)a;
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("d = %d\n", e);
	printf("f = %d\n", f);
	//str3[5] = { b,c,d,e,f };
	str[0] = b;
	str[1] = c;
	str[2] = d;
	str[3] = e;
	str[4] = f;
	for (int i = 0; i < 5; i++)
	{
		if (str[i] == 0)
			g++;
		else if (str[i] == 1)
			h++;
		else if (str[i] == 2)
			j++;
		else if (str[i] == 3)
			k++;
		else if (str[i] == 4)
			l++;
		else if (str[i] == 5)
			z++;
		else if (str[i] == 6)
			x++;
		else if (str[i] == 7)
			w++;
		else if (str[i] == 8)
			q++;
		else if(str[i] == 9)
			y++;
	}
	printf("0 repeat %d times\n", g);
	printf("1 repeat %d times\n", h);
	printf("2 repeat %d times\n", j);
	printf("3 repeat %d times\n", k);
	printf("4 repeat %d times\n", l);
	printf("5 repeat %d times\n", z);
	printf("6 repeat %d times\n", x);
	printf("7 repeat %d times\n", w);
	printf("8 repeat %d times\n", q);
	printf("9 repeat %d times\n", y);

	//printf("e = %s\n", str1[0]);
	//_itoa(a, str1, 10);
	//printf("e=%s\n", str1);
	return 0;
}