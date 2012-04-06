/******************************************************************************
*Author:		Kehnin Dyer
*File name:		ArrayTestFunc.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
******************************************************************************/

#ifndef ARRAYTESTFUNC_H_
#define ARRAYTESTFUNC_H_

#include "Array.h"
#include "k_string.h"

template<typename T>
bool ArrayTest_AccessNoElement()
{
	Array<T> a;
	try
	{
		a[0];
	}
	catch(Exception e)
	{
		return true;
	}
	return false;
}

template<typename T>
bool ArrayTest_IncreaseLength()
{
	Array<T> a;
	a.setLength(5);
	return a.getLength() == 5;
}

template<typename T>
bool ArrayTest_DecreaseLength()
{
	Array<T> a(10);
	a.setLength(5);
	return a.getLength() == 5;
}

template<typename T>
bool ArrayTest_Assignment(T const & instance, size_t size)
{
	bool Passed = true;
	Array<T> a(size);
	for(size_t i(0); i < a.getLength(); i++)
	{
		a[i] = instance;
	}
	size_t len(0);
	for(len; len < a.getLength() && Passed; len++)
	{
		Passed = a[len] == instance;
	}
	return Passed && (len == size);
}

template<typename T>
bool ArrayTest_ChangeBase(int b)
{
	Array<T> a(5,0);
	a.setStartIndex(b);
	return a.getStartIndex() == b;
}

template<typename T>
bool ArrayTest_CopyConstructor(Array<T> const & instance)
{
	Array<T> a(instance);
	bool pass =		(a.getLength() == instance.getLength()) 
				 && (a.getStartIndex() == instance.getStartIndex()) 
				 && (&a != &instance);
	a.setLength(instance.getLength()+5);
	pass =  pass && (a.getLength() == (instance.getLength() + 5) );
	return pass;
}

template<typename T>
bool ArrayTest_OutofBoundsAssignment(bool higher)
{
	Array<T> a(5);
	if(higher)
	{
		try
		{
			a[a.getLength()+1];
		}
		catch(Exception e)
		{
			return k_strcmp(e.what(), "Index out of bounds: Greater");
		}
	}
	else
	{
		try
		{
			a[a.getStartIndex()-1];
		}
		catch(Exception e)
		{
			return k_strcmp(e.what(), "Index out of bounds: Lower");
		}
	}
	//what...
	return false;
}

template<typename T>
bool ArrayTest_SelfAssignment()
{
	Array<T> a(5);
	try
	{
		a = a;
	}
	catch(...)
	{
		return false;
	}
	return true;
}

#endif
