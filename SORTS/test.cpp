/******************************************************************************
*Author:		Kehnin Dyer
*File name:		test.cpp
*Date Created:	2012/04/19
*Modifed:		2012/04/20 - functionally complete
*					
******************************************************************************/


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();

#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <fstream>


#include "auxfunc.h"
#include "../Utils/k_string.h"
#include "../ArrayClass/Array.h"
#include "../ArrayClass/Exception.h"
#include "BubbleSort.h"
#include "FlaggedBubbleSort.h"
#include "HeapSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "ShellSort.h"

using std::ofstream;
using std::vector;
using std::cout;
//int const LEN = 10;

double clkdiffms(clock_t c1, clock_t c2)
{
	return ((c2 - c1)*1000)/CLOCKS_PER_SEC;
}

void main(int argc, char * argv[] )
{
	size_t const LEN (atoi(argv[1]));
	std::cout << LEN;
	unsigned int SEED = time(NULL);
	srand(SEED);
	vector<int> x(LEN);
	for(size_t i(0); i < LEN; i++)
	{
		x[i] = rand();
	}
	clock_t start;
	clock_t end;
	ofstream fout("output.txt");
	/*
	{
		//bf bubble sort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];
		
		for(size_t i(0); i < LEN; i++)
		{
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			bfbubblesort(v, LEN);
		end = clock();
		fout << "\nBrute force bubble sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nBrute force bubble sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i += 1000)
			fout << " " << v[i] << " ";
		start = clock();
			bfbubblesort(a, LEN);
		end = clock();
		fout << "\nBrute force bubble sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nBrute force bubble sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			bfbubblesort(c, LEN);
		end = clock();
		fout << "\nBrute force bubble sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nBrute force bubble sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//flagged bubble sort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];

		for(size_t i(0); i < LEN; i++)
		{
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			flaggedbubblesort(v, LEN);
		end = clock();
		fout << "\nFlagged bubble sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nFlagged bubble sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			flaggedbubblesort(a, LEN);
		end = clock();
		fout << "\nFlagged bubble sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nFlagged bubble sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			flaggedbubblesort(c, LEN);
		end = clock();
		fout << "\nFlagged bubble sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nFlagged bubble sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//selection sort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];

		for(size_t i(0); i < LEN; i++)
		{
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			selectionsort(v, LEN);
		end = clock();
		fout << "\nselection sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nselection sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			selectionsort(a, LEN);
		end = clock();
		fout << "\nselection sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nselection sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			selectionsort(c, LEN);
		end = clock();
		fout << "\nselection sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\nselection sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//selection sort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];

		for(size_t i(0); i < LEN; i++)
		{
			
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			insertionsort(v, LEN);
		end = clock();
		fout << "\ninsertion sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\ninsertion sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			insertionsort(a, LEN);
		end = clock();
		fout << "\ninsertion sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\ninsertion sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			insertionsort(c, LEN);
		end = clock();
		fout << "\ninsertion sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		cout << "\ninsertion sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//shell sort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];
		for(size_t i(0); i < LEN; i++)
		{
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			shellsort(v, LEN);
		end = clock();
		 fout << "\nshellsort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			shellsort(a, LEN);
		end = clock();
		 fout << "\nshellsort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			shellsort(c, LEN);
		end = clock();
		 fout << "\nshellsort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}*/
	{
		//mergesort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];
		
		 
		for(size_t i(0); i < LEN; i++)
		{
			
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			mergesort(v, LEN);
		end = clock();
		 fout << "\nmerge sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			mergesort(a, LEN);
		end = clock();
		 fout << "\nmerge sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			mergesort(c, LEN);
		end = clock();
		 fout << "\nmerge sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//heapsort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];
		
		 
		for(size_t i(0); i < LEN; i++)
		{
			
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			heapsort(v, LEN);
		end = clock();
		 fout << "\nheap sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			heapsort(a, LEN);
		end = clock();
		 fout << "\nheap sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			heapsort(c, LEN);
		end = clock();
		 fout << "\nheap sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	{
		//quicksort
		vector<int> v(LEN);
		Array<int> a(LEN);
		int * c = new int[LEN];
		
		 
		for(size_t i(0); i < LEN; i++)
		{
			
			v[i] = x[i];
			a[i] = x[i];
			c[i] = x[i];
		}
		start = clock();
			quicksort(v, LEN);
		end = clock();
		fout << "\nquick sort<" << "vector" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << v[i] << " ";
		start = clock();
			quicksort(a, LEN);
		end = clock();
		 fout << "\nquick sort<" << "Array" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << a[i] << " ";
		start = clock();
			quicksort(c, LEN);
		end = clock();
		 fout << "\nquick sort<" << "cArray" << ">:" << clkdiffms(start, end) << "\n";
		for(int i(0); i < LEN; i +=1000)
			fout << " " << c[i] << " ";
		delete[] c;
	}
	
	MEMDUMP
	


	std::cin.ignore();
}

