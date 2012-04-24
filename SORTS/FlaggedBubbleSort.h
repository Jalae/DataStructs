/******************************************************************************
*Author:		Kehnin Dyer
*File name:		FlaggedBubbleSort.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/

#pragma once

template <typename T>
void flaggedbubblesort(T & ary, int size)
{
	bool sorted = false;
	for(int i(0); i < size && (!sorted); i++)
	{
		sorted = true;
		for(int j(0); j < (size-i-1); j++)
		{
			if(ary[j] > ary[j+1])
			{
				sorted = false;
				swap(ary[j], ary[j+1]);
			}
		}
	}
}