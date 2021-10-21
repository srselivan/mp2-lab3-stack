#pragma once
#include <iostream>
#include <string>
#include "TStack.h"

class TCalculator
{
	std::string expr;
	std::string postfix;
	TStack<char> stack_char;
	TStack<double> stack_double;

public:

	bool CheckExpr(std::string _expr)
	{
		return 1;
	}

	double calc()
	{
		for (auto elem : postfix)
		{
			if ('0' <= elem <= '9') stack_double.Push(std::stod(&elem));
			if (elem == '+' || elem == '-')
			{
				double a = stack_double.Pop();
				double b = stack_double.Pop();
				switch (elem)
				{
				case'+': 
					stack_double.Push(b + a);
					break;
				case'-':
					stack_double.Push(b - a);
					break;
				default:
					break;
				}
			}
		}
		return stack_double.Pop();
	}






























	// задавать, проверка на корректность | set / get / check
	// оформить класс, проверка корректности и метод счёта
};

