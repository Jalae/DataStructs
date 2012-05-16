/******************************************************************************
*Author:		Kehnin Dyer
*File name:		stack test.cpp
*Date Created:	2012/04/30
*Modifed:		2012/04/30
*
*Overview:		This assinment is to make a stack using my Linked list class
*
*Input:			None
*
*Output:		pushes values on the stack peeks the first value on the stack
				(0) and prints the length (11) and then pops and shows every 
				value on the stack (0->10) then trys to pop once more and shows
				the error.
******************************************************************************/
#include <iostream>
#include "Queue_list.h"

int main()
{
	Queue_list<int> test;
	int i = 10;
	for(int i(10); i > 0; i--)
		test.Enqueue(i);

	std::cout << "\n\n" << test.Front() <<" " <<  test.Size() << "\n\n";

	while(!test.isEmpty())
		std::cout << " " << test.Dequeue();
	try
	{
		test.Dequeue();
	}
	catch(char* a)
	{
		std::cout << "\n\n" << a;
	}
	std::cin.ignore();


}


