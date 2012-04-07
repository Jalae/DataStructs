/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Array2DTestFunc.h
*Date Created:	2012/04/06
*Modifed:		2012/04/06
******************************************************************************/

#ifndef ARRAY2DTESTFUNC_H_
#define ARRAY2DTESTFUNC_H_

#include "../Utils/k_string.h"
#include "Array2d.h"

template<typename T>
bool Array2DTest_AccessNoElement()
{
	Array2D<T> a;
	try
	{
		a[0][0];
	}
	catch(Exception e)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Array2DTest_IncreaseRow()
{
	Array2D<T> a;
	a.setRow(5);
	return a.getRow() == 5;
}

template<typename T>
bool Array2DTest_DecreaseRow()
{
	Array2D<T> a(10,1);
	a.setRow(5);
	return a.getRow() == 5;
}

template<typename T>
bool Array2DTest_IncreaseColumn()
{
	Array2D<T> a;
	a.setColumn(5);
	return a.getColumn() == 5;
}

template<typename T>
bool Array2DTest_DecreaseColumn()
{
	Array2D<T> a(1,10);
	a.setColumn(5);
	return a.getColumn() == 5;
}

template<typename T>
bool Array2DTest_Assignment(T const & instance, size_t row, size_t col)
{
	bool Passed = true;
	Array2D<T> a(row, col);
	for(size_t i(0); i < a.getRow(); i++)
		for (size_t j(0); j < a.getColumn(); j++)
			a[i][j] = instance;
	size_t len(0);
	for(size_t i(0); i < a.getRow() && Passed; i++)
		for(size_t j(0); j < a.getColumn() && Passed; len++, j++ )
			Passed = a[i][j] == instance;
	return Passed && (len == (row*col));
}

template<typename T>
bool Array2DTest_AssignFromConst(T const & instance)
{
	Array2D<T> a(5, 5);
	for(size_t i(0); i < 5; i++)
		for(size_t j(0); j < 5; j++)
			a[i][j] = instance;
	//B will be a read only copy
	Array2D<T> const B(a);
	bool passed(true);
	for(size_t i(0); (i < 5) && passed; i++)
		for(size_t j(0); (j < 5) && passed; j++)
			passed = instance == B[i][j];
	
	return passed;

}


template<typename T>
bool Array2DTest_CopyConstructor(Array2D<T> const & instance)
{
	Array2D<T> a(instance);
	bool pass =		(a.getRow() == instance.getRow())
				 && (a.getColumn() == instance.getColumn())
				 && (&a != &instance);
	a.setRow(instance.getRow()+5);
	pass =  pass && (a.getRow() == (instance.getRow() + 5) );
	return pass;
}

template<typename T>
bool Array2DTest_OutofBoundsAssignmentRow()
{
	Array2D<T> a(5, 5);
	try
	{
		a[a.getRow()+1] [1];
	}
	catch(Exception e)
	{
	 return k_strcmp(e.what(),"Invalid Row index");
	}
	return false;
}

template<typename T>
bool Array2DTest_OutofBoundsAssignmentColumn()
{
	Array2D<T> a(5, 5);
	try
	{
		a[1][a.getColumn()+1];
	}
	catch(Exception e)
	{
	 return k_strcmp(e.what(),"Invalid Column index");
	}
	return false;
}


template<typename T>
bool Array2DTest_SelfAssignment()
{
	Array2D<T> a(5,1);
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
