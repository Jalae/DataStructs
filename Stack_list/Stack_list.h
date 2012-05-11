/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack_list.h
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
*	ÅEReturns the number of items currently on the stack.
*	isEmpty
*	ÅEReturns true if the stack is empty.
*
******************************************************************************/
template <typename T>
class Stack_list:public abs_LinkedList<T>
{
private:
int top;

public:
	Stack_list():top(0)
	{}

	Stack_list(Stack_list const & rhs)
	{*this = rhs;}
	~Stack_list()
	{
		Purge();
		top = 0;
	}
	Stack_list & operator=(Stack_list const & rhs)
	{
		for(Node<T>* temp(rhs.Head);temp;temp = temp->Next)
		{
			Append(temp->Data);
		}
		top = rhs.top;
		return *this;
	}
	void Push(T const & d)
	{
		top++;
		Prepend(d);
	}
	T const Pop()
	{
		if(isEmpty())
			throw("Pop Failed: Stack Empty");
		T val = First();
		Extract(val);
		top--;
		return val;
	}
	T const & Peek()
	{
		if(isEmpty())
			throw("Peek Failed: Stack Empty");
		return First();
	}
	size_t Size()
	{
		return top;
	}
};
