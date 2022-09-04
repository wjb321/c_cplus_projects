Class objects as class members

c++ 中的类可以是另一个类的对象

class a{};
class b
{
 a a1;
}


类A 是类B的对象，那么会先构造类A 的构造函数
析构函数的释放顺序正好相反

