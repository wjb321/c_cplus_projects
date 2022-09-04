浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作

Shallow copy: a simple assignment copy operation
Deep copy: requesting space in the heap area and and then do a copy operation in the newly allocated space


问题: 堆区开辟的数据需要程序员手动开辟同时也需要程序员手动释放，这是一个必备的流程 a = new int (b)[pointer], return a *. 所以
通常在析构函数上对当时分配的空间进行释放（析构函数的主要作用）
problem:It is a necessary process that the data allocated in the heap area needs to be deleted before the object is destoried.
so the allocated heap memory is freed in deconstructor

