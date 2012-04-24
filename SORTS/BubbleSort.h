/******************************************************************************
*Author:		Kehnin Dyer
*File name:		BubbleSort.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/
#pragma once

template <typename T>
void bfbubblesort(T & ary, int size)
{
	for(int i(0); i < size; i++)
	{
		for(int j(0); j < (size-1); j++)
		{
			if(ary[j] > ary[j+1])
				swap(ary[j], ary[j+1]);
		}
	}
}
