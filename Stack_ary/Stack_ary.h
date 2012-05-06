/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack_ary.h
*Date Created:	2012/04/30
*Modifed:		2012/04/30
******************************************************************************/


#pragma once

#include "../ArrayClass/Array.h"

/******************************************************************************
*	void Push(T const &)
*	- Pushes its parameter onto the top of the stack.
*	T const & Pop()
*	- Removes and returns the data from the top of the stack
*	T const & Peek()
*	- Returns the element on the top of the stack but does not remove it.
*	size_t Size()
*	– Returns the number of items currently on the stack.
*	bool isEmpty()
*	– Returns true if the stack is empty.
*	bool isFull()
*	– Returns true if the stack is full.
******************************************************************************/


template <typename T>
class Stack_ary
{
private:
Array<T> ary;
// ary knows our max so we don't need it here.
int top;

public:
	Stack_ary(size_t size = 0):top(0)
	{
		ary.setLength(size);
		ary.setStartIndex(0);
	}
	Stack_ary(Stack_ary const & rhs)
	{
		*this = rhs;
	}
	~Stack_ary()
	{
		ary.setLength(0);
		top = 0;
	}
	Stack_ary & operator=(Stack_ary const & rhs)
	{
		ary = rhs.ary;//Array<> handles the deep copy for us;
		top = rhs.top;
	}

	void Push(T const & d)
	{
		if(isFull())
			throw("Push Failed: Stack Full");
		ary[top++] = d;
	}

	T const & Pop()
	{
		if(isEmpty())
			throw("Pop Failed: Stack Empty");
		return ary[--top];
	}
	
	T const & Peek()
	{
		if(isEmpty())
			throw("Peek Failed: Stack Empty");
		return ary[top-1];
	}

	size_t Size()
	{
		return top;
	}

	bool isEmpty()
	{
		return top == 0;
	}

	bool isFull()
	{
		return top == ary.getLength();
	}

};
