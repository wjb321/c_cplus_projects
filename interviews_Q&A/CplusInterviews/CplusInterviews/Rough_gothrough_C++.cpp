#include <iostream>
#include <string>
#include <typeinfo>
#include <ctime>
using namespace std;


#define storageClass   0
#define memberOperator 0
#define lambdaFunc     0
#define arrayInfo      0
#define stringInfo     0
#define pointerInfo    0
#define pointerArray    0
#define pointerPointer   0
#define pointertoFunc    0
#define funcReturnPointer    0
#define reference_c           0 
#define referenceInfunc       0
#define structDef             0
#define structAsfunPara       0
#define PointerToStruct       1
static int count1 = 10;
struct Employer {
	char first_name[16];
	int age;
}emp;

struct Employer1 {
	char first_name[16];
	int age;
}*p_emp;

struct Books
{
	char title[50];
	char author[50];
	char subject[50];
	int  bookID;
};
void func(void);
double getAverage(int* arr, int size);
int* getRandom();
void swap(int& x, int& y);
void printBook(struct Books book);
void printBook1(struct Books* book);
int main()
{
#if storageClass
	while (count1--)
	{
		func();
	}
#elif memberOperator 
  // . is for the real object, arrow operator use with a pointer which points to the object(real object)
  //-> left is a pointer
	strcpy_s(emp.first_name, "jiabin");
	cout << emp.first_name << endl;
	emp.age = 10;
	cout << emp.age << endl;
	//Employer1 *p_emp = NULL;
	//p_emp->age = 20;
	//cout << p_emp->age << endl;
#elif lambdaFunc 
// lambda regards func as an object, it can be used as like object, for example, can assign it to variable or regards as a parameter or evaluating them like functions
// [capture](parameters)->return-type{body}
//[](int x, int y){return x < y;}

#elif arrayInfo
	double array1[5]={ 1000.0, 2.0, 3.4, 17.0, 50.0 };
	double* p;
	p = array1; // array name is the pointer of the first variable in the array
	cout << "the value that uses pointer: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	cout << "use runoobAarray: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(runoobAarray + " << i << ") : ";
		cout << *(array1 + i) << endl;
	}
#elif stringInfo
	char str1[13] = "runoob";
	char str2[13] = "google";
	char str3[13];
	int  len;
	char* ptr = strchr(str1, 'un');
	//cout << "strchr()" << typeid(ptr)<< strchr(str1, 'un') << endl;
	cout << "strcmp()" << strcmp(str1, str2) << endl;
	strcpy_s(str3, str1);
	cout << "strcpy( str3, str1) : " << str3 << endl;
	strcat_s(str1, str2);
	cout << "strcat( str1, str2): " << str1 << endl;
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;
#elif pointerInfo
	const int MAX = 3;
	int  var1;
	char var2[10];
	int var = 20;
	int* ptr;
	int* ptr1 = NULL;
	char* ptr2 = NULL;
	ptr = &var;

	int  var3[MAX] = { 10, 100, 200 };
	int* ptr3;
	ptr3 = var3;

	cout << "ptr1 " << ptr1 << " ptr1++ "<< ++ptr1<< endl;
	//cout << "ptr2 " << ptr2 << " ptr2++ " << ++ptr2 << endl;
	cout << "ptr " << ptr << " *ptr " << *ptr << endl;
    cout << "var1 address： ";
	cout << &var1 << endl;
    cout << "var2 address： ";
	cout << &var2 <<endl;

	for (int i = 0; i < MAX; i++)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr3<< endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr3 << endl;

		// 移动到下一个位置
		ptr2++;
	}
#elif pointerArray
	const int MAX = 3;
	int  var[MAX] = { 10, 100, 200 };
	int* ptr[MAX];

	for (int i = 0; i < MAX; i++)
	{   
		cout << "Value of var[" << i << "] = " << &var[i]<< endl;
		ptr[i] = &var[i]; // 赋值为整数的地址
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of var[" << i << "] = ";
		cout << *ptr[i] << endl;
	}
#elif  pointerPointer
int var;
int* ptr;
int** pptr;
var = 3000;
ptr = &var;
pptr = &ptr;
cout << "var 值为 :" << var << endl;
cout << "*ptr 值为:" << *ptr << endl;
cout << "**pptr 值为:" << **pptr << endl;
cout << "var 地址为 :" << &var << endl;
cout << "ptr=&var 值为var的地址:" << ptr << endl;
cout << "ptr地址为:" << &ptr << endl;
cout << "*pptr=ptr=&var  值为var的地址:" << *pptr << endl;
cout << "pptr 地址为:" << &pptr << endl;
#elif  pointertoFunc

int balance[5] = { 1000, 2, 3, 17, 50 };
double avg;
avg = getAverage(balance, 5);
cout << "Average value is: " << avg << endl;

