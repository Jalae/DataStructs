/******************************************************************************
*Author:		Kehnin Dyer
*File name:		ArrayTest.cpp
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - changed from linear tests to functional
*
*Overview:		This assinment is to make an Array class for use in other labs
*				and assignments. This program runs all the tests nessicary to 
*				show that this class works as required.
*
*Input:			None
*
*Output:		Tells the user what test is run and whether that test passed 
*				or if it failed,
******************************************************************************/

#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else //i want to compile on both windows and linux
#define MEMDUMP ;
#endif


#include "Array.h"
#include <iostream>
#include "ArrayTestFunc.h"
using std::cout;

int main()
{
	{
		cout << "Testing Accessing of no element(BASIC):";
		cout << (ArrayTest_AccessNoElement<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Accessing of no element(ADVANCED):";
		cout << (ArrayTest_AccessNoElement<Array<int>>()?"PASSED\n":"FAILED\n");

		cout << "Testing Increase Length(BASIC):";
		cout << (ArrayTest_IncreaseLength<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Increase Length(ADVANCED):";
		cout << (ArrayTest_IncreaseLength<Array<int>>()?"PASSED\n":"FAILED\n");

		cout << "Testing Decrease Length(BASIC):";
		cout << (ArrayTest_DecreaseLength<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Decrease Length(ADVANCED):";
		cout << (ArrayTest_DecreaseLength<Array<int>>()?"PASSED\n":"FAILED\n");

		cout << "Testing Assignment(BASIC):";
		cout << (ArrayTest_Assignment<int>(5, 10)?"PASSED\n":"FAILED\n");
		cout << "Testing Assignment(ADVANCED):";
		cout << (ArrayTest_Assignment<Array<int>>(Array<int>(5), 10)?"PASSED\n":"FAILED\n");
		
		cout << "Testing Change Base Higher(BASIC):";
		cout << (ArrayTest_ChangeBase<int>(10)?"PASSED\n":"FAILED\n");
		cout << "Testing Change Base Higher(ADVANCED):";
		cout << (ArrayTest_ChangeBase<Array<int>>(10)?"PASSED\n":"FAILED\n");

		cout << "Testing Change Base Lower(BASIC):";
		cout << (ArrayTest_ChangeBase<int>(-10)?"PASSED\n":"FAILED\n");
		cout << "Testing Change Base Lower(ADVANCED):";
		cout << (ArrayTest_ChangeBase<Array<int>>(-10)?"PASSED\n":"FAILED\n");

		cout << "Testing Copy Constructor(BASIC):";
		cout << (ArrayTest_CopyConstructor<int>(Array<int>(1,0))?"PASSED\n":"FAILED\n");
		cout << "Testing Copy Constructor(ADVANCED):";
		cout << (ArrayTest_CopyConstructor<Array<int>>(Array<Array<int>>(1,0))?"PASSED\n":"FAILED\n");

		cout << "Testing Out of Bounds, Higher(BASIC):";
		cout << (ArrayTest_OutofBoundsAssignment<int>(true)?"PASSED\n":"FAILED\n");
		cout << "Testing Out of Bounds, Higher(ADVANCED):";
		cout << (ArrayTest_OutofBoundsAssignment<Array<int>>(true)?"PASSED\n":"FAILED\n");

		cout << "Testing Out of Bounds, Lower(BASIC):";
		cout << (ArrayTest_OutofBoundsAssignment<int>(false)?"PASSED\n":"FAILED\n");
		cout << "Testing Out of Bounds, Lower(ADVANCED):";
		cout << (ArrayTest_OutofBoundsAssignment<Array<int>>(false)?"PASSED\n":"FAILED\n");

		cout << "Testing Self Assignment(BASIC):";
		cout << (ArrayTest_SelfAssignment<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Self Assignment(ADVANCED):";
		cout << (ArrayTest_SelfAssignment<Array<int>>()?"PASSED\n":"FAILED\n");

	}
	std::cin.ignore();
	MEMDUMP
}

