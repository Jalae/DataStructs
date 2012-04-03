
#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
	char * m_msg;
public:
	Exception();
	Exception(char * const msg);
	Exception(Exception & e);
	~Exception();
	Exception & operator=(Exception& const rhs);
	static char * const getMessage();
	void setMessage(char* const msg);
	ostream& operator<<(ostream& stream, Exception& const except);
	static char* const what();
}
