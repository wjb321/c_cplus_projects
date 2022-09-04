构造函数调用规则：

默认情况下，一个类至少含有三个函数：
1. 默认构造函数（无参，函数体为空）
2. 默认析构函数（无参，函数体为空）
3. 默认拷贝构造函数， 堆属性进行值拷贝

构造函数调用规则：

1. If the user defines a reference constructor, 
   then c++ will not provide a default non-parameter constructor but will provide a default copy constructor

2. If the user defines a copy constructor, then c++ does not provide other constructors(constructor, destructor)
 