#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
using std::ostream;
class Exception
{
	char * m_msg;
public:
	Exception();
	Exception(char * const msg);
	Exception(Exception & e);
	~Exception();
	Exception & operator=(Exception& rhs);
	char * const getMessage() const;
	void setMessage(char* const msg);
	char* const what() const;
};
	ostream & operator<<(ostream & stream, Exception & except);

#endif
