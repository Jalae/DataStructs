/******************************************************************************
*Author:		Kehnin Dyer
*File name:		ShellSort.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
*					:see git commits for more details
******************************************************************************/
#pragma once

template <typename T>
void shellsort(T & ary, int size)
{
	int space(1);
	while(space < (size / 3))
		space = space * 3 + 1;
	while(space >= 1)//each i in space
	{

		for(int i(space); i < size; i=i+space) 
		{
			int temp = ary[i];//grr
			int j(i);
			for(j; j >= space && ary[j-space] > temp; j -= space)
					ary[j] = ary[j-space];
			ary[j] = temp;
		}
		space = (space - 1) / 3;
	}
}
