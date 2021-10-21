#pragma once
#include <iostream>

template <class T>
class TDStack
{
	int NumLast1, NumLast2;
	int Size;
	T* tdstack;

public:

	TDStack(int Size = 10) : Size(Size), NumLast1(-1), NumLast2(Size)
	{
		if (Size < 0)
			throw Size;
		tdstack = new T[Size];
	}

	TDStack(const TDStack<T>& tds) : Size(tds.Size), NumLast1(tds.NumLast1), NumLast2(tds.NumLast2)
	{
		tdstack = new T[Size];
		for (int i = 0; i <= NumLast1; i++)
		{
			tdstack[i] = tds.tdstack[i];
		}
		for (int i = Size - 1; i >= NumLast2; i--)
		{
			tdstack[i] = tds.tdstack[i];
		}
	}

	friend std::ostream& operator<< (std::ostream& ostr, const TDStack& tds)
	{
		for (int i = 0; i <= tds.NumLast1; i++)
		{
			ostr << tds.tdstack[i] << " ";
		}
		ostr << "| ";
		for (int i = tds.Size - 1; i >= tds.NumLast2; i--)
		{
			ostr << tds.tdstack[i] << " ";
		}
		return ostr;
	}

	bool operator== (const TDStack& tds) const
	{
		if (NumLast1 != tds.NumLast1 || NumLast2 != tds.NumLast2) 
			return false;

		for (int i = 0; i <= NumLast1; i++)
			if (tdstack[i] != tds.tdstack[i]) 
				return false;

		for (int i = Size - 1; i >= NumLast1; i--)
			if (tdstack[i] != tds.tdstack[i])
				return false;

		return true;
	}

	bool operator!= (const TDStack& tds) const
	{
		return !(*this == tds);
	}

	bool Is_full()
	{
		return (NumLast2 - NumLast1 == 1);
	}

	bool Is_empty1()
	{
		return NumLast1 == -1;
	}

	bool Is_empty2()
	{
		return NumLast2 == Size;
	}

	void Clear()
	{
		NumLast1 = -1;
		NumLast2 = Size;
	}

	void Clear1()
	{
		NumLast1 = -1;
	}

	void Clear2()
	{
		NumLast2 = Size;
	}

	void Push1(const T& elem)
	{
		if (Is_full())
			throw "Err";
		tdstack[++NumLast1] = elem;
	}

	void Push2(const T& elem)
	{
		if (Is_full())
			throw "Err";
		tdstack[--NumLast2] = elem;
	}

	T& Pop1()
	{
		if (Is_empty1())
			throw "Err";
		return tdstack[NumLast1--];
	}

	T& Pop2()
	{
		if (Is_empty2())
			throw "Err";
		return tdstack[NumLast2++];
	}

	T& Top1()
	{
		if (Is_empty1())
			throw "Err";
		return tdstack[NumLast1];
	}

	T& Top2()
	{
		if (Is_empty2())
			throw "Err";
		return tdstack[NumLast2];
	}

	~TDStack()
	{
		delete[] tdstack;
	}
};

