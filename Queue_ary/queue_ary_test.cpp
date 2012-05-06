/******************************************************************************
*Author:		Kehnin Dyer
*File name:		queue_ary_test.cpp
*Date Created:	2012/04/30
*Modifed:		2012/04/30
*
*Overview:		This assinment is to make a queue using my array class
*
*Input:			None
*
*Output:		pushes values on the queue until it is full, trys once more,
				and prints out the error. peeks the first value on the queue
				(10) and then tests cirularness of the queue by poping several
				values, then refilling the queue. then every value in the 
				queue is popped, then trys to pop once more and shows the error
******************************************************************************/
#include <iostream>
#include "Queue_ary.h"

int main()
{
	Queue_ary<int> test(10);
	int i = 10;
	while(!test.isFull())
		test.Enqueue(i--);
	try
	{
		test.Enqueue(i);
	}
	catch(char* i)
	{
		std::cout << i << "\n\n";
	}
	std::cout << test.Front() << " " << test.Size() << "\n\n";
	
	//test circularness
	for(int i = 0; i < 6; ++i)
		std::cout << test.Dequeue() << " ";
	while(!test.isFull())
		test.Enqueue(i--);
	std::cout << "\n";
	
	//print out the whole queue
	while(!test.isEmpty())
		std::cout << test.Dequeue() << " ";
	try
	{
		test.Dequeue();
	}
	catch(char* i)
	{
		std::cout << "\n\n" << i;
	}

	std::cin.ignore();
}
