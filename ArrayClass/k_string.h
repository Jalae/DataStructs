#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif


#ifndef K_STRING_
#define K_STRING_
#include <iostream>

size_t k_strlen(char* str);

void k_strcpy(char* src, char* & des);

bool k_strcmp(char* src, char* des);

#endif