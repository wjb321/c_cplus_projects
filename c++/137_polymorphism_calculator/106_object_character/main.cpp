#include "iostream"
#include "string"
using namespace std;
class Calculator
{
public:
	float getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		else if (oper == "/" && m_Num2 != 0)
		{
			return m_Num1 / m_Num2; 
		}
		//如果想扩展新的功能，需求修改源码
		//但是在开发中要有开闭原则，即扩展进行开发，对修改进行关闭
	}

	float m_Num1;
	float m_Num2;
};


class AbstractCal
{
public:
	virtual float getfinalResult()
	{
		return 0;
	}
	float m_num1;
	float m_num2;
};

class AddCalculator : public AbstractCal
{
public:
	float getfinalResult()
	{
		return m_num1 + m_num2;
	}
};

class SubCalculator : public AbstractCal
{
public:
	float getfinalResult()
	{
		return m_num1 - m_num2;
	}
};

class MulCalculator : public AbstractCal
{
public:
	float getfinalResult()
	{
		return m_num1 * m_num2;
	}
};

class DivCalculator : public AbstractCal
{
public:
	float getfinalResult()
	{
		return m_num1 / m_num2;
	}
};
void test01()
{  
	//创建计算器对象、
	Calculator cal;
	cal.m_Num1 = 10.1;
	cal.m_Num2 = 20.0;
	cout << cal.m_Num1 << "+" << cal.m_Num2 << "=" << cal.getResult("+") << endl;
	cout << cal.m_Num1 << "-" << cal.m_Num2 << "=" << cal.getResult("-") << endl;
	cout << cal.m_Num1 << "*" << cal.m_Num2 << "=" << cal.getResult("*") << endl;
	cout << cal.m_Num1 << "/" << cal.m_Num2 << "=" << cal.getResult("/") << endl;


}


void test02()
{
	AbstractCal * abc = new AddCalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 20;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getfinalResult() << endl;
	//用完后进行销毁
	delete abc;
    
	abc = new SubCalculator;
	abc->m_num1 = 20.0;
	abc->m_num2 = 5.0;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getfinalResult() << endl;

	delete abc;

	abc = new MulCalculator;
	abc->m_num1 = 20.0;
	abc->m_num2 = 5.1;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getfinalResult() << endl;


	delete abc;

	abc = new DivCalculator;
	abc->m_num1 = 22.3;
	abc->m_num2 = 5.1;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getfinalResult() << endl;

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}















































