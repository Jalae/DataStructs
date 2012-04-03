
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
using std::ostream;
class Exception
{
	char * m_msg;
public:
	Exception(){}
	Exception(char * const msg){}
	Exception(Exception & e){}
	~Exception(){}
	Exception & operator=(Exception& rhs){}
	static char * const getMessage(){}
	void setMessage(char* const msg){}
	static char* const what(){}
};
	ostream & operator<<(ostream & stream, Exception & except){}

#endif
