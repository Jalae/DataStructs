/******************************************************************************
*Author:		Kehnin Dyer
*File name:		QuickSort.h
*Date Created:	2011/02/015 //i wrote this in 126 a year ago for fun. so ima
*							use it
*Modifed:		
******************************************************************************/
#pragma once





//T must have '[]' and T[n] must have '<' and '=='
template <typename T>
void quicksort(T & ary, size_t first, size_t last)
{
	if(last-first==1)
	{
		if(ary[last]<ary[first])
			swap(ary[last], ary[first]);
		return;
	}

	size_t pivot(first);
	size_t i(pivot+1);
	size_t j(last);
	while(i <= j)
	{
		while(i <= j && ary[i] <= ary[pivot])
			i++;
		while(i <= j && ary[pivot] <= ary[j])
			j--;
		if(i<j)
			swap((ary[i]), (ary[j]));
		i++; //without this it inf loops when 2 are the same.
	}
	size_t diff = j-first;
	swap(ary[pivot],ary[j]);
	if (diff>1)
		quicksort(ary, first, j-1);
	diff=last-j;
	if (diff>1)
		quicksort(ary, j+1, last);
	return;
}


template <typename T> 
void quicksort(T & ary, size_t size)
{
	quicksort (ary, 0, size-1);
	return;
}
