静态成员：

静态成员就是在成员变量和成员函数前加上关键字 static， 称为静态成员。
静态成员分为：

静态成员变量
    所有对象共享同一份数据：即一个对象更改数据那么另一个对象使用的也是更改过的数据
	在编译阶段分配内存
    类内声明，类外初始化：必须有一个初始值


静态成员函数
    所有对象共享一个函数
	静态成员函数只能访问静态成员变量
	
