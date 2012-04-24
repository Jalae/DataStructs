/******************************************************************************
*Author:		Kehnin Dyer
*File name:		MergeSort.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					:see git commits for more details
******************************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma once



template <typename T>
void merge(T & ary, T & temp, int left, int right, int right_end)
{

	int left_end(right - 1),
		start(left),
		temp_pos(left),
		size(right_end - left + 1);
	while((left < left_end) && (right < right_end))
	{
		if(ary[left] <= ary[right])
		{
			temp[temp_pos++] = ary[left++];
		}
		else
		{
			temp[temp_pos++] = ary[right++];
		}
	}
	for(int i(left); left <= left_end; left++)
		temp[temp_pos++] = ary[left];
	for(int i(right); right <= right_end; right++)
		temp[temp_pos++] = ary[right];

	for(int i(start); i < size; i++)
		ary[i] = temp[i];
}

template <typename T>
void mergesort(T & ary, T & temp, int left, int right)
{
	if((right-left) > 1)
	{
		int mid = (left + right) / 2;
		mergesort(ary, temp, left, mid);
		mergesort(ary, temp, mid+1, right);
		merge(ary, temp, left, mid+1, right);
	}
}

template <typename T>
void mergesort(T & ary, int size)
{
	T temp(ary);
	mergesort(ary, temp, 0, size-1);
}

