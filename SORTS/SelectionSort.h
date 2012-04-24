/******************************************************************************
*Author:		Kehnin Dyer
*File name:		selectionSort.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/
#pragma once

template <typename T>
void selectionsort(T & ary, int size)
{
	for(int i(0); i < (size-1); i++)
	{
		int j(0);
		int max(0);
		for(; j < (size-i); j++)
		{
			if(ary[j] > ary[max])
					max = j;
		}
		swap(ary[j-1], ary[max]);
	}
}
