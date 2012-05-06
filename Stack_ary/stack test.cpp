/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack test.cpp
*Date Created:	2012/04/30
*Modifed:		2012/04/30
*
*Overview:		This assinment is to make a stack using my array class
*
*Input:			None
*
*Output:		pushes values on the stack until it is full, trys once more,
				and prints out the error. peeks the first value on the stack
				(1) and then pops and shows every value on the stack (1->10)
				then trys to pop once more and shows the error
******************************************************************************/
#include <iostream>
#include "Stack_ary.h"

int main()
{
	Stack_ary<int> test(10);
	int i = 10;
	while(!test.isFull())
		test.Push(i--);
	try
	{
		test.Push(0);
	}
	catch(char* a)
	{
		std::cout << a;
	}
	std::cout << "\n\n" << test.Peek() << "\n\n";
	while(!test.isEmpty())
		std::cout << " " << test.Pop();
	try
	{
		test.Pop();
	}
	catch(char* a)
	{
		std::cout << "\n\n" << a;
	}
	std::cin.ignore();


}