#elif funcReturnPointer
int* p;
p = getRandom();
for (int i = 0; i < 10; i++)
{   cout << "*(p + " << i << ") : ";
	cout << *(p + i) << endl;
}
#elif reference_c
int    i;
double d;
int& r = i;
double& s = d;
i = 5;
cout << "Value of i : " << i << endl;
cout << "Value of i reference : " << r << endl;
d = 11.7;
cout << "Value of d : " << d << endl;
cout << "Value of d reference : " << s << endl;
r = 10;
cout << "Value of i reference r : " << r << endl;
cout << "Value of i : " << i << endl;

#elif referenceInfunc
int a = 100;
int b = 200;
cout << "交换前，a 的值：" << a << endl;
cout << "交换前，b 的值：" << b << endl;
swap(a, b);
cout << "交换后，a 的值：" << a << endl;
cout << "交换后，b 的值：" << b << endl;
#elif structDef
Books Book1;        // 定义结构体类型 Books 的变量 Book1
Books Book2;        // 定义结构体类型 Books 的变量 Book2

// Book1 详述
strcpy_s(Book1.title, "C++ 教程");
strcpy_s(Book1.author, "Runoob");
strcpy_s(Book1.subject, "编程语言");
Book1.bookID = 12345;

// Book2 详述
strcpy_s(Book2.title, "CSS 教程");
strcpy_s(Book2.author, "Runoob");
strcpy_s(Book2.subject, "前端技术");
Book2.bookID = 12346;

// 输出 Book1 信息
cout << "第一本书标题 : " << Book1.title << endl;
cout << "第一本书作者 : " << Book1.author << endl;
cout << "第一本书类目 : " << Book1.subject << endl;
cout << "第一本书 ID : " << Book1.bookID << endl;

// 输出 Book2 信息
cout << "第二本书标题 : " << Book2.title << endl;
cout << "第二本书作者 : " << Book2.author << endl;
cout << "第二本书类目 : " << Book2.subject << endl;
cout << "第二本书 ID : " << Book2.bookID << endl;
#elif structAsfunPara
//（1）class 中默认的成员访问权限是 private 的，而 struct 中则是 public 的。
//（2）从 class 继承默认是 private 继承，而从 struct 继承默认是 public 继承。
//（3）class 可以定义模板，而 struct 不可以。
Books Book1;        // 定义结构体类型 Books 的变量 Book1
Books Book2;        // 定义结构体类型 Books 的变量 Book2
strcpy_s(Book1.title, "C++ 教程");
strcpy_s(Book1.author, "Runoob");
strcpy_s(Book1.subject, "编程语言");
Book1.bookID = 12345;
strcpy_s(Book2.title, "CSS 教程");
strcpy_s(Book2.author, "Runoob");
strcpy_s(Book2.subject, "前端技术");
Book2.bookID = 12346;
printBook(Book1);
printBook(Book2);

#elif  PointerToStruct 
Books Book1;        // 定义结构体类型 Books 的变量 Book1
Books Book2;        // 定义结构体类型 Books 的变量 Book2
strcpy_s(Book1.title, "C++ 教程");
strcpy_s(Book1.author, "Runoob");
strcpy_s(Book1.subject, "编程语言");
Book1.bookID = 12345;
strcpy_s(Book2.title, "CSS 教程");
strcpy_s(Book2.author, "Runoob");
strcpy_s(Book2.subject, "前端技术");
Book2.bookID = 12346;
printBook1(&Book1);
printBook1(&Book2);
#endif 
	return 0;
}

#if storageClass
void func()
{
	 int i = 5;
	i++;
	cout << "variable i :" << i;
	std::cout << " count value is "<< count1 << std::endl;
}

// do the 2 test, int i with static and without static, without, then cause i is local variable, then in main function, 
// a .i will keep like a constant:
// variable i :6 count value is 9
//variable i : 7 count value is 8
//variable i : 8 count value is 7

//b,  when i is static: 
//variable i : 6 count value is 9
//variable i : 6 count value is 8
//variable i : 6 count value is 7
#elif  pointertoFunc 
double getAverage(int* arr, int size)
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

#elif funcReturnPointer
int* getRandom()
{
	static int  r[10];

	// 设置种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}

#elif referenceInfunc
void swap(int& x, int& y)
{
	int temp;
	cout << "调用的函数中的交换:" << endl;
	cout << x << endl;
	cout << y << endl;
	temp = x; /* 保存地址 x 的值 */
	x = y;    /* 把 y 赋值给 x */
	y = temp; /* 把 x 赋值给 y  */
	cout << x << endl;
	cout << y << endl;
	return;
}
#elif structAsfunPara
void printBook(struct Books book)
{
	cout << "书标题 : " << book.title << endl;
	cout << "书作者 : " << book.author << endl;
	cout << "书类目 : " << book.subject << endl;
	cout << "书 ID : " << book.bookID<< endl;
}
#elif PointerToStruct
void printBook1(struct Books* book)
{
	cout << "书标题  : " << book->title << endl;
	cout << "书作者 : " << book->author << endl;
	cout << "书类目 : " << book->subject << endl;
	cout << "书 ID : " << book->bookID << endl;
}
#endif