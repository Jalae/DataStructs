/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack_ary.h
*Date Created:	2012/04/30
*Modifed:		2012/04/30
******************************************************************************/


#pragma once

#include "../abs_LinkedList/abs_LinkedList.h"

/******************************************************************************
*	Push
*	- Pushes its parameter onto the top of the stack.
*	Pop
*	- Removes and returns the data from the top of the stack. 
*	Peek
*	- Returns the element on the top of the stack.
*	Size
*	– Returns the number of items currently on the stack.
*	isEmpty
*	– Returns true if the stack is empty.
*
******************************************************************************/


template <typename T>
class Stack_list
{
private:
abs_LinkedList<T> ary;
// ary knows our max so we don't need it here.
int top;

public:
	Stack_list():top(0)
	{
	}

	Stack_list(Stack_list const & rhs)
	{
		*this = rhs;
	}
	~Stack_list()
	{
		ary.Purge();
		top = 0;
	}
	Stack_list & operator=(Stack_list const & rhs)
	{
		ary = rhs.ary;//linkedlist<> handles the deep copy for us;
		top = rhs.top;
	}

	void Push(T const & d)
	{
		top++;
		ary.Prepend(d);
	}

	T const & Pop()
	{
		if(isEmpty())
			throw("Pop Failed: Stack Empty");
		T val = ary.First();
		ary.Extract(val);
		top--;
		return val;
	}
	
	T const & Peek()
	{
		if(isEmpty())
			throw("Peek Failed: Stack Empty");
		return ary.First();
	}

	size_t Size()
	{
		return top;
	}

	bool isEmpty()
	{
		return ary.isEmpty();
	}



};
