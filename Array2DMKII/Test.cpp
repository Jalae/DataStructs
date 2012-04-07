/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Test.cpp
*Date Created:	2012/04/06
*Modifed:		2012/04/06
*
*Overview:		This assinment is to make an Array2D for use in other labs
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


#include "Array2D.h"
#include "Array2DTestFunc.h"

#include <iostream>
#include <string>
using std::cout;
using std::string;//for testing

int main()
{
	{
		cout << "Testing Accessing of no element(BASIC):";
		cout << (Array2DTest_AccessNoElement<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Accessing of no element(ADVANCED):";
		cout << (Array2DTest_AccessNoElement<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Increase Row(BASIC):";
		cout << (Array2DTest_IncreaseRow<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Increase Row(ADVANCED):";
		cout << (Array2DTest_IncreaseRow<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Increase Column(BASIC):";
		cout << (Array2DTest_IncreaseColumn<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Increase Column(ADVANCED):";
		cout << (Array2DTest_IncreaseColumn<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Decrease Row(BASIC):";
		cout << (Array2DTest_DecreaseRow<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Decrease Row(ADVANCED):";
		cout << (Array2DTest_DecreaseRow<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Decrease Column(BASIC):";
		cout << (Array2DTest_DecreaseRow<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Decrease Column(ADVANCED):";
		cout << (Array2DTest_DecreaseRow<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Assignment(BASIC):";
		cout << (Array2DTest_Assignment<int>(5, 10, 10)?"PASSED\n":"FAILED\n");
		cout << "Testing Assignment(ADVANCED):";
		cout << (Array2DTest_Assignment<string>(string("test"), 10, 10)?"PASSED\n":"FAILED\n");
		
		cout << "Testing Assigning from a const(BASIC):";
		cout << (Array2DTest_AssignFromConst<int>(5)?"PASSED\n":"FAILED\n");
		cout << "Testing Assigning from a const(ADVANCED):";
		cout << (Array2DTest_AssignFromConst<string>(string("test"))?"PASSED\n":"FAILED\n");

		cout << "Testing Copy Constructor(BASIC):";
		cout << (Array2DTest_CopyConstructor<int>(Array2D<int>(6,2))?"PASSED\n":"FAILED\n");
		cout << "Testing Copy Constructor(ADVANCED):";
		cout << (Array2DTest_CopyConstructor<string>(Array2D<string>(12,62))?"PASSED\n":"FAILED\n");

		cout << "Testing Out of Bounds, Row(BASIC):";
		cout << (Array2DTest_OutofBoundsAssignmentRow<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Out of Bounds, Row(ADVANCED):";
		cout << (Array2DTest_OutofBoundsAssignmentRow<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Out of Bounds, Column(BASIC):";
		cout << (Array2DTest_OutofBoundsAssignmentColumn<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Out of Bounds, Column(ADVANCED):";
		cout << (Array2DTest_OutofBoundsAssignmentColumn<string>()?"PASSED\n":"FAILED\n");

		cout << "Testing Self Assignment(BASIC):";
		cout << (Array2DTest_SelfAssignment<int>()?"PASSED\n":"FAILED\n");
		cout << "Testing Self Assignment(ADVANCED):";
		cout << (Array2DTest_SelfAssignment<string>()?"PASSED\n":"FAILED\n");

	}
	std::cin.ignore();
	MEMDUMP
}

