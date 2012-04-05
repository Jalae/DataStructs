#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif





#include "k_string.h"


size_t k_strlen(char* str)
{
	size_t i(0);
	for(i; str[i] != 0; i++); 
	return i;
}

void k_strcpy(char* src, char* & des)
{
	if(src==des)
		return;
	size_t len = k_strlen(src);
	if(des)
		delete[] des;
	des = new char[len+1];
	for(size_t i(0); i < (len + 1); i++)
	{
		des[i] = src[i];
	}
}


bool k_strcmp(char* src, char* des)
{
	size_t i(0);
	while(src[i]==des[i] && src[i])
		i++;
	return src[i]==des[i];
}