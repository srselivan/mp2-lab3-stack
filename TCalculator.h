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
		default: return 0;
		}
	}

	std::string RemoveSpaces(std::string str)
	{
		std::string output;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ') output += str[i];
		}
		return output;
	}

public:

	double calc()
	{
		if (!CheckExpr())
			throw "INCORRECT EXPR";

		std::string infix = "(" + expr + ")";
		stack_char.Clear();
		stack_double.Clear();
		infix = RemoveSpaces(infix);

		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] == '(')
			{
				stack_char.Push(infix[i]);
				continue;
			}

			if ( ('0' <= infix[i] && infix[i] <= '9') || infix[i] == 'x')
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
				if (infix.substr(i, 4) == "sin(" || infix.substr(i, 4) == "cos(" || infix.substr(i, 4) == "tan(")
				{
					stack_char.Push(infix[i]);
					i += 3;
					continue;
				}
				throw "INCORRECT EXPR";
			}

			if (infix[i] == ')')
			{

				while (stack_char.Top() != '(' && stack_char.Top() != 's' && stack_char.Top() != 'c' && stack_char.Top() != 't')
				{
					double a;
					double b;
					try {
						a = stack_double.Pop();
						b = stack_double.Pop();
					}
					catch (int)
					{
						throw "INCORRECT EXPR";
					}
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

			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^')
			{
				while (Priority(stack_char.Top()) >= Priority(infix[i]))
				{
					double a;
					double b;
					try {
						a = stack_double.Pop();
						b = stack_double.Pop();
					}
					catch (int)
					{
						throw "INCORRECT EXPR";
					}
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

	void ToPostfix()
	{
		std::string infix = "(" + expr + ")";
		stack_char.Clear();
		stack_double.Clear();

		for (int i = 0; i < infix.size(); i++)
		{
			try
			{
				if ('0' <= infix[i] && infix[i] <= '9') postfix += infix[i];
				if (infix[i] == '(') stack_char.Push(infix[i]);
				if (infix[i] == ')')
				{
					while (stack_char.Top() != '(')
						postfix += stack_char.Pop();
					stack_char.Pop();
				}
				while (Priority(stack_char.Top()) <= Priority(infix[i]))
				{
					postfix += stack_char.Pop();
				}
				stack_char.Pop();
			}
			catch (int)
			{

			}
		}
	}

};

