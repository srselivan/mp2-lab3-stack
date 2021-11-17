#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "TStack.h"
 
class TCalculator
{
	std::string expr;
	std::string postfix;
	TStack<char> stack_char;
	TStack<double> stack_double;

	bool CheckExpr()
	{
		TStack<char> symbols(expr.length());
		try
		{
			for (char elem : expr)
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

public:

	double calc()
	{
		if (!CheckExpr())
			throw "INCORRECT EXPR";

		std::string infix = "(" + expr + ")";
		stack_char.Clear();
		stack_double.Clear();

		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] == '(')
			{
				stack_char.Push(infix[i]);
				continue;
			}

			if ('0' <= infix[i] && infix[i] <= '9' || infix[i] == 'x')
			{
				if (infix[i] == 'x')
				{
					double x;
					std::cin >> x;
					stack_double.Push(x);
				}
				else
				{
					size_t index = i;
					stack_double.Push(std::stod(&infix[i], &index));
					i += index - 1;
				}
				continue;
			}

			if (infix[i] == 's' || infix[i] == 'c' || infix[i] == 't')
			{
				switch (infix[i])
				{
				case 's':
					if (infix.substr(i, 4) == "sin(")
					{
						stack_char.Push(infix[i]);
						i += 3;
					}
					else throw "INCORRECT EXPR";
					break;
				case 'c':
					if (infix.substr(i, 4) == "cos(")
					{
						stack_char.Push(infix[i]);
						i += 3;
					}
					else throw "INCORRECT EXPR";
					break;
				case 't':
					if (infix.substr(i, 3) == "tg(")
					{
						stack_char.Push(infix[i]);
						i += 2;
					}
					else throw "INCORRECT EXPR";
					break;
				default:
					break;
				}
				continue;
			}

			if (infix[i] == ')')
			{
				if (stack_char.Top() == 's' || stack_char.Top() == 'c' || stack_char.Top() == 't')
				{
					switch (stack_char.Pop())
					{
					case 's':
						stack_double.Push(sin(stack_double.Pop()));
						break;
					case 'c':
						stack_double.Push(cos(stack_double.Pop()));
						break;
					case 't':
						stack_double.Push(tan(stack_double.Pop()));
						break;
					default:
						break;
					}
					continue;
				}

				while (stack_char.Top() != '(' && stack_char.Top() != 's' && stack_char.Top() != 'c' && stack_char.Top() != 't')
				{
					double a = stack_double.Pop();
					double b = stack_double.Pop();
					switch (stack_char.Pop())
					{
					case'+':
						stack_double.Push(b + a);
						break;
					case'*':
						stack_double.Push(b * a);
						break;
					case'/':
						if (a == 0)
							throw "INCORRECT EXPR: DEVIDE BY ZERO";
						stack_double.Push(b / a);
						break;
					case'-':
						stack_double.Push(b - a);
						break;
					case'^':
						stack_double.Push(pow(b,a));
						break;
					default:
						break;
					}
				}
				stack_char.Pop();
				continue;
			}

			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^')
			{
				while (Priority(stack_char.Top()) >= Priority(infix[i]))
				{
					double a = stack_double.Pop();
					double b = stack_double.Pop();
					switch (stack_char.Pop())
					{
					case'+':
						stack_double.Push(b + a);
						break;
					case'*':
						stack_double.Push(b * a);
						break;
					case'/':
						stack_double.Push(b / a);
						break;
					case'-':
						stack_double.Push(b - a);
						break;
					case'^':
						stack_double.Push(pow(b, a));
						break;
					default:
						break;
					}
				}
				stack_char.Push(infix[i]);
				continue;
			}
		}
		if (stack_double.Is_empty())
			throw "CALC ERROR";
		return stack_double.Pop();
	}

	void SetExpr(std::string _expr) { expr = _expr; }

	std::string GetExpr() const { return expr; }

	int Priority(char op)
	{
		switch (op)
		{
			case '(': return 0;
			case '+': return 1;
			case '-': return 1;
			case '*': return 2;
			case ':': return 2;
			case '^': return 3;		
		}
	}

	void ToPostfix()
	{
		std::string infix = "(" + expr + ")";
		stack_char.Clear();
		stack_double.Clear();

		for (auto elem : infix)
		{
			if ('0' <= elem && elem <= '9') postfix += elem;
			if (elem == '(') stack_char.Push(elem);
			if (elem == ')')
			{
				while (stack_char.Top() != '(')
					postfix += stack_char.Pop();
				stack_char.Pop();
			}
			while (Priority(stack_char.Top()) <= Priority(elem))
			{
				postfix += stack_char.Pop();
			}
			stack_char.Pop();
		}
	}
























	/*
	Перевод с префиксной в постфиксную
	----------------------------------
	
	
	
	
	
	
	
	*/



	// задавать, проверка на корректность | set / get / check
	// оформить класс, проверка корректности и метод счёта
};

