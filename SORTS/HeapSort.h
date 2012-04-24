/******************************************************************************
*Author:		Kehnin Dyer
*File name:		HeapSort.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
*					:see git commits for more details
******************************************************************************/
#pragma once

inline int leftMember(int x)
{
	return 2*x+1;
}
inline int rightMember(int x)
{
	return 2*x+2;
}

template <typename T>
void moveDown(T & ary, int begin, int end)
{
	
	for(int largest(begin);largest < end;)
	{
		int leftchild = leftMember(largest);
		int rightchild = rightMember(largest);
		if((leftchild < end) && (ary[begin] < ary[leftchild]))
		{
			largest = leftchild;
		}
		if((rightchild < end) && (ary[largest] < ary[rightchild]))
		{
			largest = rightchild;
		}
		if(largest != begin)
		{
			swap(ary[begin],  ary[largest]);
			begin = largest;
		}
		else
			largest = end +1;
			
	}
}

template <typename T>
void makeHeap(T & ary, int size)
{
	for(int i((size-2)/2); i >= 0; i --)
		moveDown(ary, i, size-1);
}

template <typename T>
void heapsort(T & ary, int size)
{
	makeHeap(ary, size);
	for(int i(size-1); i > 0; i--)
	{
		swap(ary[0], ary[i]);
		moveDown(ary, 0, i-1);
	}
	if (ary[0] > ary[1])//do the last swap.
		swap(ary[0], ary[1]);
}
