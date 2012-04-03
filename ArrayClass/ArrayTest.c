

#include "Array.h"
#include <iostream.h>

using namespace std::cout;

void main()
{
	cout << "Creating Array with default\n";
	Array a;
	cout << "Try to access an element, expect exception:";
	try
	{
		a[0];
	}
	catch(Exception e)
	{
		cout << e.what();
	}
	cout << "Increase the length to 5\n";
	a.setLength(5);
	cout << "Access all values, expect 0 0 0 0 0 \n";
	for(size_t i(0); i < a.getLength(); i++)
	{
		cout << a[i] << " ";
	}
	cout << "Assign 1 2 3 4 5 to a\n";
	for(size_t i(0); i < a.getLength(); i++)
	{
		a[i] = i + 1;
	}

	cout << "Change base to -10, access via -10 -> -5:\n";
	a.setStartIndex(-10);
	for(int i(-10); i < (-10 + a.getLength()); i++)
	{
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	
	cout << "Construct b with length of 10, and base 2\n";
	Array b(10,2);
	cout << "Set to 2 3 4 5 6 7 8 9 10 11\n";
	for(int i(2); i < (b.getLength() + 2) ; i++)
	{
		b[i] = i;
		cout << "b[" << i << "]:" << b[i] << "\n";
	}
	cout << "Construct c by coping b\n";
	Array c(b);
	for (int i(c.getStartIndex()); i < (c.getLength()+c.getStartIndex()); i++)
	{
		cout << "c[" << i << "]:" << c[i] << "\n";
	}

	cout << "Lower the size of c\n";
	c.setLength(c.getLength()-5);
	for (int i(c.getStartIndex()); i < (c.getLength()+c.getStartIndex()); i++)
	{
		cout << "c[" << i << "]:" << c[i] << "\n";
	}

	cout << "Out of Bounds Assignment\n";
	try{c.[c.getStartIndex()+c.getLength()+5] = 5;}
	catch(Exception e){cout << e.what();}
	

}

