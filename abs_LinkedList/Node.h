/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Node.h
*Date Created:	2012/05/03
*Modifed:		2012/04/04
******************************************************************************/
#pragma once

template <typename T>
class abs_LinkedList;
template <typename T>
class DoubleLinkedList;
template <typename T>
class Stack_list;
class Iterator;
class fwdIterator;
class bkwIterator;

template <typename T>
class Node
{
	friend class abs_LinkedList<T>;
	friend class DoubleLinkedList<T>;
	friend class Stack_list<T>;
	friend class abs_LinkedList<T>::Iterator;
	friend class abs_LinkedList<T>::fwdIterator;
	friend class abs_LinkedList<T>::bkwIterator;
	T Data;
	Node * Next;
	Node * Previous;

	Node():Next(nullptr),Previous(nullptr)
	{
	}
	Node(T const & D):Next(nullptr),Previous(nullptr), Data(D)
	{
	}
	Node(Node const & rhs):Next(nullptr),Previous(nullptr), Data(rhs.Data)
	{
	}
	Node & operator=(Node const & rhs)
	{
		Data = rhs.Data;
		return *this;
	}
public:
	~Node()
	{
	}
	

	T & operator=(T const & rhs)
	{
		Data = rhs;
		return Data;
	}
	T const & operator=(T const & rhs) const
	{
		return Data;
	}



};