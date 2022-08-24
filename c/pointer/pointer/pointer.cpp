#include"iostream"
using namespace std;
const int MAX = 3;
int main()
{

	int a = 20;  // 定义一个变量
	int * p; // 定义一个指针类型
	p = &a;  // 指针保存变量的地址

	cout << "&a: " << &a << endl;
	cout << "p: " << p << endl;  // p == &a
	cout << "*p: " << *p << endl;  //指针指向保存地址的内容

	//1) null pointer
	int * ptr1 = NULL;  // 大多数操作系统不允许访问地址0的内存，因为是操作系统保留的
	cout << "ptr1 is " << ptr1 << endl;

	//2）
	int var[MAX] = {10, 100, 200};
	int *ptr;
    
	ptr = var;
	for (int i = 0; i < MAX;  i++)
	{
		cout << "address of var [" << i << "]";
		cout << ptr << endl;

		cout << "value of var[" << i << "] = ";
		cout << *ptr << endl;
		ptr++;
	}
	return 0;

}