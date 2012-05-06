#pragma once

#include "Node.h"


/******************************************************************************
*
*	bool isEmpty()																X
*		– does the list have any elements in it?
*	T & First()																	X
*		– return a const reference to the first element.
*	T & Last()																	X
*		– return a const reference to the last element.
*	void Prepend(T const &)														X
*		– add an item to the front of the list.
*	void Append(T const &)														X
*		– add an item to the end of the list.
*	void Purge()																X
*		– remove all items from the list.
*		  Throws and exception if there is no match
*	void Extract(T const &)
*		– removes the first item that matches the passed argument from the list.
*		  Throws and exception if there is no match
*	void InsertAfter(T const & d, T const & i)
*		– insert a data item d after the first instance i found.
*		  Throws and exception if there is no match
*	InsertBefore(T const & d, T const & i)
*		– insert a data item d before the first instance i found.
*		  Throws and exception if there is no match
******************************************************************************/

template <typename T>
class abs_LinkedList
{
protected:
	Node<T> * Head;
	Node<T> * Tail;

public:

	 abs_LinkedList():Head(nullptr), Tail(nullptr)
	{
	}
	
	 abs_LinkedList(abs_LinkedList const & that)
	{
		*this = that;
	}
	
	virtual ~abs_LinkedList()
	{
		Purge();
	}

	virtual abs_LinkedList & operator=(abs_LinkedList const & rhs)
	{// needs to deep copy
		for(Node<T>* temp(rhs.Head);temp;temp = temp->Next)
		{
			Append(temp->Data);
		}
		return *this;
	}

	bool isEmpty()
	{
		return (!Head);
	}

	T const & First()const 
	{
		if(Head)
			return Head->Data;
		else throw("First Failed: Empty List");
	}
	T const & Last()const
	{
		if(Tail)
			return Tail->Data;
		else throw("Last Failed: Empty List");
	}

	void Append(T const & d)
	{	
		Node<T>* temp = new Node<T>(d);
		if(Tail)
		{
			temp->Previous = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else
			Head = Tail = temp;
	}
	void Prepend(T const & d)
	{
		Node<T>* temp = new Node<T>(d);
		if(Head)
		{
			Head->Previous = temp;
			temp->Next = Head;
			Head = temp;
		}
		else
			Head = Tail = temp;
	}

	void Purge()
	{
		Node<T> * temp;
		while(Head)
		{
			temp = Head->Next;
			delete Head;
			Head = temp;
		}
		Tail = Head;
	}

	void Extract(T const & i)
	{
		Node<T>* temp = Head;
		if(temp)
		{ //find i in the list, or die trying.
			for(;temp && (temp->Data != i); temp = temp->Next);
		}
		else
			throw("Extraction Failed: Empty List.");
		if(!temp)
			throw("Extraction Failed: Data not found in list.");

		if(temp == Head)
		{
			Head = temp->Next;
			if(Head)
				Head->Previous = nullptr;
			else
			{
				Tail = nullptr;
			}
			delete temp;
		}else if(temp == Tail)
		{
			Tail = temp->Previous;
			Tail->Next = nullptr;
			delete temp;
		} else
		{
			temp->Previous->Next = temp->Next;
			temp->Next->Previous = temp->Previous;
			delete temp;
		}
	}

	void InsertAfter(T const & d, T const & i)
	{
		Node<T>* temp = Head;
		Node<T>* data = new Node<T>(d);
		if(temp)
		{ //find i in the list, or die trying.
			for(;temp && (temp->Data != i); temp = temp->Next);
		}
		else
			throw("Insertion Failed: Empty List.");
		if(!temp)
			throw("Insertion Failed: Data not found in list.");
		if(temp == Tail)
		{
			data->Previous = Tail;
			Tail->Next = data;
			Tail = data;
		}
		else
		{
			data->Previous = temp;
			data->Next = temp->Next;
			temp->Next = data;
			data->Next->Previous = data;
		}
	}
	void InsertBefore(T const & d, T const & i)
	{
		Node<T>* temp = Head;
		Node<T>* data = new Node<T>(d);
		if(temp)
		{ //find i in the list, or die trying.
			for(;temp && (temp->Data != i); temp = temp->Next);
		}
		else
			throw("Insertion Failed: Empty List.");
		if(!temp)
			throw("Insertion Failed: Data not found in list.");
		if(temp == Head)
		{
			data->Next = Head;
			Head->Previous = data;
			Head = data;
		}
		else
		{
			data->Next = temp;
			data->Previous = temp->Previous;
			temp->Previous = data;
			data->Previous->Next = data;
		}
	}
	
};