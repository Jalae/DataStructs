

#pragma once

template <typename T>
class abs_LinkedList;
template <typename T>
class DoubleLinkedList;

template <typename T>
class Node
{
	friend class abs_LinkedList<T>;
	friend class DoubleLinkedList<T>;
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