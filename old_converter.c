/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <stdio.h>
//Implementation from stack overflow
int fast_atoi( const char * str )
{
	    int val = 0;
	        while( *str ) {
			        val = val*10 + (*str++ - '0');
				    }
		    return val;
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
	for (unsigned i = 0; i<nlines; i++)
	{
		nums[i]=fast_atoi(lines[i]);
	}
}
