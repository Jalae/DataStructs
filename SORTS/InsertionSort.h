/******************************************************************************
*Author:		Kehnin Dyer
*File name:		ShellSort.h
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/
#pragma once


template <typename T>
void insertionsort(T & ary, int size)
{
	for(int i(1); i < size; i++)
	{
		int temp = ary[i];
		int j(i);
		while((j > 0) && (temp < ary[j-1]))
		{
			ary[j] = ary[j-1];
			j--;
		}
		ary[j] = temp;
	}

}
