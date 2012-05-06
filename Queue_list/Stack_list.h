/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack_ary.h
*Date Created:	2012/04/30
*Modifed:		2012/04/30
******************************************************************************/


#pragma once

#include "../abs_LinkedList/abs_LinkedList.h"

/******************************************************************************
*	void Enqueue(T const & d)
*	- Pushes its parameter onto the top of the stack.
*	T const & Dequeue()
*	- Removes and returns the data from the top of the stack. 
*	T const & Front()
*	- Returns the element on the top of the stack.
*	size_t Size()
*	– Returns the number of items currently on the stack.
*	bool isEmpty()
*	– Returns true if the stack is empty.
*
******************************************************************************/


template <typename T>
class Queue_list
{
private:
abs_LinkedList<T> ary;
// ary knows our max so we don't need it here.
int num;

public:
	Queue_list():num(0)
	{
	}

	Queue_list(Queue_list const & rhs)
	{
		*this = rhs;
	}
	~Queue_list()
	{
		ary.Purge();
		num = 0;
	}
	Queue_list & operator=(Queue_list const & rhs)
	{
		ary = rhs.ary;//linkedlist<> handles the deep copy for us;
		num = rhs.top;
	}

	void Enqueue(T const & d)
	{
		num++;
		ary.Append(d);
	}

	T const & Dequeue()
	{
		if(isEmpty())
			throw("Pop Failed: Stack Empty");
		T val = ary.First();
		ary.Extract(val);
		num--;
		return val;
	}
	
	T const & Front()
	{
		if(isEmpty())
			throw("Peek Failed: Stack Empty");
		return ary.First();
	}

	size_t Size()
	{
		return num;
	}

	bool isEmpty()
	{
		return ary.isEmpty();
	}



};
