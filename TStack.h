#pragma once
#include <iostream>

template <class T>
class TStack
{
	int Size;
	T* stack;
	int NumLast;

public:

	TStack(int Size = 10) : Size(Size), NumLast(-1)
	{
		if (Size < 0)
			throw Size;
		stack = new T[Size];
	}

	TStack(const TStack<T>& ts) : Size(ts.Size), NumLast(ts.NumLast)
	{
		stack = new T[Size];
		for (int i = 0; i <= NumLast; i++)
		{
			stack[i] = ts.stack[i];
		}
	}

	friend std::ostream& operator<< (std::ostream& ostr, const TStack& ts)
	{
		for (int i = 0; i <= ts.NumLast; i++)
			ostr << ts.stack[i] << " ";
		return ostr;
	}

	bool Is_empty() const //проверка на пустоту
	{
		return (NumLast == -1);
	}

	bool Is_full() const //проверка на полноту
	{
		return (NumLast == Size - 1);
	}

	bool operator== (const TStack& ts) const
	{
		if (NumLast != ts.NumLast) return false;
		for (int i = 0; i <= NumLast; i++)
			if (stack[i] != ts.stack[i]) return false;
		return true;
	}

	bool operator!= (const TStack& ts) const
	{
		return !(*this == ts);
	}

	void Clear()
	{
		NumLast = -1;
	}

	void Push(const T& elem)
	{
		if (Is_full())
			throw NumLast;
		stack[++NumLast] = elem;
	}

	T& Pop()
	{
		if (Is_empty())
			throw NumLast;
		return stack[NumLast--];
	}

	T& Top() const
	{
		if (Is_empty())
			throw NumLast;
		return stack[NumLast];
	}

	~TStack()
	{
		delete[] stack;
	}
};

