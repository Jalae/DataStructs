/******************************************************************************
*Author:		Kehnin Dyer
*File name:		auxfunc.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/

#pragma once

template <typename T>
void swap(T & elem1, T & elem2)
{
	T tmp(elem2);
	elem2 = elem1;
	elem1 = tmp;
}