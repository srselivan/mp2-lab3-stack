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
		TStack<char> symbols(_expr.length());
		try
		{
			for (char elem : _expr)
			{
				if (elem == '(') symbols.Push(elem);
				if (elem == ')') symbols.Pop();
			}
			return symbols.Is_empty();
		}
		catch (int)
		{
			return false;
		}
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

	void SetExpr(std::string _expr) { expr = _expr; }

	std::string GetExpr() const { return expr; }






























	// задавать, проверка на корректность | set / get / check
	// оформить класс, проверка корректности и метод счёта
};

