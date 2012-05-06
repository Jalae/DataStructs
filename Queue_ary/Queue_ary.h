/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Queue_ary.h
*Date Created:	2012/04/30
*Modifed:		2012/04/30
******************************************************************************/

#pragma once
#include "../ArrayClass/Array.h"


/******************************************************************************
		void Enqueue(T const & d)
		- Puts the data item at the end (tail) of the queue.
		T const & Dequeue()
		- Removes and returns the data item at the front of the queue.
		T const & Front()
		- Returns a reference to the data at the front of the queue. 
		  This will allow the consumer to modify the element at the front of the queue.
		size_t Size()
		– Returns the number of items currently in the queue.
		bool isEmpty()
		- Returns true if the stack is empty.
		bool isFull()
		- Returns true if the queue is full.
******************************************************************************/
template <typename T>
class Queue_ary
{
private:
	Array<T> ary;
	int start;
	int num;
public:
	Queue_ary(int size = 0):start(0),num(0)
	{
		ary.setLength(size);
	}
	Queue_ary(Queue_ary const & rhs):start(rhs.start),num(rhs.num)
	{
		ary = rhs.ary;
	}
	~Queue_ary()
	{
		start = 0;
		num = 0;
		ary.setLength(0);
	}
	Queue_ary const & operator=(Queue_ary const & rhs)
	{
		start = rhs.start;
		num = rhs.num;
		ary = rhs.ary;
	}

	void Enqueue(T const & d)
	{
		if(isFull())
			throw("Enqueue Failed: Queue Full");
		ary[(start+num>=ary.getLength()?(start+num-ary.getLength()):(start+num))] = d;
		++num;
	}
	
	T const & Dequeue()
	{
		if(isEmpty())
			throw("Dequeue Failed: Queue Empty");
		T d =  ary[start];
		start = ((++start==ary.getLength())?(0):(start));
		--num;
		return d;
	}

	T const & Front()
	{
		if(isEmpty())
			throw("Front Failed: Queue Empty");
		return ary[start];
	}

	size_t Size()
	{
		return num;
	}

	bool isEmpty()
	{
		return num == 0;
	}

	bool isFull()
	{
		return num == ary.getLength();
	}

};