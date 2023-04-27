/*there are 4 blocks for memory:
code area: store binary code for functions, managed by os
global area: store global variables and static variable and const
stack area: allocation and free by complier, store the parameters of functions and local variables 
heap area: managed by engineer for allocation and free, if programmer did not free, then when program finished, free by
           os
code area: store cpu machine commands, and this area is sharable, readonly
*/
#include <iostream>
using namespace std;
int g_a = 12;
int g_b = 13;
const int c_g_a = 10;
int main()
{
    int a = 10;
    int b = 13;
    cout << "local a address " << (int)&a << endl;
    cout << "local b address " << (int)&b << endl;

    cout << "global a address " << (int)&g_a << endl;
    cout << "global b address " << (int)&g_b << endl;

    static int s_a = 12;
    static int s_b = 13;

    cout << "static a address " << (int)&s_a << endl;
    cout << "static b address " << (int)&s_b << endl;

    cout << "string address" << (int)&"hello the world" << endl;

    //variable with const
    cout << "global const variable address" << (int)&c_g_a << endl;

    const int c_l_a = 12;
    cout << "local const variable address " << (int)&c_l_a << endl;
    system("pause");
}