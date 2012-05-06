#pragma once

#include <iostream>
#include "abs_LinkedList.h"


template <typename T>
class DoubleLinkedList:public abs_LinkedList<T>
{
public:
	DoubleLinkedList()
	{

	}
	DoubleLinkedList(DoubleLinkedList const & rhs)
	{
		*this = rhs;
	}
	~DoubleLinkedList()
	{}
	


	void * getHead()
	{
		return Head;
	}

	void * getTail()
	{
		return Tail;
	}

	void PrintForwards()
	{
		Node<T>* temp=Head;
		while(temp)
		{
			std::cout << temp->Data << " ";
			temp = temp->Next;
		}
		std::cout << "\n";
	}
	
	void PrintBackwards()
	{
		Node<T>* temp=Tail;
		while(temp)
		{
			std::cout << temp->Data << " ";
			temp = temp->Previous;
		}
		std::cout << "\n";
	}

};