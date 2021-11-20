#include <iostream>
#include <string>
#include "TStack.h"
#include "TCalculator.h"
#include "TDStack.h"

void main()
{
	/*TDStack<int> tds(12);
	tds.Push1(1);
	tds.Push1(2);
	tds.Push1(3);
	tds.Push1(4);
	tds.Push2(21);
	tds.Push2(22);
	tds.Push2(23);
	tds.Push2(24);
	std::cout << tds << std::endl;
	tds.Pop1();
	tds.Pop1();
	tds.Pop2();
	tds.Pop2();
	std::cout << tds << std::endl;

	std::cout << tds.Top1() << " " << tds.Top2() << std::endl;
	

	TDStack<int> _tds(12);
	_tds.Push1(1);
	_tds.Push1(2);
	_tds.Push2(21);
	_tds.Push2(22);
	_tds.Push2(23);
	_tds.Push2(24);
	bool res = tds == _tds;
	std::cout << res << std::endl;

	_tds.Clear1();
	std::cout << _tds << std::endl;*/

	//// 1)
	//TStack<int> st(10);
	//int i = 0;
	//while (!st.Is_full())
	//{
	//	st.Push(i++);
	//}
	//std::cout << "STACK: " << st << std::endl;
	//while (!st.Is_empty())
	//{
	//	st.Pop();
	//}
	//std::cout << "AFTER POP: " << st << std::endl;
	//
	//// 2)
	//std::string str;
	//getline(std::cin, str);
	//TStack<char> symbols(str.length());

	//try
	//{
	//	for (char elem : str)
	//	{
	//		if (elem == '(') symbols.Push(elem);
	//		if (elem == ')') symbols.Pop();
	//	}
	//	if (symbols.Is_empty()) std::cout << std::endl << "CORRECT" << std::endl;
	//	else std::cout << std::endl << "INCORRECT" << std::endl;
	//}
	//catch (int)
	//{
	//	std::cout << std::endl << "INCORRECT" << std::endl;
	//}

	std::string tmp = "1 + sin(0 + 1^4 + (9*2) + (2)) + cos(x^4)";
	TCalculator calc;
	calc.SetExpr(tmp);
	try
	{
		double res = calc.calc();
		std::cout << res;
	}
	catch (const char* ex)
	{
		std::cout << ex;
	}
	
}